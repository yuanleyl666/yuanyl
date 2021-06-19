#include"FightBoard.h"
using namespace cocos2d;

void FightBoard::attack(const int xInit, const int yInit, const int xAim, const int yAim)
{
    chess[yInit][xInit].attack(&chess[xAim][yAim]);
    //攻击动画（上侧）
    auto spriteA = Sprite::create("/res/atk.png");
    spriteA->setScale(0.1);
    spriteA->setPosition(100, 100);
    spriteA->setRotation(-70.0f);
    //this->getSprite()->getParent()代表场景的this指针
    this->chess[yInit][xInit].getSprite()->getParent()->addChild(spriteA);
    auto rotateToA = RotateBy::create(0.6f, -30.0f);
    auto seqA = Sequence::create(rotateToA, rotateToA->reverse(), nullptr);
    //攻击动画（下侧）
    auto spriteB = Sprite::create("/res/atk.png");
    spriteB->setScale(0.1);
    spriteB->setPosition(100, 100);
    spriteB->setRotation(-15.0f);
    //this->getSprite()->getParent()代表场景的this指针
    this->chess[yInit][xInit].getSprite()->getParent()->addChild(spriteB);
    auto rotateToB = RotateBy::create(0.6f, 30.0f);
    auto seqB = Sequence::create(rotateToB, rotateToB->reverse(), nullptr);
    //远程攻击
    auto moveTo = MoveTo::create(4, Vec2(300, 300));
    auto emitter = ParticleFire::create();//火焰
    emitter->setScale(0.15);
    emitter->setPosition(50, 50);
    this->chess[yInit][xInit].getSprite()->getParent()->addChild(spriteB);
    // 技能特效
    auto emitter6 = ParticleExplosion::create();//爆炸
    emitter6->setScale(0.5);
    emitter6->setPosition(50, 50);
    this->chess[yInit][xInit].getSprite()->getParent()->addChild(spriteB);
    //通过chesstype判断攻击类型
    switch (this->chess[yInit][xInit].ChessWithSprite::getChessType())
    {

    case 0:
        break;
    case 1:
        //攻击动画（上侧）
        spriteA->runAction(seqA);
        break;
    case 2:
        //攻击动画（下侧）
        spriteB->runAction(seqB);
        break;
    case 3:
        //远程攻击
        emitter->runAction(moveTo);
        break;
    case 4:
        // 技能特效
        emitter6->runAction(moveTo);
        break;
    }
    if (chess[xAim][yAim].getHP() < 1e-3)
    {
        //加上死亡动画
        chess[xAim][yAim].setChessType(ChessWithSprite::ChessType::noChess);
        chess[xAim][yAim].getSprite()->removeAllChildren();
        chess[xAim][yAim].init();
        //死亡特效
        auto fadeOut = FadeOut::create(1.0f);
        auto spriteD = Sprite::create();
        spriteD->runAction(fadeOut);
    }
}

const positionOnMap FightBoard::findNextMove(const int xInBoard, const int yInBoard)
{
    auto AimPosition = findPossibleAttackAim(xInBoard, yInBoard);

    if (AimPosition == positionOnMap(-1, -1))
        return positionOnMap(xInBoard, yInBoard);

    if (1)
    {
        double EnemyDistance = fabs(yInBoard - AimPosition.y) < fabs(xInBoard - AimPosition.x) ? fabs(xInBoard - AimPosition.x) : fabs(yInBoard - AimPosition.y);
        log("%f", EnemyDistance);
        log("%f", chess[yInBoard][xInBoard].getRA());
        if (EnemyDistance <= chess[yInBoard][xInBoard].getRA())
        {
            return positionOnMap(xInBoard, yInBoard);
        }
    }

    if (1)
    {
        positionOnMap positionToReturn(xInBoard, yInBoard);
        double MinDistanceToEnemy = 110;
        for (int i = -1; i < 2; i++)
            for (int k = -1; k < 2; k++)
            {
                if (xInBoard + k < 0 || xInBoard + k>7 || yInBoard + i < 0 || yInBoard + i>7 || chess[yInBoard + i][xInBoard + k].getChessType() != ChessWithSprite::ChessType::noChess)
                    continue;

                double EnemyDistance = fabs(yInBoard + i - AimPosition.y) < fabs(xInBoard + k - AimPosition.x) ? fabs(xInBoard + k - AimPosition.x) : fabs(yInBoard + i - AimPosition.y);
                if (EnemyDistance < MinDistanceToEnemy)
                {
                    positionToReturn = positionOnMap(xInBoard + k, yInBoard + i);
                    MinDistanceToEnemy = EnemyDistance;
                }
            }
        return positionToReturn;
    }



}

//为某坐标上的棋子寻找最近的敌人的位置
const positionOnMap FightBoard::findPossibleAttackAim(const int xInBoard, const int yInBoard)
{
    positionOnMap toReturn(-1, -1);
    double distance = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int k = 0; k < 8; k++)
        {
            if (this->chess[i][k].getChessType() == ChessWithSprite::ChessType::noChess)
                continue;

            if (this->chess[i][k].getPlayer() != this->chess[yInBoard][xInBoard].getPlayer())
            {
                double dis = fabs(yInBoard - i) < fabs(xInBoard - k) ? fabs(xInBoard - k) : fabs(yInBoard - i);

                if (dis > distance)
                {
                    toReturn.x = k;
                    toReturn.y = i;
                    distance = dis;
                }
            }
        }
    }
    return toReturn;
}
void FightBoard::moveChess(const int xInit, const int yInit, const int xAim, const int yAim)
{
    if (this->chess[yInit][xInit].getChessType() == ChessWithSprite::ChessType::noChess)
        return;
    this->chess[yInit][xInit].changeChessToOtherChess(&this->chess[yAim][xAim]);
    double distance = 16;
    auto operateSprite = this->chess[yAim][xAim].getSprite()->getChildByTag(0);
    operateSprite->setPosition(operateSprite->getPositionX() - (xAim - xInit), operateSprite->getPositionY() - (yAim - yInit));
    // Move a sprite to a specific location over 2 seconds.
    auto moveTo = MoveTo::create(2, Vec2(xAim - xInit, yAim - yInit));
    operateSprite->runAction(moveTo);
}
void FightBoard::act(bool& player_1_lose, bool& player_2_lose)
{

    bool isActed[8][8] = { 0 };
    for (int i = 0; i < 8; i++)
        for (int k = 0; k < 8; k++)
        {
            if (chess[i][k].getChessType() && !isActed[i][k])
            {

                if (chess[i][k].getPlayer() == player1->getPlayerRank())
                    player_1_lose = 0;
                else if (chess[i][k].getPlayer() == player2->getPlayerRank())
                    player_2_lose = 0;

                positionOnMap atkPosition = this->findPossibleAttackAim(k, i);
                positionOnMap movePosition = this->findNextMove(k, i);
                if ((movePosition == positionOnMap(k, i)) == 0)
                {
                    moveChess(k, i, movePosition.x, movePosition.y);
                    log("MOVE");
                    log("%d,%d", movePosition.x, movePosition.y);
                    isActed[movePosition.y][movePosition.x] = 1;
                }
                else
                {
                    chess[i][k].attack(&chess[atkPosition.y][atkPosition.x]);
                    isActed[atkPosition.y][atkPosition.x] = 1;
                    CCLOG("ATK");
                }
            }
        }

}
//
void FightBoard::fight()
{
    if (getFightWinner() == this->player1->getPlayerRank())
    {
        player1->setHp(player1->getHp() - 1);
    }
    if (getFightWinner() == this->player2->getPlayerRank())
    {
        player2->setHp(player2->getHp() - 1);
    }
}

bool FightBoard::init(Player* p1, Player* p2)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    this->boardScene = Scene::create();

    auto MapSprite = Sprite::create("HelloWorld.png");
    MapSprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    boardScene->addChild(MapSprite);

    for (int i = 0; i < 8; i++)
        for (int k = 0; k < 8; k++)
        {
            MapSprite->addChild(chess[i][k].getSprite());
            auto chessSprite = chess[i][k].getSprite();
            chessSprite->setScale(0.12, 0.12);
            auto move = MoveTo::create(0, Vec2(20 + k * 25, 50 + i * 25));
            chessSprite->runAction(move);
        }

    this->player1 = p1;
    this->player2 = p2;
    for (int i = 0; i < 8; i++)
    {
        for (int k = 0; k < 8; k++)
        {
            if (i < 4)
            {
                this->chess[i][k] = *(p1->getPlayerBoard()->getChess(i, k));

            }
            else
            {
                this->chess[i][k] = *(p2->getPlayerBoard()->getChess(7 - i, 7 - k));

            }
        }
    }
    return 1;
}
Scene* FightBoard::getBoardScene()
{
    return this->boardScene;
}
void FightBoard::setBoardScene(Scene* toSet)
{
    this->boardScene = toSet;
}
void FightBoard::Winner(bool player1_lose)
{
    if (player1_lose == 1)
        this->fightWinner = player2->getPlayerRank();
    else
        this->fightWinner = player1->getPlayerRank();
}
int FightBoard::getFightWinner()
{
    return fightWinner;
}
