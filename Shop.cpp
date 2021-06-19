#include"Shop.h"
using namespace cocos2d;
namespace ChessInitData
{
    const std::string SpriteInMap[31] = { "","res\\model\\Axe.png","res\\model\\CG.png","res\\model\\BH.png","res\\model\\DR.png","res\\model\\CK.png",
                                              "res\\model\\MR.png","res\\model\\QoP.png","res\\model\\Jugg.png","res\\model\\TK.png","res\\model\\DS.png",
                                              "res\\model\\PA.png","res\\model\\TW.png","res\\model\\GG.png","res\\model\\GS.png","res\\model\\DK.png",
                                              "res\\model\\TA.png","res\\model\\DRK.png","res\\model\\GT.png","res\\model\\TH.png","res\\model\\COCO.png",
                                              "res\\model\\M1.png","res\\model\\M2.png","res\\model\\M3.png","res\\model\\M4.png","res\\model\\M5.png",
                                              "res\\model\\M6.png","res\\model\\M7.png","res\\model\\M8.png","res\\model\\M9.png","res\\model\\M10.png" };
    const std::string SpriteInShop[21] = { "","res\\shop\\Axe_SHOP.png","res\\shop\\CG_SHOP.png","res\\shop\\BH_SHOP.png","res\\shop\\DR_SHOP.png","res\\shop\\CK_SHOP.png",
                                             "res\\shop\\MR_SHOP.png","res\\shop\\QoP_SHOP.png","res\\shop\\Jugg_SHOP.png","res\\shop\\TK_SHOP.png","res\\shop\\DS_SHOP.png",
                                             "res\\shop\\PA_SHOP.png","res\\shop\\TW_SHOP.png","res\\shop\\GG_SHOP.png","res\\shop\\GS_SHOP.png","res\\shop\\DK_SHOP.png",
                                             "res\\shop\\TA_SHOP.png","res\\shop\\DRK_SHOP.png","res\\shop\\GT_SHOP.png","res\\shop\\TH_SHOP.png","res\\shop\\COCO_SHOP.png" };
}

Shop::Shop(Player* player)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();

    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    


    this->whoOpenThis = player;
    player->setShop(this);


    this->setSprite(Sprite::create("res\\shop.png"));
    //this->getSprite()->setIgnoreAnchorPointForPosition(1);
    //this->getSprite()->setAnchorPoint(Vec2(0,0));
    //this->getPlayer()->getSecondScene()->addChild(this->getSprite());
    this->getSprite()->setPosition(Vec2(190, 10));
      
    player->getSprite()->addChild(this->getSprite(),1);
    
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

        ChessLibrary[i].initInShop(1);
    }
  
    //设置ui和按钮
    //auto shopframe = Sprite::create("res\\shop.png");

    //设置btn的位置
    //shopframe->setPosition(Vec2(300, 0));

    //this->getPlayer()->getPlayerBoard()->getBoardScene()->addChild(shopframe, 1);
    //创建商店的大外框
    //this->setSprite(Sprite::create("res\\shop.png"));
    //在商店中分别放置精灵；
    for (int i = 0; i < 5; i++)
    {
        //设置棋子精灵
        auto chessSprite = this->ChessLibrary[i].getSprite();

        //把chessSprite显示上去
        chessSprite->setOpacity(255);
        //chessSprite->setIgnoreAnchorPointForPosition(1);
        //chessSprite->setAnchorPoint(Vec2(0, 0));
        chessSprite->setScale(0.6);
        chessSprite->setPosition(Vec2(i * 40+160, 40));
       

        this->getPlayer()->getSecondScene()->addChild(chessSprite, 2);

        auto listener1 = EventListenerTouchOneByOne::create();

        listener1->setSwallowTouches(true);//设置事件吞没，避免了下游的其它监听器获取到此事件
        
        // trigger when you push down
        //listener1->onTouchBegan = [&,i](Touch* touch, Event* event) 
        //{
        //    
        //    auto target = static_cast<Sprite*>(event->getCurrentTarget());

        //    Point pp;
        //    pp = target->getPosition();

        //    Point pos = Director::getInstance()->convertToGL(touch->getLocationInView());
        //    log("%d", pp.x);
        //    log("%d", pp.y);
        //    /* 判断点击的坐标是否在精灵的范围内 */
        //    if (target->getBoundingBox().containsPoint(pos))
        //    {
        //       
        //      if(! this->buyChess(i))
        //          log("sb");
        //      else  log("bought");
        //        return true;
        //    }

        //    return false;
        //};
        listener1->onTouchBegan = [i,this](Touch* touch, Event* event) {
            auto targetA = static_cast<Sprite*>(event->getCurrentTarget());
            //pos_org = targetA->getPosition();
           
            Point locationInNode = targetA->getParent()->convertToNodeSpace(touch->getLocation());
            Size s = targetA->getContentSize();
            Rect rect = Rect(0, 0, s.width, s.height);
            log("Node");
            log("%d", locationInNode.x);
            log("%d", locationInNode.y);
            if (rect.containsPoint(locationInNode))
            {
                //log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
                //targetA->setOpacity(160);
                if (!this->buyChess(i))
                    log("sb");
                else
                    log("bought");
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
        this->getPlayer()->getSecondScene()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1, chessSprite );

        //
        //log("%d", chessSprite);
        //this->getSprite()->addChild(buyButton, 0, i + 5);



    }
    //设置关闭按钮
    auto updateButton = Sprite::create("res\\shop.png");
    updateButton->setOpacity(0);
    this->getSprite()->addChild(updateButton, 0, -1);
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
            this->whoOpenThis->setReserve(i, &this->ChessLibrary[rank]);
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

}


Player* Shop::getPlayer()
{
    return this->whoOpenThis;
}
void Shop::setPlayer(Player* toSet)
{
    this->whoOpenThis = toSet;
}

void shopUpDate(Shop* shop,int pool[21])
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
        shop->ChessLibrary[i]=ChessWithSprite(ChessWithSprite::ChessType::Axe);
    }
}

Sprite* Shop::getSprite()
{
    return this->shopSprite;
}
