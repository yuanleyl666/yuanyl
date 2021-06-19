#include "FirstScene.h"
#include"SecondScene.h"

//MyFirstScene��������ʵ��
Scene* MyFirstScene::createScene()
{
	auto scene = Scene::create();	//����һ������
	auto layer = MyFirstScene::create();//����һ��MyFirstScene��
	scene->addChild(layer);		//��MyFirstScene�����ոմ����ĳ����У�
	return scene;			//�����������
}

bool MyFirstScene::init()
{
	if (!Layer::init())	//�ȳ�ʼ�������init��������γ�ʼ��ʧ�ܣ��򴴽�MyFirstScene��ʧ��
	{
		return false;
	}
	Size VisibleSize = Director::getInstance()->getVisibleSize();	//�����Ļ��С
	Size size = Director::getInstance()->getWinSize();
	Sprite* pSprite = Sprite::create("res\\start_scene_background.png");//res\\start_scene_background.png
	pSprite->setPosition(size.width / 2, size.height / 2);
	float winw = size.width;
	float winh = size.height;

	float spx = pSprite->getTextureRect().getMaxX();
	float spy = pSprite->getTextureRect().getMaxY();

	pSprite->setScaleX(winw / spx);
	pSprite->setScaleY(winh / spy);
	this->addChild(pSprite, 0);

	auto label = Label::createWithSystemFont("Start", "fonts/Marker Felt.ttf", 32);//����һ����ǩ
	//�˵���Ŀ�Ĵ����ж��֣�֮ǰ��HelloWorld.cpp��ʵ�ֵ���ͼƬ�˵���Ŀ(MenuItemImage)��������ͼƬ�������˵���Ŀ
	//�����Ǹ��ݱ�ǩ�������˵���Ŀ,Ȼ�����ûص�����
	auto menuitem = MenuItemLabel::create(label, CC_CALLBACK_1(MyFirstScene::EnterSecondScene, this));
	//�������˲˵���Ŀ������Ҫ����˵��У�����������Ǵ����˵�
	auto menu = Menu::create(menuitem, NULL);
	//�Ѳ˵���ӵ�MyFirstScene����
	this->addChild(menu);

	return true;
}
//�˵��ص�������ʵ��
void MyFirstScene::EnterSecondScene(Ref* pSender)
{
	//����֪���������Ҫ��ת�������ͻ��뵽һ���࣬������Director�࣬�����ǹ�������
	//������ת�������õ����ǵ����������ӿڣ�replaceScene(Scene *scene),���洫��ȥ���Ǿ���һ��������������Ҫע����ǳ�������ͷ�ļ�����Ҫ���ϵ�
	Director::getInstance()->replaceScene(MySecondScene::createScene());
}