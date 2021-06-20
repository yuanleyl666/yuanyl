#pragma once
#include"cocos2d.h"
#include "Player.h"
#include "PlayerBoard.h"

using namespace cocos2d;
class PlayerBoard; class Player;
class MySecondScene :public Layer
{
public:
	static Scene* createScene();

	CREATE_FUNC(MySecondScene);

	virtual bool init();

	void EnterFirstScene(Ref* pSender);

	void menuCloseCallback(cocos2d::Ref* pSender);

	//myadd
	void moveChess(Sprite*);
	Player* getPlayer();
	void setPlayer(Player*);
	PlayerBoard* getBoard();
	void setBoard(PlayerBoard*);
	//MySecondScene* getScene();
	//void setScene(MySecondScene*);
private:
	Sprite* targetA = nullptr;
	Player* player = nullptr;
	PlayerBoard* board = nullptr;
	//MySecondScene* scene;
private:
	Point pos, posA, pos_org;
	int x, y, x_org, y_org;
};
