#include"Player.h"
#include "Shop.h"
using namespace cocos2d;

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

bool Player::setReserve(const int i, ChessWithSprite* toSet)
{
    if (this->ChessReserve[i].getChessType() == ChessWithSprite::ChessType::noChess)
        return 0;
    toSet->changeChessToOtherChess(&this->ChessReserve[i]);
    toSet->setPlayer(this->playerRank);

}

Shop* Player::getShop()
{
    return this->ShopOpened;
}

void Player::setShop(Shop* toSet)
{
    this->ShopOpened = toSet;
}

Sprite* Player::getSprite()const
{
    return this->PlayerSprite;
}

bool Player::setSprite(Sprite* sp)
{
    this->PlayerSprite = sp;
    return 1;
}

void  Player::openShop()
{
    Player* playerPoint = this;
    Shop* toOpen = new Shop((Player*)(playerPoint));
}

void Player::setPlayerBoard(PlayerBoard* toSet)
{
    this->board = toSet;
}

PlayerBoard* Player::getPlayerBoard()
{
    return this->board;
}
