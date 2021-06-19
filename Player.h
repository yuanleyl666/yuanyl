#pragma once
#include "ui/CocosGUI.h"
#include "ChessBase.h"
#include"ChessWithSprite.h"
#include"PlayerBoard.h"
#include "Shop.h"
using namespace cocos2d;
class Shop;
class PlayerBoard;

class Player
{
private:
    int playerRank;
    int exp;
    int level;
    int gold;
    int hp;
    bool IsPlayer;

    ChessWithSprite ChessReserve[5];
private:
    Sprite* PlayerSprite=nullptr;
    PlayerBoard* board=nullptr;
    Shop* ShopOpened=nullptr;
public:
    Player(bool isPlayer=1,const int GameLevel=0)
    {
        this->IsPlayer = isPlayer;
        if (this->IsPlayer == 1)
            this->playerRank = 0;
        else
            this->playerRank = 1;
        level = 1;
        gold = 5;
        hp = 100;
        exp = 0;
        if (GameLevel)
        {
            PlayerBoard *monsterBoard=new PlayerBoard;
            monsterBoard->setPlayer(this);
            this->setPlayerBoard(monsterBoard);
            switch (GameLevel)
            {
                case 1:
                    monsterBoard->setChess(4, 3, &ChessWithSprite(ChessWithSprite::Axe, 1));
                    monsterBoard->setChess(4, 2, &ChessWithSprite(ChessWithSprite::BH, 1));

                    break;
                case 2:
                    monsterBoard->setChess(4, 3, &ChessWithSprite(ChessWithSprite::Axe, 1));
                    monsterBoard->setChess(4, 2, &ChessWithSprite(ChessWithSprite::BH, 1));
                    monsterBoard->setChess(4, 1, &ChessWithSprite(ChessWithSprite::ChessType::CG));
                    break;
                case 3:
                    monsterBoard->setChess(4, 3, &ChessWithSprite(ChessWithSprite::Axe, 1));
                    monsterBoard->setChess(3, 3, &ChessWithSprite(ChessWithSprite::Axe, 1));
                    monsterBoard->setChess(4, 2, &ChessWithSprite(ChessWithSprite::BH, 1));
                    monsterBoard->setChess(4, 1, &ChessWithSprite(ChessWithSprite::ChessType::CG));
                    break;
                case 4:
                    monsterBoard->setChess(4, 3, &ChessWithSprite(ChessWithSprite::Axe, 2));
                    monsterBoard->setChess(4, 2, &ChessWithSprite(ChessWithSprite::BH, 2));
                    break;
                case 5:
                    monsterBoard->setChess(4, 3, &ChessWithSprite(ChessWithSprite::ChessType::GT, 1));
                    break;
            }
        }

    }

    const int getPlayerRank()const;
    const int getExp()const;
    const int getLevel()const;
    const int getGold()const;
    const int getHp()const;
    Sprite* getSprite()const;
    ChessWithSprite* getReserve(const int i);
    Shop* getShop();
    PlayerBoard* getPlayerBoard();

    bool setReserve(const int i, ChessWithSprite*);
    bool setPlayerRank(const int playerRank);
    bool setExp(const int Exp);
    bool setLevel(const int Level);
    bool setGold(const int Gold);
    bool setHp(const int Hp);
    bool setSprite(Sprite* sp);
    void setPlayerBoard(PlayerBoard* toSet);
    void setShop(Shop* shop);

    void openShop();
    


};
