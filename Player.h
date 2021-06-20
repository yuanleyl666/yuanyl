#pragma once
#include "ui/CocosGUI.h"
#include "ChessBase.h"
#include"myMenu.h"
#include"ChessWithSprite.h"
#include"PlayerBoard.h"
#include "Shop.h"
#include "SecondScene.h"
using namespace cocos2d;
class Shop;
class PlayerBoard;
class MySecondScene;

class Player
{
private:
    int playerRank;
    int exp;
    int level = 1;
    int gold;
    int hp;
    ChessWithSprite ChessReserve[5];
private:
    Sprite* PlayerSprite;
    PlayerBoard* board;
    Shop* ShopOpened;
    MySecondScene* secondscene;
public:
    const int getPlayerRank()const;
    const int getExp()const;
    const int getLevel()const;
    const int getGold()const;
    const int getHp()const;
    Sprite* getSprite()const;
    ChessWithSprite* getReserve(const int i);

    bool setReserve(const int i, ChessWithSprite*);
    bool setPlayerRank(const int playerRank);
    bool setExp(const int Exp);
    bool setLevel(const int Level);
    bool setGold(const int Gold);
    bool setHp(const int Hp);
    bool setSprite(Sprite* sp);
    Shop* getShop();
    void setShop(Shop* shop);
    void openShop();
    PlayerBoard* getPlayerBoard();
    void setPlayerBoard(PlayerBoard* toSet);
    MySecondScene* getSecondScene();
    void setSecondScene(MySecondScene* toSet);
};
