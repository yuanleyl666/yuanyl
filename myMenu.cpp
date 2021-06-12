#include<iostream>
#include "myMenu.h"
//#include "ChessBoard.h"
#include "cocos-ext.h"
#include "ui/UIScale9Sprite.h"
#include "ui/CocosGUI.h"
#include "cocostudio/SimpleAudioEngine.h"
using namespace CocosDenshion;
using namespace cocos2d::ui;
using namespace std;
using namespace cocos2d::extension;
USING_NS_CC;
USING_NS_CC_EXT;
bool if_buy = false;
Point p1, p2;
Scene* myMenu::createScene()
{
    return myMenu::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in myMenuScene.cpp\n");
}

//void myMenu::shopTouch(Ref* pSender, cocos2d::ui::Widget::TouchEventType type)
//{
//    auto BH = Sprite::create("res\\model\\BH.png");
//    switch (type)
//    {
//        case cocos2d::ui::Widget::TouchEventType::BEGAN:
//            BH->setPosition(Vec2(169.0f, 74.5f));
//            BH->setScale(2.0f);
//            BH->addChild(BH, 1);
//            break;
//        case cocos2d::ui::Widget::TouchEventType::ENDED:
//            return;
//    }
//    return ;
//}

// on "init" you need to initialize your instance
bool myMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }
    auto audio = SimpleAudioEngine::getInstance();

    // set the background music and continuously play it.
    audio->playBackgroundMusic("res\\music_background.mp3", true);

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


//background
    auto sprite = Sprite::create("res\\map.png");
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


   
    //创建button对象
    auto shop = Sprite::create("res\\shop\\BH_SHOP.png");

    //设置btn的位置
    shop->setPosition(Vec2(visibleSize.width - 300, 200));
    p1 = shop->getPosition();
    auto listener1 = EventListenerTouchOneByOne::create();

    // trigger when you push down
    listener1->onTouchBegan = [shop](Touch* touch, Event* event) {
        // your code
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        p2 = target->getPosition();
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        CCLOG("%f %f", p1.x, p1.y);
        CCLOG("%f %f", p2.x, p2.y);
        if (rect.containsPoint(locationInNode))
        {
            target->setOpacity(0);
            shop->setOpacity(180);
            if_buy = true;
        }
        return false; // if you are consuming it
    };
    CCLOG("%d", if_buy);
    if (if_buy)
    {
        auto BH = Sprite::create("res\\model\\BH.png");
        BH->setPosition(Vec2(169.0f, 74.5f));
        BH->setScale(2.0f);
        BH->addChild(BH, 1);
    }
    // Add listener
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this);
    this->addChild(shop, 1);

    
    return true;
}


void myMenu::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();
}
