#include "FirstScene.h"
#include"SecondScene.h"
#include"ThirdScene.h"

//MyFirstScene��������ʵ��
Scene* MyThirdScene::createScene()
{
	auto scene = Scene::create();	//����һ������
	auto layer = MyThirdScene::create();//����һ��MyFirstScene��
	scene->addChild(layer);		//��MyFirstScene�����ոմ����ĳ����У�
	return scene;			//�����������
}

bool MyThirdScene::init()
{
	if (!Layer::init())	//�ȳ�ʼ�������init��������γ�ʼ��ʧ�ܣ��򴴽�MyFirstScene��ʧ��
	{
		return false;
	}
	
	return true;
}
//�˵��ص�������ʵ��
/*void MyThirdScene::EnterSecondScene(Ref* pSender)
{
	//����֪���������Ҫ��ת�������ͻ��뵽һ���࣬������Director�࣬�����ǹ�������
	//������ת�������õ����ǵ����������ӿڣ�replaceScene(Scene *scene),���洫��ȥ���Ǿ���һ��������������Ҫע����ǳ�������ͷ�ļ�����Ҫ���ϵ�
	Director::getInstance()->replaceScene(MySecondScene::createScene());
}*/