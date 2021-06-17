#pragma once
#include <cmath>
#include "cocos2d.h"
using namespace cocos2d;
//�������ݴ���Ļ���
class ChessBase
{

protected:
    int attackInterval = 0;
    int player = 0;
    int price = 0;
    int level = 0;
    bool isDead = 0;

    double HP = 0;//Ѫ��
    double MP = 0;//��   
    double AT = 0;//������
    double AR = 0;//����ֵ
    double MR = 0;//���������˺�����
    double RA = 0;//������Χ

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