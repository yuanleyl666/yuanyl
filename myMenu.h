#ifndef __myMenu_SCENE_H__
#define __myMenu_SCENE_H__

#include "cocos2d.h"
//#include "ChessBoard.h"
#include "cocos-ext.h"
#include "ui/CocosGUI.h"
//#include "Mouse.h"

class myMenu : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    //void ClipScene::stopCreate(Object* menuItem);
    // implement the "static create()" method manually
    CREATE_FUNC(myMenu);

    /*void shopTouch(Ref* pSender, cocos2d::ui::Widget::TouchEventType type);*/
};


#endif // __myMenu_SCENE_H__
