#pragma once
#include <cmath>
#include "cocos2d.h"
using namespace cocos2d;

class ChessBase
{

protected:
    int attackInterval = 0;
    int player = 0;
    int price = 0;
    int level = 0;
    bool isDead = 0;

    double HP = 0;//ÑªÁ¿
    double MP = 0;//À¶   
    double AT = 0;//¹¥»÷Á¦
    double AR = 0;//»¤¼×Öµ
    double MR = 0;//Ï÷¼õ¼¼ÄÜÉËº¦·ù¶È
    double RA = 0;//¹¥»÷·¶Î§

public:

    bool setHp(const double& hp);
    bool setMp(const double& mp);
    bool setAT(const double& at);
    bool setAR(const double& ar);
    bool setMR(const double& mr);
    bool setRA(const double& ra);

    bool setAttackInterval(const int& ai);

    bool setPlayer(const int& Player);

    bool setPrice(const int& Price);

    const int getAttackInterval()const;
    const int getPlayer()const;
    const int getPrice()const;
    const double getHP()const;
    const double getMP()const;
    const double getAT()const;
    const double getAR()const;
    const double getMR()const;
    const double getRA()const;

    bool attack(ChessBase* targetChess);
};



class ChessWithSprite:public ChessBase
{
public:
    enum ChessType { noChess, firstType, secondType, thirdType };

    ChessWithSprite(){}

    ChessWithSprite(const ChessWithSprite& chess);

    ChessWithSprite& operator=(const ChessWithSprite& chess);

    ChessWithSprite(const ChessWithSprite::ChessType& type)
    {
        this->chessType = type;
        this->init();
    }
    
    bool setSprite(Sprite*);   
    
    Sprite* getSprite()const;
    
    bool attack(ChessWithSprite* targetChess);
    
    void setChessType(const ChessType& type);
    
    ChessType getChessType()const;
    
    void init();
private:
    ChessType chessType=noChess;

    Sprite* sprite=nullptr;
};



