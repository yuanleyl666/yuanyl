#pragma once
#include "ui/CocosGUI.h"
#include "ChessBase.h"
#include"Menu//myMenu.h"
#include"ChessWithSprite.h"
#include"Player.h"
using namespace cocos2d;
class ChessWithSprite;
class Player;
class Shop
{

private:
    Player* whoOpenThis;
    Sprite* shopSprite;
    ChessWithSprite ChessLibrary[5];
public:
    //根据player的等级等初始化shop
    friend void shopUpDate(Shop* shop)
    {
        auto player = shop->getPlayer();
        shop->closeShop();
        Shop* _shop = new Shop(player);
        player->getSprite()->addChild(shop->getSprite(), 0, 1);
    }
    Shop(Player* player);

    Sprite* getSprite()
    {
        return this->shopSprite;
    }

    void setSprite(Sprite*);
    ///买棋子
    bool buyChess(const int i);
    //ui关闭商店,同时断开商店和player的指针
    void closeShop();

    Player* getPlayer();

    void setPlayer(Player*);
};