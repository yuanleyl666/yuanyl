#include"Shop.h"
using namespace cocos2d;


Shop::Shop(Player* player)
{
    this->whoOpenThis = player;

    for (int i = 0; i < 5; i++)
    {
        int rate = random() % 100;
        //具体某种棋子
        if (rate < 1)
        {
            ChessLibrary[i].setChessType(ChessWithSprite::ChessType::firstType);
            ChessLibrary[i].init();
        }
    }

    player->setShop(this);
    //设置ui和按钮
    //创建商店的大外框
    this->setSprite(Sprite::create("图片名"));
    //在商店中分别放置精灵；
    for (int i = 0; i < 5; i++)
    {
        //设置棋子精灵
        auto chessSprite = this->ChessLibrary[0].getSprite();
        //把chessSprite显示上去
        chessSprite->setPosition(Vec2(i * 100, 200));

        //设置按钮，不一定非要是精灵，可以是其他类，只要能调用购买就行
        //显示、设置点击事件，点击调用this-》buychess（i）
         //创建button对象
        auto buyButton = Sprite::create("res\\shop\\BH_SHOP.png");

        //设置btn的位置
        buyButton->setPosition(Vec2(300, 200));

        this->getPlayer()->getPlayerBoard()->getBoardScene()->addChild(buyButton, 1);
        auto listener1 = EventListenerTouchOneByOne::create();
        listener1->setSwallowTouches(true);//设置事件吞没，避免了下游的其它监听器获取到此事件
        // trigger when you push down
        listener1->onTouchBegan = [=](Touch* touch, Event* event) {
            auto target = static_cast<Sprite*>(event->getCurrentTarget());

            Point pos = Director::getInstance()->convertToGL(touch->getLocationInView());

            /* 判断点击的坐标是否在精灵的范围内 */
            if (target->getBoundingBox().containsPoint(pos))
            {
                /* 设置精灵的透明度为100 */
                target->setOpacity(0);
                return true;
            }

            return false;
        };
        // trigger when you let up
        listener1->onTouchEnded = [](Touch* touch, Event* event) {
            // your code
            CCLOG("进入ended");
        };
        /* 注册监听事件，绑定精灵1 */
        this->getPlayer()->getPlayerBoard()->getBoardScene()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1, buyButton);

        //
        this->getSprite()->addChild(buyButton, 0, i + 5);



    }
    //设置关闭按钮
    auto closeButton = Sprite::create("关闭");
    this->getSprite()->addChild(closeButton, 0, -1);
    //设置事件，点击调用closeShop（）

}

void Shop::setSprite(Sprite* toSet)
{
    this->shopSprite = toSet;
}
bool Shop::buyChess(const int rank)
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

            this->whoOpenThis->setGold(this->whoOpenThis->getGold() - this->ChessLibrary[rank].getPrice());
            this->ChessLibrary[rank].changeChessToOtherChess(this->whoOpenThis->getReserve(i));
            //ui

            //
            break;
        }
    }
    if (reseverIsFull)
        return 0;
    //扣除玩家金币

    return 1;
}
void Shop::closeShop()
{
    this->whoOpenThis->getSprite()->removeAllChildren();
    this->whoOpenThis->setShop(nullptr);
    this->whoOpenThis = nullptr;
    //ui关闭商店界面
    //
    delete this;
}


Player* Shop::getPlayer()
{
    return this->whoOpenThis;
}
void Shop::setPlayer(Player* toSet)
{
    this->whoOpenThis = toSet;
}
