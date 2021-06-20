#pragma once
#include "ui/CocosGUI.h"
#include "ChessBase.h"
#include"ChessBoard.h"
#include "myMenu.h"
#include "Player.h"
#include "SecondScene.h"
using namespace cocos2d;
class Player;
class MySecondScene;
class PlayerBoard :public ChessBoard
{
public:
    MySecondScene* getBoardScene();
    void setBoardScene(MySecondScene*);
    //myadd
    Sprite* getMap();
    void setMap(Sprite*);

    void init()
    {
        if (this->MapSprite == nullptr )
            return;
        Point ppos;
        for (int i = 0; i < 8; i++)
            for (int k = 0; k < 8; k++)
            {
                if (chess[i][k].getSprite() == nullptr)
                    continue;
                auto chessSprite = chess[i][k].getSprite();
                ppos.x = 177 + 16 * i;
                ppos.y = 100 + 16 * k;
                chessSprite->setPosition(ppos);
                MapSprite->addChild(chessSprite,3);
            }
    }
     Player* getPlayer();
    void setPlayer(Player*);
    virtual bool setChess(const int& row, const int& column, ChessWithSprite* chess);
    PlayerBoard();

private:
    Sprite* MapSprite = nullptr;
    MySecondScene* boardScene = nullptr;
    Player* player = nullptr;

};

