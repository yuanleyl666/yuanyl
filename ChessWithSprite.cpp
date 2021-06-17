#include"ChessWithSprite.h"
using namespace cocos2d;

//////////////////////////////////////////////////////////////////////////////////////////////
bool ChessWithSprite::setSprite(Sprite* toSet)
{
    if (this == nullptr)
        return 0;
    this->sprite;
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
    //donghua
    this->ChessBase::attack(targetChess);
    if (targetChess->getHP() < 1e-3)
    {
        //������������s
        this->chessType = ChessType::noChess;
        this->sprite->removeAllChildren();
        this->init();

    }
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
//just copy number
ChessWithSprite& ChessWithSprite::operator=(const ChessWithSprite& chess)
{
    this->sprite->removeAllChildren();

    this->attackInterval = chess.attackInterval;

    player = chess.player;
    price = chess.price;
    level = chess.level;
    isDead = chess.isDead;

    HP = chess.HP;//Ѫ��
    MP = chess.MP;//��   
    AT = chess.AT;//������
    AR = chess.AR;//����ֵ
    MR = chess.MR;//���������˺�����
    RA = chess.RA;//������Χ
    chessType = chess.chessType;

    if (this->chessType != 0)
    {
        auto child = Sprite::create("HelloWorld.png");
        this->sprite->addChild(child, 0, 0);
    }
    return *this;
}

void ChessWithSprite::init()
{
    //���ݳ�ʼ��
    std::string fileName[2] = { "","HelloWorld.png" };
    double HP[2] = { 0,100 };
    double RA[2] = { 0,1.5 };
    double AT[2] = { 0,50 };



    if (this->chessType != noChess)
    {
        auto childToSet = Sprite::create("HelloWorld.png");
        this->sprite->addChild(childToSet, 0, 0);
        this->setHp(HP[1]);
        this->setAT(AT[1]);
        this->setRA(RA[1]);
        this->player = 0;
    }
    else
    {

    }

}

