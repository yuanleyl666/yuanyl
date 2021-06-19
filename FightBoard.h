#pragma once
#include "ui/CocosGUI.h"
#include "ChessBase.h"
#include"FirstScene.h"
#include"SecondScene.h"
#include"ChessBoard.h"
#include"Player.h"
#include"Shop.h"
#include"PlayerBoard.h"
#include "GameTimer.h"
using namespace cocos2d;
#include <iostream>
class FightBoard :public ChessBoard
{
public:
    void attack(const int xInit, const int yInti, const int xAim, const int yAim);

    //��x,y��������,Ѱ������һ���ƶ�������
    const positionOnMap findNextMove(const int xInBoard, const int yInBoard);
    //��x,y��������,Ѱ��������Ŀ�������
    const positionOnMap findPossibleAttackAim(const int xInBoard, const int yInBoard);
    void moveChess(const int xInit, const int yInit, const int xAim, const int yAim);
    void act(bool& player_1_lose, bool& player_2_lose);
    //
    void fight();
    bool init(Player* p1, Player* p2);
    Scene* getBoardScene();
    void setBoardScene(Scene* toSet);
    void Winner(bool player1_lose);
    int getFightWinner();
private:
    Scene* boardScene = nullptr;
    Player* player1 = nullptr;
    Player* player2 = nullptr;
    int fightWinner = 0;
};
