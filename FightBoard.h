#pragma once
#include "ui/CocosGUI.h"
#include "ChessBase.h"
#include"myMenu.h"
#include"ChessBoard.h"
#include"Player.h"
#include"Shop.h"
#include"PlayerBoard.h"
using namespace cocos2d;
#include <iostream>
class FightBoard :public ChessBoard
{
public:
    void attack(const int xInit, const int yInti, const int xAim, const int yAim);

    //对x,y处的棋子,寻找它下一次移动的坐标
    const positionOnMap findNextMove(const int xInBoard, const int yInBoard);
    //对x,y处的棋子,寻找它攻击目标的坐标
    const positionOnMap findPossibleAttackAim(const int xInBoard, const int yInBoard);
    void moveChess(const int xInit, const int yInit, const int xAim, const int yAim)
    {
        if (this->chess[yInit][xInit].getChessType() == ChessWithSprite::ChessType::noChess)
            return;
        this->chess[yInit][xInit].changeChessToOtherChess(&this->chess[yAim][xAim]);
        double distance = 16.0f;
        auto operateSprite = this->chess[yAim][xAim].getSprite()->getChildByTag(0);
        operateSprite->setPosition(operateSprite->getPositionX() - (xAim - xInit), operateSprite->getPositionY() - (yAim - yInit));
        // Move a sprite to a specific location over 2 seconds.
        auto moveTo = MoveTo::create(2, Vec2(xAim - xInit, yAim - yInit));
        operateSprite->runAction(moveTo);
    }
    //
    void fight()
    {
        while (1)
        {
            bool isActed[8][8] = { 0 };

            bool player_1_lose = 1;
            bool player_2_lose = 1;
            for (int i = 0; i < 8; i++)
                for (int k = 0; k < 8; k++)
                {
                    if (chess[i][k].getChessType() && !isActed[i][k])
                    {
                        if (chess[i][k].getPlayer() == player1->getPlayerRank())
                            player_1_lose = 0;
                        else if (chess[i][k].getPlayer() == player2->getPlayerRank())
                            player_2_lose = 0;

                        positionOnMap atkPosition = this->findPossibleAttackAim(k, i);
                        positionOnMap movePosition = this->findNextMove(k, i);
                        if ((movePosition == positionOnMap(k, i)) == 0)
                        {
                            moveChess(k, i, movePosition.x, movePosition.y);
                            log("MOVE");
                            log("%d,%d", movePosition.x, movePosition.y);
                            isActed[movePosition.y][movePosition.x] = 1;
                        }
                        else
                        {
                            chess[i][k].attack(&chess[atkPosition.y][atkPosition.x]);
                            isActed[atkPosition.y][atkPosition.x] = 1;
                            CCLOG("ATK");
                        }
                    }
                }
            if (player_1_lose)
            {
                player1->setHp(player1->getHp() - 1);
                break;
            }
            if (player_2_lose)
            {
                player2->setHp(player2->getHp() - 1);
                break;
            }

        }
    }

    bool init(Player* p1, Player* p2)
    {
        auto visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        this->boardScene = Scene::create();

        auto MapSprite = Sprite::create("HelloWorld.png");
        MapSprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
        boardScene->addChild(MapSprite);

        for (int i = 0; i < 8; i++)
            for (int k = 0; k < 8; k++)
            {
                MapSprite->addChild(chess[i][k].getSprite());
                auto chessSprite = chess[i][k].getSprite();
                chessSprite->setScale(0.12, 0.12);
                auto move = MoveTo::create(0, Vec2(20.0f + k * 25.0f, 50.0f + i * 25.0f));
                chessSprite->runAction(move);
            }

        this->player1 = p1;
        this->player2 = p2;
        for (int i = 0; i < 8; i++)
        {
            for (int k = 0; k < 8; k++)
            {
                if (i < 4)
                {
                    this->chess[i][k] = *(p1->getPlayerBoard()->getChess(i, k));

                }
                else
                {
                    this->chess[i][k] = *(p2->getPlayerBoard()->getChess(7 - i, 7 - k));

                }
            }
        }
        return 1;
    }
    Scene* getBoardScene()
    {
        return this->boardScene;
    }
    void setBoardScene(Scene* toSet)
    {
        this->boardScene = toSet;
    }

private:
    Scene* boardScene = nullptr;
    Player* player1 = nullptr;
    Player* player2 = nullptr;
    int fightWinner = 0;
};
