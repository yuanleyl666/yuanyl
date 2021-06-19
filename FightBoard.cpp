#include"FightBoard.h"
using namespace cocos2d;

void FightBoard::attack(const int xInit, const int yInit, const int xAim, const int yAim)
{
    chess[yInit][xInit].attack(&chess[xAim][yAim]);


    //需要添加攻击精灵的位置


    //攻击动画（上侧）
    auto spriteA = Sprite::create("/res/atk.png");
    spriteA->setScale(0.1);
    spriteA->setPosition(xInit*16.0f, yInit * 16.0f);
    spriteA->setRotation(-70.0f);
    //this->getSprite()->getParent()代表场景的this指针
    this->chess[yInit][xInit].getSprite()->getParent()->addChild(spriteA);
    auto rotateToA = RotateBy::create(0.475f, -30.0f);
    auto fadeOut = FadeOut::create(0.05f);
    auto seqA = Sequence::create(rotateToA, rotateToA->reverse(),fadeOut, nullptr);
    //攻击动画（下侧）
    auto spriteB = Sprite::create("/res/atk.png");
    spriteB->setScale(0.1);
    spriteB->setPosition(xInit * 16.0f, yInit * 16.0f);
    spriteB->setRotation(-15.0f);
    //this->getSprite()->getParent()代表场景的this指针
    this->chess[yInit][xInit].getSprite()->getParent()->addChild(spriteB);
    auto rotateToB = RotateBy::create(0.475f, 30.0f);
    auto seqB = Sequence::create(rotateToB, rotateToB->reverse(),fadeOut, nullptr);
    //远程攻击
    auto moveTo = MoveTo::create(0.95f, Vec2(xAim*16.0f, yAim * 16.0f));
    auto emitter = ParticleFire::create();//火焰
    emitter->setScale(0.15f);
    emitter->setPosition(xInit*16.0f, yInit * 16.0f);
    this->chess[yInit][xInit].getSprite()->getParent()->addChild(emitter);
    auto seqC = Sequence::create(moveTo, fadeOut, nullptr);
    // 技能特效
    auto emitter6 = ParticleExplosion::create();//爆炸
    emitter6->setScale(0.5);
    emitter6->setPosition(xInit * 16.0f, yInit * 16.0f);
    this->chess[yInit][xInit].getSprite()->getParent()->addChild(emitter6);
    auto seqD = Sequence::create(moveTo, fadeOut, nullptr);
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
            emitter->runAction(seqC);
            break;
        case 4:
            // 技能特效
            emitter6->runAction(seqD);
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
