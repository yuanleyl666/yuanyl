#pragma once
#include "ui/CocosGUI.h"
#include "ChessBase.h"
#include"ChessBoard.h"
#include "myMenu.h"
#include "Player.h"
using namespace cocos2d;
class Player;
class myMenu;
class PlayerBoard :public ChessBoard
{
public:
    myMenu* getBoardScene();
    void setBoardScene(myMenu*);
     Player* getPlayer();
    void setPlayer(Player*);
    void setMap(Sprite* map)
    {
        this->MapSprite = map;
    }
    Sprite* getMap()
    {
        return this->MapSprite;
    }
    virtual bool setChess(const int& row, const int& column, ChessWithSprite* chess);
    PlayerBoard();

private:
    Sprite* MapSprite = nullptr;
    myMenu* boardScene = nullptr;
    Player* player = nullptr;

};

