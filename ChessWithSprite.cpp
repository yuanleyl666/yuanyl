#include"ChessWithSprite.h"
using namespace cocos2d;


#define D 1
namespace ChessInitData
{
    const double Hp[21] = { 0,700,700,550,400,500,500,550,600,500,450,550,700,600,800,850,850,900,1000,950,1050 };
    const double AT[21] = { 0,50,45,50,60,40,50,55,65,40,65,70,80,60,60,55,90,60,50,50,80 };
    //const double AR[20] = { 0 };
    const double MR[21] = { 0,5,5,5,5,5,5,0,5,10,5,0,10,5,15,10,5,15,10,5,10 };
    const int RA[21] = { 0,D,D,D,3 * D,D,2 * D,2 * D,D,3 * D,5 * D,D,2 * D,3 * D,D,D,2 * D,D,3 * D,D,D };
    const int Price[21] = { 0,1,1,1,1,1,2,2,2,2,3,3,3,4,4,4,5,5,5,5,5 };
    const int Pro[21] = {0,1,2,3,4,5,5,3,1,2,4,3,1,4,2,5,3,5,2,4,1};//1:战士，2:地精，3:刺客，4:猎人，5:骑士
    const std::string SpriteInMap[21] = { "","res\\model\\Axe .png","res\\model\\CG .png","res\\model\\BH .png","res\\model\\DR .png","res\\model\\CK .png",
                                             "res\\model\\MR .png","res\\model\\QoP .png","res\\model\\Jugg .png","res\\model\\TK .png","res\\model\\DS .png",
                                             "res\\model\\PA .png","res\\model\\TW .png","res\\model\\GG .png","res\\model\\GS .png","res\\model\\DK .png",
                                             "res\\model\\TA .png","res\\model\\DRK .png","res\\model\\GT .png","res\\model\\TH .png","res\\model\\COCO" };
    const std::string SpriteInShop[21] = { "","res\\shop\\Axe .png","res\\shop\\CG .png","res\\shop\\BH .png","res\\shop\\DR .png","res\\shop\\CK .png",
                                             "res\\shop\\MR .png","res\\shop\\QoP .png","res\\shop\\Jugg .png","res\\shop\\TK .png","res\\shop\\DS .png",
                                             "res\\shop\\PA .png","res\\shop\\TW .png","res\\shop\\GG .png","res\\shop\\GS .png","res\\shop\\DK .png",
                                             "res\\shop\\TA .png","res\\shop\\DRK .png","res\\shop\\GT .png","res\\shop\\TH .png","res\\shop\\COCO" };
}

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
        //死亡动画






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

    HP = chess.HP;//血量
    MP = chess.MP;//蓝   
    AT = chess.AT;//攻击力
    AR = chess.AR;//护甲值
    mR = chess.mR;//削减技能伤害幅度
    RA = chess.RA;//攻击范围
    chessType = chess.chessType;

    if (this->chessType != 0)
    {
        auto child = Sprite::create("HelloWorld.png");
        this->sprite->addChild(child, 0, 0);
    }
    return *this;
};
void ChessWithSprite::init(const int level = 1)
{
    //数据初始化
    setMp(0);
    setRA(0);
    setMR(ChessInitData::MR[chessType]);
    setRA(ChessInitData::RA[chessType]);
    setPrice(ChessInitData::Price[chessType]);
    this->level = level;
    if (level == 1)
    {
        setHp(ChessInitData::Hp[chessType]);
        setAT(ChessInitData::AT[chessType]);
        //setAR(AR[chessType - 1]);       
    }
    
    if (level == 2)
    {
        setHp(ChessInitData::Hp[chessType] * 2);
        setAT(ChessInitData::AT[chessType] * 2);
        //setAR(AR[chessType - 1]*2);       
    }
    
    if (level == 3)
    {
        setHp(ChessInitData::Hp[chessType] * 3);
        setAT(ChessInitData::AT[chessType] * 3);
        //setAR(AR[chessType - 1]*3);       
    }

    this->player = 0;

    if (this->chessType != noChess)
    {
        auto childToSet = Sprite::create(ChessInitData::SpriteInMap[chessType]);
        this->sprite->addChild(childToSet, 0, 0);
     
    }
    else
    {


    }

}


void ChessWithSprite::initInShop(const int level=1)
{
    //数据初始化
    setMp(0);
    setRA(0);
    setMR(ChessInitData::MR[chessType]);
    setRA(ChessInitData::RA[chessType]);
    setPrice(ChessInitData::Price[chessType]);
    this->level = level;
    this->player = 0;
    if (level == 1)
    {
        setHp(ChessInitData::Hp[chessType]);
        setAT(ChessInitData::AT[chessType]);
        //setAR(AR[chessType - 1]);       
    }

    if (level == 2)
    {
        setHp(ChessInitData::Hp[chessType] * 2);
        setAT(ChessInitData::AT[chessType] * 2);
        //setAR(AR[chessType - 1]*2);       
    }

    if (level == 3)
    {
        setHp(ChessInitData::Hp[chessType] * 3);
        setAT(ChessInitData::AT[chessType] * 3);
        //setAR(AR[chessType - 1]*3);       
    }

    if (this->chessType != noChess)
    {
        auto childToSet = Sprite::create(ChessInitData::SpriteInShop[chessType]);
        this->sprite->addChild(childToSet, 0, 0);

    }
    else
    {
     
    }

}
