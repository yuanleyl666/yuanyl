#include "ChessBase.h"
//////////////////////////////////////////////////////////////////////////////////////////

bool ChessBase::setHp(const double& hp)
{
    if (this == nullptr)
        return 0;
    this->HP = hp;
    return 1;
}
bool ChessBase::setMp(const double& mp)
{
    if (this == nullptr)
        return 0;
    this->MP = mp;
    return 1;
}
bool ChessBase::setAT(const double& at)
{
    if (this == nullptr)
        return 0;
    this->AT = at;
    return 1;
}
bool ChessBase::setAR(const double& ar)
{
    if (this == nullptr)
        return 0;
    this->AR = ar;
    return 1;
}
bool ChessBase::setMR(const double& mr)
{
    if (this == nullptr)
        return 0;
    this->MR = mr;
    return 1;
}
bool ChessBase::setRA(const double& ra)
{
    if (this == nullptr)
        return 0;
    this->RA = ra;
    return 1;
}
bool ChessBase::setAttackInterval(const int& ai)
{
    if (this == nullptr)
        return 0;
    this->attackInterval = ai;
    return 1;
}
bool  ChessBase::setPlayer(const int& Player)

{
    if (this == nullptr)
        return 0;
    this->player = Player;
    return 1;
}
bool  ChessBase::setPrice(const int& Price)

{
    if (this == nullptr)
        return 0;
    this->price = Price;
    return 1;
}


const int ChessBase:: getPlayer()const
{
    return this->player;
}
const int  ChessBase:: getPrice()const
{
    return this->price;
}
const int ChessBase::getAttackInterval()const
{
	return attackInterval;
}
const double ChessBase::getHP()const
{
	return HP;
}
const double ChessBase::getMP()const
{
	return MP;
}
const double ChessBase::getAT()const
{
	return AT;
}
const double ChessBase::getAR()const
{
	return AR;
}
const double ChessBase::getMR()const
{
	return MR;
}
const double ChessBase::getRA()const
{
	return RA;
}
bool ChessBase::attack(ChessBase* targetChess)
{
    if (this == nullptr)
        return 0;
    targetChess->HP -= (exp(AT - targetChess->AR) > targetChess->HP ? targetChess->HP : exp(AT - targetChess->AR));
    this->MP += 10;
    return 1;
}


//////////////////////////////////////////////////////////////////////////////////////////////
bool ChessWithSprite::setSprite(Sprite* toSet)
{
    if (this == nullptr)
        return 0;
    this->sprite = toSet;
    return 1;
}
Sprite* ChessWithSprite::getSprite()const
{
    return this->sprite;
}
bool ChessWithSprite::attack(ChessWithSprite* targetChess)
{
    if (this == nullptr)
        return 0;
    this->ChessBase::attack(targetChess);
    return 1;
}
void ChessWithSprite::setChessType(const ChessType& type)
{
    this->chessType = type;
}
ChessWithSprite::ChessType ChessWithSprite::getChessType()const
{
    return this->chessType;
}
ChessWithSprite::ChessWithSprite(const ChessWithSprite& chess) 
{
    this->chessType = chess.chessType;
    this->init();
}
ChessWithSprite& ChessWithSprite::operator=(const ChessWithSprite& chess)
{
    this->attackInterval = chess.attackInterval;
    player = chess.player;
    price = chess.price;
    level = chess.level;
    isDead = chess.isDead;

    HP = chess.HP;//ÑªÁ¿
    MP = chess.MP;//À¶   
    AT = chess.AT;//¹¥»÷Á¦
    AR = chess.AR;//»¤¼×Öµ
    MR = chess.MR;//Ï÷¼õ¼¼ÄÜÉËº¦·ù¶È
    RA = chess.RA;//¹¥»÷·¶Î§
    chessType = chess.chessType;
    return *this;
}
void ChessWithSprite::init()
{
    
    if (chessType == firstType)
    {
        setHp(1);
        setMp(1);
        setAT(1);
        setAR(1);
        setMR(1);
        setRA(1);
        setAttackInterval(1);
        setSprite(Sprite::create("1"));
    }


    else if (chessType == secondType)
    {
        setHp(2);
        setMp(2);
        setAT(2);
        setAR(2);
        setMR(2);
        setRA(2);
        setAttackInterval(2);
        setSprite(Sprite::create("2"));
    }
}