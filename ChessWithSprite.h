#pragma once
#include <cmath>
#include "cocos2d.h"
#include"ChessBase.h"
using namespace cocos2d;


//在基类基础上放置了精灵
class ChessWithSprite :public ChessBase
{
public:
    ChessWithSprite()
    {

    }
    //需要更改数据
    enum ChessType { noChess, Axe, CG, BH, DR, CK, MR, QoP, Jugg, TK, DS, PA, TW, GG, GS, DK, TA, DRK, GT, TH, COCO };

    //复制构造，在复制构造过程中，精灵也会复制并绑定到新对象，会初始化棋子的数据
    ChessWithSprite(const ChessWithSprite& chess);

    //赋值，只赋值不初始化，用于战斗等，精灵也会复制并绑定到新对象
    ChessWithSprite& operator=(const ChessWithSprite& chess);

    //根据棋子的type进行构造
    ChessWithSprite(const ChessWithSprite::ChessType& type, const int level = 1) : ChessWithSprite()
    {
        this->level = level;
        this->chessType = type;
        this->init(level);
    }

    //只设定棋子绑定的原精灵（透明的精灵）（基本弃用）
    bool setSprite(Sprite*);

    //只得到棋子绑定的原精灵（透明的精灵）
    Sprite* getSprite()const;

    //攻击

    //需要修改攻击动画（未完成）
    bool attack(ChessWithSprite* targetChess);

    void setChessType(const ChessType& type);

    ChessType getChessType()const;

    //根据棋子的type进行初始化并绑定对应type精灵
    void init(const int level = 1);
    void initInShop(const int level = 1);
    //把参数的棋子换成调用的棋子并且把调用函数的棋子变为nochess
    bool changeChessToOtherChess(ChessWithSprite* chess)
    {
        if (this->chessType == noChess || chess->chessType != noChess)
            return 0;

        *chess = *this;
        this->chessType = noChess;
        this->init();
    }
private:
    ChessType chessType = noChess;

    Sprite* sprite = nullptr;
};
