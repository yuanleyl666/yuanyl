#pragma once

#ifndef _GAME_TIMER_H_
#define _GAME_TIMER_H_

#include "cocos2d.h"
#include"FightBoard.h"
USING_NS_CC;
class FightBoard;
class GameTimer : public cocos2d::Node
{
public:
	GameTimer();

	virtual ~GameTimer();

	static GameTimer* createTimer(float time);

	void update(float delta);

	bool init(float time);

	FightBoard* fightboard;

	void setFightBoard(FightBoard* board)
	{
		this->fightboard = board;
	}
private:

	Label* label;
	float pTime;
};

#endif