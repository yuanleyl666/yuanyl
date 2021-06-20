#include"Shop.h"
using namespace cocos2d;


Shop::Shop(Player* player)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();

    Vec2 origin = Director::getInstance()->getVisibleOrigin();



    this->whoOpenThis = player;
    player->setShop(this);

    this->setSprite(Sprite::create("res\\shopboard.png"));
    this->getSprite()->setScale(1);
    this->getSprite()->setPosition(Vec2(240, 40));
    player->getSecondScene()->addChild(this->getSprite());


    static int pool[21] = { 0,20,20,20,20,20,20,20,20,20,15,15,15,15,15,15,10,10,10,10,10 };//默认卡池参数

    for (int i = 0; i < 5; i++)
    {
        int draw;//抽取到的棋子（标号）
        int rate = 1 + rand() % 100;
        const int Rate[4][10] = { {100,70 ,60, 50, 40, 30, 25, 20,15,10},//各等级抽取棋子概率
                                  {100,100,90, 80, 70, 65, 55, 50,35,25},
                                  {100,100,100,95, 90, 85, 80, 80,60,50},
                                  {100,100,100,100,100,95, 90, 85,80,75} };
        if (rate <= Rate[0][whoOpenThis->getLevel() - 1])
        {
            draw = 1 + rand() % 5;
        }
        else if (rate <= Rate[1][whoOpenThis->getLevel() - 1])
        {
            draw = 6 + rand() % 4;
        }
        else if (rate <= Rate[2][whoOpenThis->getLevel() - 1])
        {
            draw = 10 + rand() % 3;
        }
        else if (rate <= Rate[3][whoOpenThis->getLevel() - 1])
        {
            draw = 13 + rand() % 3;
        }
        else
        {
            draw = 16 + rand() & 5;
        }
        pool[draw]--;//卡池数减一
        ChessLibrary[i].setChessType(static_cast<ChessWithSprite::ChessType>(draw));
        ChessLibrary[i].initInShop(1);
    }

    //设置ui和按钮
    //创建商店的大外框

    //在商店中分别放置精灵；
    for (int i = 0; i < 5; i++)
    {
        //Sprite* chessSprite = nullptr;
        //设置棋子精灵
        auto chessSprite = this->ChessLibrary[i].getSprite();
        chessSprite->setOpacity(255);
        //把chessSprite显示上去
        chessSprite->setScale(0.62);
        chessSprite->setPosition(Vec2(i * 47.5 + 170, 35));
        if (chessSprite->getParent() == nullptr)
            this->getPlayer()->getSecondScene()->addChild(chessSprite, 2);
        //设置按钮，不一定非要是精灵，可以是其他类，只要能调用购买就行
        //显示、设置点击事件，点击调用this-》buychess（i）
         //创建button对象
       
        auto listener1 = EventListenerTouchOneByOne::create();
        listener1->setSwallowTouches(true);//设置事件吞没，避免了下游的其它监听器获取到此事件
        // trigger when you push down
        listener1->onTouchBegan = [=](Touch* touch, Event* event) {
            auto target = static_cast<Sprite*>(event->getCurrentTarget());
            int num = -1;
            Point pos = Director::getInstance()->convertToGL(touch->getLocationInView());
            Point pppp = Point(pos.x, pos.y - 57.0);
            /* 判断点击的坐标是否在精灵的范围内 */
            if (pos.y > 75 && pos.y < 107 && pos.x>148 && pos.x < 382) {
                if (pos.x > 148 && pos.x < 192)
                    num = 0;
                else if (pos.x > 195 && pos.x < 239)
                    num = 1;
                else if (pos.x > 242 && pos.x < 286)
                    num = 2;
                else if (pos.x > 290 && pos.x < 334)
                    num = 3;
                else if (pos.x > 338 && pos.x < 382)
                    num = 4;
                else
                    num = -1;
            }
            if (num > -1 && num < 5)
            {
                if (!this->buyChess(num, this->getPlayer()))
                    log("sb");
                else  log("bought");
                return true;
            }
            //if (target->getBoundingBox().containsPoint(pppp))
            //{
            //    /* 设置精灵的透明度为100 */
            //    this->buyChess(i, this->getPlayer());
            //    return true;
            //}

            return false;
        };
        // trigger when you let up
        listener1->onTouchEnded = [](Touch* touch, Event* event) {
            // your code
            CCLOG("进入ended");
        };
        /* 注册监听事件，绑定精灵1 */
        this->getPlayer()->getSecondScene()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1, this->getSprite());

        //
        //this->getSprite()->addChild(buyButton, 0, i + 5);



    }
    //设置关闭按钮
    auto updateBtn = Sprite::create("res\\freshen.png");
    //this->getSprite()->addChild(updateBtn);
    updateBtn->setPosition(120, 25);
    auto listener1 = EventListenerTouchOneByOne::create();
    listener1->setSwallowTouches(true);//设置事件吞没，避免了下游的其它监听器获取到此事件
    // trigger when you push down
    listener1->onTouchBegan = [=](Touch* touch, Event* event) {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());

        Point pos = Director::getInstance()->convertToGL(touch->getLocationInView());
        Point pppp = Point(pos.x, pos.y - 57.0);
        /* 判断点击的坐标是否在精灵的范围内 */
        if (target->getBoundingBox().containsPoint(pppp))
        {
            /* 设置精灵的透明度为100 */
            shopUpDate(this,pool);
            return true;
        }

        return false;
    };
    listener1->onTouchEnded = [](Touch* touch, Event* event) {
        // your code
        CCLOG("进入ended");
    };
    /* 注册监听事件，绑定精灵1 */
    this->getPlayer()->getSecondScene()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1, updateBtn);
    this->getPlayer()->getSecondScene()->addChild(updateBtn, 3);
    //设置事件，点击调用closeShop（）

}

void Shop::setSprite(Sprite* toSet)
{
    this->shopSprite = toSet;
}
bool Shop::buyChess(const int rank,Player* player)
{

    if (rank < 0 || rank>4)
        return 0;
    if (this->whoOpenThis->getGold() < this->ChessLibrary[rank].getPrice())
        return 0;
    bool reseverIsFull = 1;
    for (int i = 0; i < 5; i++)
    {
        if (this->whoOpenThis->getReserve(i)->getChessType() == ChessWithSprite::ChessType::noChess)
        {

            reseverIsFull = 0;
            //扣除玩家金币
            this->whoOpenThis->setGold(this->whoOpenThis->getGold() - this->ChessLibrary[rank].getPrice());

            //ui        不一定需要
            //
            //


            this->whoOpenThis->setReserve(i, &this->ChessLibrary[rank]);
            break;
        }
    }
    if (reseverIsFull)
        return 0;

    return 1;
}
void Shop::closeShop()
{
    this->whoOpenThis->getSprite()->removeAllChildren();
    this->whoOpenThis->setShop(nullptr);
    this->whoOpenThis = nullptr;
    //ui关闭商店界面

}


Player* Shop::getPlayer()
{
    return this->whoOpenThis;
}
void Shop::setPlayer(Player* toSet)
{
    this->whoOpenThis = toSet;
}

void shopUpDate(Shop* shop, int pool[21])
{
    for (int i = 0; i < 5; i++)
    {
        int draw;//抽取到的棋子（标号）
        int rate = 1 + rand() % 100;
        const int Rate[4][10] = { {100,70 ,60, 50, 40, 30, 25, 20,15,10},//各等级抽取棋子概率
                                  {100,100,90, 80, 70, 65, 55, 50,35,25},
                                  {100,100,100,95, 90, 85, 80, 80,60,50},
                                  {100,100,100,100,100,95, 90, 85,80,75} };
        if (rate <= Rate[0][shop->whoOpenThis->getLevel() - 1])
        {
            draw = 1 + rand() % 5;
        }
        else if (rate <= Rate[1][shop->whoOpenThis->getLevel() - 1])
        {
            draw = 6 + rand() % 4;
        }
        else if (rate <= Rate[2][shop->whoOpenThis->getLevel() - 1])
        {
            draw = 10 + rand() % 3;
        }
        else if (rate <= Rate[3][shop->whoOpenThis->getLevel() - 1])
        {
            draw = 13 + rand() % 3;
        }
        else
        {
            draw = 16 + rand() & 5;
        }
        pool[draw]--;//卡池数减一

        shop->ChessLibrary[i].setChessType(static_cast<ChessWithSprite::ChessType>(draw));
        shop->ChessLibrary[i].initInShop();
    }
}

Sprite* Shop::getSprite()
{
    return this->shopSprite;
}

//if (1)
//{
//    round = 1;
//    player toFight;
//    playerBoard;
//    for (int i = 0; i < vec[1].size(); i++)
//        playerBoard.setChess(vec[1])
//}
