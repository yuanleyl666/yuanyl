#pragma once
#include "ChessBase.h"
class Player;
class Shop;

class ChessBoard
{
public:

	ChessWithSprite* getChess(const int& row, const int& column)
    {
        return &chess[row][column];
    }
    bool setChess(const int &row,const int column,const ChessWithSprite& chess)
    {
        this->chess[row][column] = chess;
    }

protected:
	ChessWithSprite chess[8][8];
};

class PlayerBoard:public ChessBoard
{
public:
    Scene* getBoardScene();
    void setBoardScene(Scene*);

    Player* getPlayer();
    void setPlayer(Player*);


private:
    Scene* boardScene;
    Player* player;

};
struct positionOnMap
{
    int x=-1;
    int y=-1;
    const bool operator==(const positionOnMap& p)const
    {
        return x == p.x && y == p.y;
    }
    positionOnMap(const int x,const int y)
    {
        this->x = x;
        this->y = y;
    }
};

class FightBoard:
    public ChessBoard
{
public:


    const positionOnMap findNextMove(const int xInBoard, const int yInBoard);
    const positionOnMap findPossibleAttackAim(const int xInBoard, const int yInBoard);
    void fight();
    bool init(Player* p1, Player* p2);
    Scene* getBoardScene();
    void setBoardScene(Scene*);
private:
    Scene* boardScene;
    Player* player1;
    Player* player2;
};

class Shop
{
    
private:
    Player* whoOpenThis;
    Sprite* shopSprite;
    ChessWithSprite ChessLibrary[5];
public:
    Shop(Player* player);
    Sprite* getSprite();
    void setSprite(Sprite*);

    bool buyChess(const int i);
    void closeShop();

    Player* getPlayer();
    void setPlayer(Player*);
};

class Player
{
public:

    
    const int getPlayerRank()const;
    const int getExp()const;
    const int getLevel()const;
    const int getGold()const;
    const int getHp()const;
    ChessWithSprite* getReserve(const int i);

    bool setReserve(const int i,ChessWithSprite);
    bool setPlayerRank(const int playerRank);
    bool setExp(const int Exp);
    bool setLevel(const int Level);
    bool setGold(const int Gold);
    bool setHp(const int Hp);
    
    Shop* getShop();
    void setShop(Shop*);
    void openShop()
    {
        Shop toOpen(this);

        this->PlayerSprite->addChild(toOpen.getSprite());
    }
private:
    int playerRank;

    int exp;
    int level;
    int gold;
    int hp;
    ChessWithSprite ChessReserve[5];
private:
    Sprite* PlayerSprite;
    PlayerBoard* board;
    Shop* ShopOpened;

};


