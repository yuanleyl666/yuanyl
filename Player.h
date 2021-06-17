#pragma once
#include "ui/CocosGUI.h"
#include "ChessBase.h"
#include"Menu//myMenu.h"
#include"ChessWithSprite.h"
#include"Shop.h"
#include"PlayerBoard.h"
using namespace cocos2d;
class ChessWithSprite;
class shop;
class PlayerBoard;
class Player
{
public:
    const int getPlayerRank()const;
    const int getExp()const;
    const int getLevel()const;
    const int getGold()const;
    const int getHp()const;
    Sprite* getSprite()const
    {
        return this->PlayerSprite;
    }
    ChessWithSprite* getReserve(const int i);

    bool setReserve(const int i, ChessWithSprite*);
    bool setPlayerRank(const int playerRank);
    bool setExp(const int Exp);
    bool setLevel(const int Level);
    bool setGold(const int Gold);
    bool setHp(const int Hp);
    bool setSprite(Sprite* sp)
    {
        this->PlayerSprite = sp;
    }
    Shop* getShop();
    void setShop(Shop*);
    void openShop()
    {
        Shop* toOpen = new Shop(this);

        this->PlayerSprite->addChild(toOpen->getSprite(), 0, 1);
    }
    PlayerBoard* getPlayerBoard()
    {
        return this->board;
    }
    void setPlayerBoard(PlayerBoard* toSet)
    {
        this->board = toSet;
    }
private:
    int playerRank;
    int exp;
    int level;
    int gold;
    int hp;
    ChessWithSprite ChessReserve[5];
private:
    Sprite* PlayerSprite;
    PlayerBoard* board;
    Shop* ShopOpened;

};