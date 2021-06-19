#pragma once
#include "ui/CocosGUI.h"
#include "ChessBase.h"
#include"myMenu.h"
#include"ChessWithSprite.h"
#include"PlayerBoard.h"
#include "Shop.h"
using namespace cocos2d;
class Shop;
class PlayerBoard;

class Player
{
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
public:
    const int getPlayerRank()const;
    const int getExp()const;
    const int getLevel()const;
    const int getGold()const;
    const int getHp()const;
    Sprite* getSprite()const;
    ChessWithSprite* getReserve(const int i);
    Shop* getShop();
    PlayerBoard* getPlayerBoard();

    bool setReserve(const int i, ChessWithSprite*);
    bool setPlayerRank(const int playerRank);
    bool setExp(const int Exp);
    bool setLevel(const int Level);
    bool setGold(const int Gold);
    bool setHp(const int Hp);
    bool setSprite(Sprite* sp);
    void setPlayerBoard(PlayerBoard* toSet);
    void setShop(Shop* shop);

    void openShop();



};
