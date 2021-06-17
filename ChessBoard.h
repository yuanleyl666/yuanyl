#pragma once
#include "ui/CocosGUI.h"
#include "ChessBase.h"
#include"Menu//myMenu.h"
using namespace cocos2d;
class ChessWithSprite;
#include <iostream>

class ChessBoard
{
public:

    ChessWithSprite* getChess(const int& row, const int& column)
    {
        return &chess[row][column];
    }

    //set����chess�ľ�����Ҫ�������룻
    virtual bool setChess(const int& row, const int& column, ChessWithSprite* chessToSet)
    {
        chessToSet->changeChessToOtherChess(&this->chess[row][column]);
        /// //////////////////////

        //ui
        this->chess[row][column].getSprite()->getChildren().at(0)->setScale(100);
        return 1;
    }

protected:
    ChessWithSprite chess[8][8];
};

struct positionOnMap
{
    int x = -1;
    int y = -1;
    const bool operator==(const positionOnMap& p)const
    {
        return x == p.x && y == p.y;
    }
    positionOnMap(const int x, const int y)
    {
        this->x = x;
        this->y = y;
    }
};