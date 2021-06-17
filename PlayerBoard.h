#pragma once
#include "ui/CocosGUI.h"
#include "ChessBase.h"
#include"Menu//myMenu.h"
#include"Player.h"
#include"ChessBoard.h"
using namespace cocos2d;
class ChessBoard;
class Player;
class PlayerBoard :public ChessBoard
{
public:
    myMenu* getBoardScene();
    void setBoardScene(myMenu*);
    Player* getPlayer();
    void setPlayer(Player*);
    virtual bool setChess(const int& row, const int& column, ChessWithSprite* chess)
    {
        ChessBoard::setChess(row, column, chess);
        this->chess[row][column].setPlayer(this->player->getPlayerRank());
        return 1;
    }
    PlayerBoard()
    {
        //这里需要重新设定scene

        for (int i = 0; i < 8; i++)
            for (int k = 0; k < 8; k++)
            {
                MapSprite->addChild(chess[i][k].getSprite());
                auto chessSprite = chess[i][k].getSprite();
                chessSprite->setScale(0.12, 0.12);
                auto move = MoveTo::create(0, Vec2(20 + k * 25, 50 + i * 25));
                chessSprite->runAction(move);
            }
        //设置事件读取

    }

private:
    Sprite* MapSprite = nullptr;
    myMenu* boardScene = nullptr;
    Player* player = nullptr;

};

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
        /// //////////////////////

        //ui
        this->chess[row][column].getSprite()->getChildren().at(0)->setScale(100);
        return 1;
    }

protected:
    ChessWithSprite chess[8][8];
};