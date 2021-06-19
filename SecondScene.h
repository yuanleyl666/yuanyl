#pragma once
#include"cocos2d.h"

using namespace cocos2d;

class MySecondScene :public Layer
{
public:
	static Scene* createScene();

	CREATE_FUNC(MySecondScene);

	virtual bool init();

	void EnterFirstScene(Ref* pSender);


	void menuCloseCallback(cocos2d::Ref* pSender);
};