#include "FirstScene.h"
#include"SecondScene.h"
#include"ThirdScene.h"

//MyFirstScene场景创建实现
Scene* MyThirdScene::createScene()
{
	auto scene = Scene::create();	//创建一个场景
	auto layer = MyThirdScene::create();//创建一个MyFirstScene层
	scene->addChild(layer);		//把MyFirstScene层加入刚刚创建的场景中，
	return scene;			//返回这个场景
}

bool MyThirdScene::init()
{
	if (!Layer::init())	//先初始化父类的init方法，如何初始化失败，则创建MyFirstScene层失败
	{
		return false;
	}
	
	return true;
}
//菜单回调函数的实现
/*void MyThirdScene::EnterSecondScene(Ref* pSender)
{
	//我们知道，如果需要跳转场景，就会想到一个类，它就是Director类，它就是管理场景的
	//这里跳转场景调用到的是导演类的这个接口：replaceScene(Scene *scene),里面传进去的是就是一个场景，这里需要注意的是场景二的头文件这是要加上的
	Director::getInstance()->replaceScene(MySecondScene::createScene());
}*/