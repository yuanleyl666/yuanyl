#pragma once
#include "ui/CocosGUI.h"
#include "ChessBase.h"
#include"ChessWithSprite.h"
using namespace cocos2d;


class ChessBoard
{
public:

    ChessWithSprite* getChess(const int& row, const int& column)
    {
        return &chess[row][column];
    }

    //set进的chess的精灵需要重新载入；
    virtual bool setChess(const int& row, const int& column, ChessWithSprite* chessToSet)
    {
        chessToSet->changeChessToOtherChess(&this->chess[row][column]);
        return 1;
    }

protected:
    ChessWithSprite chess[8][8];
};

struct positionOnMap
{
    int x = -1;
    int y = -1;
    positionOnMap& operator=(const positionOnMap& position)
    {
        this->x = position.x;
        this->y = position.y;
        return *this;

    }
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
