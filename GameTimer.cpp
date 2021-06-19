#include"GameTimer.h"

GameTimer::GameTimer()
{

}

GameTimer::~GameTimer()
{

}

bool GameTimer::init(float time)
{
	pTime = time;

	label = Label::create();
	label->setPosition(0, 0);

	this->addChild(label);

        schedule(CC_SCHEDULE_SELECTOR(GameTimer::update),0.1f);

	return true;
}

void GameTimer::update(float delta)
{
	bool player_1_lose = 1;
	bool player_2_lose = 1;
	pTime -= delta;
	char* mtime = new char[10];
	//此处只是显示分钟数和秒数  自己可以定义输出时间格式
	sprintf(mtime, "%d", (int)pTime);
	label->setString(mtime);
	fightboard->act(player_1_lose, player_2_lose);
	if (pTime <= 0 || player_1_lose == 0 || player_2_lose)
	{
		fightboard->Winner(player_1_lose);
		fightboard->fight();
		this->unschedule(CC_SCHEDULE_SELECTOR(GameTimer::update));
	}
}

GameTimer* GameTimer::createTimer(float time)
{
	GameTimer* gametimer = new GameTimer;
	if (gametimer && gametimer->init(time))
	{
		gametimer->autorelease();
		return gametimer;
	}
	else
	{
		delete gametimer;
		gametimer = NULL;
	}
	return NULL;
}


