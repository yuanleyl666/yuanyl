#include "ChessBoard.h"
const int Player::getPlayerRank()const
{
	return this->playerRank;
}
const int  Player::getExp()const
{
	return this->exp;
}
const int  Player::getLevel()const
{
	return this->level;
}
const int  Player::getGold()const
{
	return this->gold;
}
const int  Player::getHp()const
{
	return this->hp;
}


bool  Player::setPlayerRank(const int playerRank) 
{
	if (this == nullptr)
		return 0;
	this->playerRank = playerRank;
	return 1;
}
bool  Player::setExp(const int exp)
{
	if (this == nullptr)
		return 0;
	this->exp = exp;
	return 1;
}
bool  Player::setLevel(const int Level)
{
	if (this == nullptr)
		return 0;
	this->level = Level;
	return 1;
}
bool  Player::setGold(const int Gold)
{
	if (this == nullptr)
		return 0;
	this->gold = Gold;
	return 1;
}

bool  Player::setHp(const int Hp)
{
	if (this == nullptr)
		return 0;
	this->hp = Hp;
	return 1;
}

ChessWithSprite* Player::getReserve(const int i)
{
	return &this->ChessReserve[i];
}
bool Player::setReserve(const int i, ChessWithSprite)
{
	return 0;
}
Shop* Player::getShop()
{
	return this->ShopOpened;
}
void Player::setShop(Shop* toSet)
{
	this->ShopOpened = toSet;
}

//////////////////////////////////////////////////////////////////////////////////////////

Shop::Shop(Player* player)
{
	this->whoOpenThis = player;

	for (int i = 0; i < 5; i++)
	{
		int rate=random() % 100;
		//具体某种棋子
		if (rate< 1)
		{
			ChessLibrary[i].setChessType(ChessWithSprite::ChessType::firstType);
			ChessLibrary[i].init();
		}
	}
	player->setShop(this);
	//设置ui和按钮
	this->setSprite(Sprite::create());








	//

}
Sprite* Shop::getSprite()
{
	return this->shopSprite;
}
void Shop::setSprite(Sprite* toSet)
{
	this->shopSprite = toSet;
}
bool Shop::buyChess(const int rank)
{
	
	if (rank < 0 || rank>4)
		return 0;
	if (this->whoOpenThis->getGold() < this->ChessLibrary[rank].getPrice())
		return 0;
	bool reseverIsFull = 1;
	for (int i = 0; i < 5; i++)
	{
		if (this->whoOpenThis->getReserve(i)->getChessType() == ChessWithSprite::ChessType::noChess)
		{
			
			reseverIsFull = 0;
			this->whoOpenThis->setGold(this->whoOpenThis->getGold() - this->ChessLibrary[rank].getPrice());
			this->whoOpenThis->setReserve(i, this->ChessLibrary[rank]);
			this->ChessLibrary[rank].setChessType(ChessWithSprite::ChessType::noChess);
			//ui


		}
	}
	if (reseverIsFull)
		return 0;
	/// 
	/// 
	return 1;
}
void Shop::closeShop()
{
	this->whoOpenThis->setShop(nullptr);
	this->whoOpenThis = nullptr;
	//ui关闭商店界面


	//
}


Player* Shop::getPlayer()
{
	return this->whoOpenThis;
}
void Shop::setPlayer(Player* toSet)
{
	this -> whoOpenThis = toSet;
}




//////////////////////////////////////////////////////////////////////////////////////////////////

Scene* PlayerBoard::getBoardScene()
{
	return this->boardScene;
}
void PlayerBoard::setBoardScene(Scene* toSet)
{
	this->boardScene = toSet;
}
Player* PlayerBoard::getPlayer()
{
	return this->player;
}
void PlayerBoard::setPlayer(Player* toSet)
{
	this->player = toSet;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

const positionOnMap FightBoard::findNextMove(const int xInBoard,const int yInBoard)
{
	auto AimPosition = findPossibleAttackAim(xInBoard, yInBoard);
	
	if (AimPosition == positionOnMap(-1, -1))
		return positionOnMap(xInBoard, yInBoard);
	
	if (1)
	{
		double EnemyDistance = fabs(yInBoard - AimPosition.y) > fabs(xInBoard - AimPosition.x) ? fabs(xInBoard - AimPosition.x) : fabs(yInBoard - AimPosition.y);
		if (EnemyDistance <= chess[yInBoard][xInBoard].getAR())
			return positionOnMap(xInBoard, yInBoard);
	}

	if (1)
	{
		positionOnMap positionToReturn(xInBoard, yInBoard);
		double MinDistanceToEnemy = 0;
		for(int i=-1;i<2;i++)
			for (int k = -1; k < 2; i++)
			{
				if (xInBoard + k < 0 || xInBoard + k>7 || yInBoard + i < 0 || yInBoard + i>7 ||chess[yInBoard+i][xInBoard+k].getChessType()!=ChessWithSprite::ChessType::noChess)
					continue;

				double EnemyDistance = fabs(yInBoard+i - AimPosition.y) > fabs(xInBoard+k - AimPosition.x) ? fabs(xInBoard+k - AimPosition.x) : fabs(yInBoard+k - AimPosition.y);
				if (EnemyDistance < MinDistanceToEnemy)
				{
					positionToReturn = positionOnMap(xInBoard + k, yInBoard + i);
					MinDistanceToEnemy = EnemyDistance;
				}
			}

		return positionToReturn;
	}

	
		
}

//为某坐标上的棋子寻找最近的敌人的位置
const positionOnMap FightBoard::findPossibleAttackAim(const int xInBoard, const int yInBoard)
{
	positionOnMap toReturn(-1,-1);
	double distance = 0;
	for (int i = 1; i < 8; i++)
	{
		for (int k = 0; k < 9; k++)
		{
			if (this->chess[i][k].getChessType() == ChessWithSprite::ChessType::noChess)
				continue;
			if (this->chess[i][k].getPlayer() != this->chess[yInBoard][xInBoard].getPlayer())
			{
				double dis = fabs(yInBoard - i) > fabs(xInBoard - k) ? fabs(xInBoard - k) : fabs(yInBoard - i);
				if (dis < distance)
				{
					toReturn.x = k;
					toReturn.y = i;
					distance = dis;
				}
			}
		}
	}
	return toReturn;
}


void FightBoard::fight()
{

}



bool FightBoard::init(Player* p1, Player* p2)
{
	for (int i = 0; i < 8; i++)
	{
		for (int k = 0; k < 8; k++)
		{

		}
	}
	return 1;
}
Scene* FightBoard::getBoardScene()
{
	return this->boardScene;
}
void FightBoard::setBoardScene(Scene* toSet)
{
	this->boardScene = toSet;
}







