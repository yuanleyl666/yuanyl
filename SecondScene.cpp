#include"SecondScene.h"
#include"FirstScene.h"
#include<iostream>
#include "cocos-ext.h"
#include "ui/UIScale9Sprite.h"
#include "ui/CocosGUI.h"
using namespace cocos2d::ui;
using namespace std;
using namespace cocos2d::extension;
USING_NS_CC;
USING_NS_CC_EXT;

Point pos, posA;

Scene* MySecondScene::createScene()
{
	Scene* scene = Scene::create();
	MySecondScene* layer = MySecondScene::create();
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
	  // 1. super init first
    /*if (!MySecondScene::init())
    {
        return false;
    }*/
    //Size VisibleSize = Director::getInstance()->getVisibleSize();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //background
    auto sprite = Sprite::create("res\\map\\map.png");
    if (sprite == nullptr)
    {
        problemLoading("'res\\map.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }
    auto spriteA = Sprite::create("res\\model\\CG.png");
    spriteA->setScale(2);
    spriteA->setPosition(177, 100);//设置这个精灵在屏幕的位置
    this->addChild(spriteA);//把这个精灵添加到当前层中。

    auto listener1 = EventListenerTouchOneByOne::create();
    listener1->setSwallowTouches(true);

    listener1->onTouchBegan = [](Touch* touch, Event* event) {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);

        if (rect.containsPoint(locationInNode))
        {
            //log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setOpacity(160);
            return true;
        }
        return false;
    };
    listener1->onTouchMoved = [](Touch* touch, Event* event) {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setPosition(target->getPosition() + touch->getDelta());
        //pos = touch->getLocation() + touch->getDelta();

    };
    listener1->onTouchEnded = [=](Touch* touch, Event* event) {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        pos = touch->getLocation() + touch->getDelta();
        if (pos.y < 92.0) {
            posA.x = max(172, min(300, 172 + (int)(pos.x - 164) / 16 * 16));
            posA.y = 76;
        }
        else {
            posA.x = max(177, min(289, 177 + (int)(pos.x - 169) / 16 * 16));
            posA.y = max(100, min(148, 100 + (int)(pos.y - 92) / 16 * 16));
            int x, y;
            x = (posA.x - 177) / 16;
            y = (posA.y - 100) / 16;
        }   
        target->setPosition(posA.x, posA.y);
        target->setOpacity(255);
    };

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, spriteA);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(), spriteA);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(), spriteA);

    Director::getInstance()->pause();
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