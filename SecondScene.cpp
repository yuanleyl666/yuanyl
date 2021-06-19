#include"SecondScene.h"
#include"FirstScene.h"
#include "FightBoard.h"
#include<iostream>
#include "cocos-ext.h"
#include "ui/UIScale9Sprite.h"
#include "ui/CocosGUI.h"
using namespace cocos2d::ui;
using namespace std;
using namespace cocos2d::extension;
USING_NS_CC;
USING_NS_CC_EXT;

//Sprite* targetA;
//Point pos, posA;
//int x, y;

Scene* MySecondScene::createScene()
{
    auto scene = Scene::create();
	auto layer = MySecondScene::create();
	scene->addChild(layer);
	return scene;
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in myMenuScene.cpp\n");
}

//bool MySecondScene::init()
//{
//	
//	/*Size VisibleSize = Director::getInstance()->getVisibleSize();
//
//	auto label = Label::createWithSystemFont("Hello,This is MySecondScene", "fonts/arial.ttf", 30);
//	auto menuitem = MenuItemLabel::create(label, CC_CALLBACK_1(MySecondScene::EnterFirstScene, this));
//	auto menu = Menu::create(menuitem, NULL);
//	this->addChild(menu);*/
//    //////////////////////////////
//  // 1. super init first
//    if (!MySecondScene::init())
//    {
//        return false;
//    }
//
//    auto visibleSize = Director::getInstance()->getVisibleSize();
//    Vec2 origin = Director::getInstance()->getVisibleOrigin();
//
//    //background
//    auto sprite = Sprite::create("res\\map3.png");
//    if (sprite == nullptr)
//    {
//        problemLoading("'res\\map.png'");
//    }
//    else
//    {
//        // position the sprite on the center of the screen
//        sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
//
//        // add the sprite as a child to this layer
//        this->addChild(sprite, 0);
//    }
//
//    
//    /* repeat for as many menu items as needed */
//
//
//    auto spriteA = Sprite::create("res\\model\\CG.png");
//    spriteA->setScale(2);
//    spriteA->setPosition(177, 100);//设置这个精灵在屏幕的位置
//    this->addChild(spriteA);//把这个精灵添加到当前层中。
//
//    auto listener1 = EventListenerTouchOneByOne::create();
//    listener1->setSwallowTouches(true);
//
//    listener1->onTouchBegan = [](Touch* touch, Event* event) {
//        auto target = static_cast<Sprite*>(event->getCurrentTarget());
//        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
//        Size s = target->getContentSize();
//        Rect rect = Rect(0, 0, s.width, s.height);
//
//        if (rect.containsPoint(locationInNode))
//        {
//            //log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
//
//            target->setOpacity(160);
//            return true;
//        }
//        return false;
//    };
//    listener1->onTouchMoved = [](Touch* touch, Event* event) {
//        auto target = static_cast<Sprite*>(event->getCurrentTarget());
//        target->setPosition(target->getPosition() + touch->getDelta());
//        //pos = touch->getLocation() + touch->getDelta();
//
//    };
//    listener1->onTouchEnded = [=](Touch* touch, Event* event) {
//        auto target = static_cast<Sprite*>(event->getCurrentTarget());
//        pos = touch->getLocation() + touch->getDelta();
//        if (pos.y < 92.0) {
//            posA.x = max(172, min(300, 172 + (int)(pos.x - 164) / 16 * 16));
//            posA.y = 76;
//        }
//        else {
//            posA.x = max(177, min(289, 177 + (int)(pos.x - 169) / 16 * 16));
//            posA.y = max(100, min(148, 100 + (int)(pos.y - 92) / 16 * 16));
//            int x, y;
//            x = (posA.x - 177) / 16;
//            y = (posA.y - 100) / 16;
//        }
//        //log("posA x = %f, y = %f", posA.x, posA.y);
//        //log("pos x = %f, y = %f", pos.x, pos.y);
//        target->setPosition(posA.x, posA.y);
//        target->setOpacity(255);
//        /*auto spriteB = Sprite::create("res\\atk.png");
//        spriteB->setScale(0.1);
//        spriteB->setPosition(posA.x + 8, posA.y + 8);
//        spriteB->setRotation(-70.0f);
//        this->addChild(spriteB);
//        CCLOG("11111111111");
//        auto rotateTo = RotateBy::create(2.0f, -30.0f);
//        auto seq = Sequence::create(rotateTo, rotateTo->reverse(), nullptr);
//        spriteB->runAction(seq);*/
//    };
//
//    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, spriteA);
//    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(), spriteA);
//    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(), spriteA);
//
//    return true;
//	return true;
//}

bool MySecondScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    PlayerBoard* b1 = new PlayerBoard;
    PlayerBoard* b2 = new PlayerBoard;

    Player* p1 = new Player;
    Player* p2 = new Player;

    p1->setPlayerBoard(b1);
    b1->setPlayer(p1);

    //create the scene of p1
    p1->setSecondScene(this);

    //create the sprite of b1
    auto sprite1 = Sprite::create("res\\map\\map.png");

    //set the sprite of b1
    b1->setMap(sprite1);

    //add the sprite of b1 scene
    b1->setBoardScene(this);

    this->setBoard(b1);
  
    //this->addChild(b1->getMap());
 
    if (sprite1 == nullptr)
    {
        problemLoading("'res\\map\\map.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        //sprite1->setAnchorPoint(Vec2(0,0));
        //sprite1->setScaleX(1.7);
        sprite1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

        // add the sprite as a child to this layer
    }
    this->addChild(sprite1);





    //create the playerSprite
    auto spritetrans = Sprite::create("res\\atk.png");
    spritetrans->setPosition(Vec2(100, 100));
    //spritetrans->setOpacity(0);

    //set player Sprite
    p1->setSprite(spritetrans);

    this->addChild(p1->getSprite());
    
    //add chessReverse into Player
    for (int i = 0; i < 5; i++)
    {
        if (p1->getReserve(i)->getSprite() != nullptr)
        this->addChild(p1->getReserve(i)->getSprite());
        //p1->getSprite()->addChild(p1->getReserve(i)->getSprite());
    }
    
    this->setPlayer(p1);  

    p1->setHp(100);
    p2->setHp(100);
    p1->setExp(0);
    p2->setExp(0);
    p1->setGold(1000);
    p2->setGold(10);
    p1->setPlayerRank(1);
    p2->setPlayerRank(2);
    p1->setLevel(1);
    p2->setLevel(1);

    p2->setPlayerBoard(b2);
    b2->setPlayer(p2);

    ChessWithSprite* C = new  ChessWithSprite(ChessWithSprite::ChessType::Axe);
    b1->setChess(6, 6, C);

    b1->getChess(6, 6)->getSprite()->setScale(2);

    p1->openShop();
    

    
   // FightBoard fb;
  //  fb.init(p1, p2);
  //  fb.getBoardScene();
  

	return true;
}


void MySecondScene::EnterFirstScene(Ref* pSender)
{
	//跳转到第一个场景，记得包含第一个场景的头文件：MyFirstScene.h
	Director::getInstance()->replaceScene(MyFirstScene::createScene());
}
void MySecondScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}

//myadd
void MySecondScene::moveChess()
{
    auto listener1 = EventListenerTouchOneByOne::create();
    listener1->setSwallowTouches(true);

    listener1->onTouchBegan = [this](Touch* touch, Event* event) {
        targetA = static_cast<Sprite*>(event->getCurrentTarget());
        pos_org = targetA->getPosition();
        if (pos_org.x < 92.0) {
            x_org = (pos_org.x - 172) / 16;
            y_org = 0;
        }
        else {
            x_org = (pos_org.x - 177) / 16;
            y_org = (pos_org.y - 100) / 16;
        }
        Point locationInNode = targetA->convertToNodeSpace(touch->getLocation());
        Size s = targetA->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);

        if (rect.containsPoint(locationInNode))
        {
            //log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            targetA->setOpacity(160);
            return true;
        }
        return false;
    };
    listener1->onTouchMoved = [this](Touch* touch, Event* event) {
        targetA = static_cast<Sprite*>(event->getCurrentTarget());
        targetA->setPosition(targetA->getPosition() + touch->getDelta());
        //pos = touch->getLocation() + touch->getDelta();

    };
    listener1->onTouchEnded = [=](Touch* touch, Event* event) {
        targetA = static_cast<Sprite*>(event->getCurrentTarget());
        pos = touch->getLocation() + touch->getDelta();
        if (pos.y < 92.0) {
            posA.x = max(172, min(300, 172 + (int)(pos.x - 164) / 16 * 16));
            posA.y = 76;
            x = (posA.x - 172) / 16;
            y = 0;
        }
        else {
            posA.x = max(177, min(289, 177 + (int)(pos.x - 169) / 16 * 16));
            posA.y = max(100, min(148, 100 + (int)(pos.y - 92) / 16 * 16));
            //int x, y;
            x = (posA.x - 177) / 16;
            y = (posA.y - 100) / 16;
            
        }        
        //棋子移动与重叠回退
        if (y_org == 0 && y == 0) {
            if (this->getPlayer()->getReserve(x)->getChessType() == ChessWithSprite::ChessType::noChess) {
                targetA->setPosition(posA);
                this->getPlayer()->getReserve(x_org)->changeChessToOtherChess(this->getPlayer()->getReserve(x));
            }
            else {
                targetA->setPosition(pos_org);
            }
        }
        else if (y_org != 0 && y == 0) {
            if (this->getPlayer()->getReserve(x)->getChessType() == ChessWithSprite::ChessType::noChess) {
                targetA->setPosition(posA);               
                this->getPlayer()->getPlayerBoard()->getChess(x_org, y_org)
                    ->changeChessToOtherChess(this->getPlayer()->getReserve(x));
            }
            else {
                targetA->setPosition(pos_org);
            }
        }
        else if (y_org == 0 && y != 0) {
            if (this->getBoard()->getChess(x, y)
                ->getChessType() == ChessWithSprite::ChessType::noChess) {
                targetA->setPosition(posA);
                this->getPlayer()->getReserve(x_org)->changeChessToOtherChess
                (this->getPlayer()->getPlayerBoard()->getChess(x, y));
            }
            else {
                targetA->setPosition(pos_org);
            }
        }
        else {
            if (this->getPlayer()->getPlayerBoard()->getChess(x, y)
                ->getChessType() == ChessWithSprite::ChessType::noChess) {
                targetA->setPosition(posA);
                this->getPlayer()->getPlayerBoard()->getChess(x_org, y_org)->changeChessToOtherChess
                (this->getPlayer()->getPlayerBoard()->getChess(x, y));
            }
            else {
                targetA->setPosition(pos_org);
            }
        }

        targetA->setOpacity(255);       
    };

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this);
    //_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(), targetA);
    //_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(), targetA);
}

Player* MySecondScene::getPlayer()
{
    return this->player;
}

void MySecondScene::setPlayer(Player* toSet)
{
    this->player = toSet;
}

PlayerBoard* MySecondScene::getBoard()
{
    return this->board;
}

void MySecondScene::setBoard(PlayerBoard* toSet)
{
    this->board = toSet;
}

//MySecondScene* MySecondScene::getScene()
//{
//    return this->scene;
//}
//
//void MySecondScene::setScene(MySecondScene* toSet)
//{
//    this->scene = toSet;
//}
