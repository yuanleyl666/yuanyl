#pragma once
#include "ui/CocosGUI.h"
#include"ChessWithSprite.h"
#include"Player.h"
using namespace cocos2d;

class Player;

class Shop
{
private:
    Player* whoOpenThis;
    Sprite* shopSprite;
    ChessWithSprite ChessLibrary[5];

    Shop(const Shop&) = delete;
    Shop() = delete;
    Shop& operator=(const Shop&) = delete;
    friend Player;
    Shop(Player* player);
    void closeShop();
public:
    //根据player的等级等初始化shop
    friend void shopUpDate(Shop* shop, int pool[21]);
  
    Sprite* getSprite();

    void setSprite(Sprite*);
    ///买棋子
    bool buyChess(const int i);
    //ui关闭商店,同时断开商店和player的指针
  

    Player* getPlayer();

    void setPlayer(Player*);

};
