#include"ChessBase.h"

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
    this->mR = mr;
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


const int ChessBase::getPlayer()const
{
    return this->player;
}
const int  ChessBase::getPrice()const
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
    return mR;
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
