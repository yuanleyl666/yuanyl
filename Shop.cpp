#include"Shop.h"
using namespace cocos2d;


Shop::Shop(Player* player)
{
    this->whoOpenThis = player;
    this->setSprite(Sprite::create("res\\shop.png"));
    this->getSprite()->setPosition(100, 50);
    player->setShop(this);
    player->getSprite()->addChild(this->getSprite());


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
        ChessLibrary[i].setChessType(ChessWithSprite::ChessType::Axe);
        ChessLibrary[i].init();
    }
 
    //设置ui和按钮
    //创建商店的大外框
    
    //在商店中分别放置精灵；
    for (int i = 0; i < 5; i++)
    {
        Sprite* chessSprite = nullptr;
        //设置棋子精灵
        if (this->ChessLibrary[i].getSprite()->getChildrenCount())
        {
            chessSprite = static_cast<Sprite * >(this->ChessLibrary[i].getSprite()->getChildByTag(0));
        }
        else
        {
            chessSprite = this->ChessLibrary[i].getSprite();
        }
        //把chessSprite显示上去
        chessSprite->setPosition(Vec2(i * 100, 200));

        //设置按钮，不一定非要是精灵，可以是其他类，只要能调用购买就行
        //显示、设置点击事件，点击调用this-》buychess（i）
         //创建button对象
        auto buyButton = Sprite::create("res\\shop\\BH_SHOP.png");

        //设置btn的位置
        buyButton->setPosition(Vec2(300, 200));

        this->getSprite()->addChild(buyButton, 1);
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
    this->getSprite()->addChild(closeButton);
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
            //扣除玩家金币
            this->whoOpenThis->setGold(this->whoOpenThis->getGold() - this->ChessLibrary[rank].getPrice());

            //ui        不一定需要
            //
            //


            this->ChessLibrary[rank].changeChessToOtherChess(this->whoOpenThis->getReserve(i));
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

void shopUpDate(Shop* shop)
{
    auto player = shop->getPlayer();
    shop->closeShop();
    CC_SAFE_DELETE(shop);
    Shop* _shop = new Shop(player);
    player->getSprite()->addChild(shop->getSprite(), 0, 1);
}

Sprite* Shop::getSprite()
{
    return this->shopSprite;
}
