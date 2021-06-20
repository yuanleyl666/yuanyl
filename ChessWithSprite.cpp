#include"ChessWithSprite.h"
using namespace cocos2d;


#define D 1
namespace ChessInitData
{
    const double Hp[31] = { 0,700,700,550,400,500,500,550,600,500,450,550,700,600,800,850,850,900,1000,950,1050,300,400,500,600,700,800,900,1000,1100,1200 };
    const double AT[31] = { 0,50,45,50,60,40,50,55,65,40,65,70,80,60,60,55,90,60,50,50,80,20,25,35,40,50,55,60,65,75,80 };
    //const double AR[20] = { 0 };
    const double MR[31] = { 0,5,5,5,5,5,5,0,5,10,5,0,10,5,15,10,5,15,10,5,10,5,5,5,5,5,5,5,5,5,5 };
    const int AR[31] = { 0,1,1,1,3,1,2,2,1,3,5,1,2,3,1,1,2,1,3,1,1,1,1,1,1,1,1,1,1,1,1 };
    const int Price[31] = { 0,1,1,1,1,1,2,2,2,2,3,3,3,4,4,4,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0 };
    const int Pro[31] = { 0,1,2,3,4,5,5,3,1,2,4,3,1,4,2,5,3,5,2,4,1,0,0,0,0,0,0,0,0,0,0 };//0:怪，1:战士，2:地精，3:刺客，4:猎人，5:骑士
    struct monster
    {
        int type;
        int x;
        int y;
        monster(const int type, const int x, const int y)
        {
            this->type = type;
            this->x = x;
            this->y = y;
        }
    };
    const std::vector<monster>MonsPos[14] = { {}, {monster(21,5,4),monster(21,5,4)},{monster(21,5,4),monster(22,5,4)},
                                 {monster(21,5,4),monster(22,5,5),monster(21,5,6)},{monster(21,5,4),monster(23,5,5),monster(21,5,6)},
                                 {monster(22,5,3),monster(22,5,4),monster(22,5,5),monster(22,5,6)},{monster(22,5,3),monster(23,5,4),monster(23,5,5),monster(22,5,6)},
                                 {monster(22,5,3),monster(23,5,4),monster(24,5,5),monster(23,5,6),monster(22,5,7)},{monster(23,5,3),monster(23,5,4),monster(24,5,5),monster(23,5,6),monster(23,5,7)},
                                 {monster(24,5,2),monster(25,5,3),monster(26,5,4),monster(26,5,5),monster(25,5,6),monster(24,5,7)},{monster(25,5,2),monster(26,5,3),monster(27,5,4),monster(27,5,5),monster(26,5,6),monster(25,5,7)},
                                 {monster(25,5,2),monster(26,5,3),monster(27,5,4),monster(28,5,5),monster(27,5,6),monster(26,5,7),monster(25,5,8)},{monster(26,5,2),monster(27,5,3),monster(28,5,4),monster(29,5,5),monster(28,5,6),monster(27,5,7),monster(26,5,8)},
                                 {monster(27,5,1),monster(28,5,2),monster(29,5,3),monster(30,5,4),monster(30,5,5),monster(29,5,6),monster(28,5,7),monster(27,5,8)} };
    const std::string SpriteInMap[31] = { "","res\\model\\Axe.png","res\\model\\CG.png","res\\model\\BH.png","res\\model\\DR.png","res\\model\\CK.png",
                                               "res\\model\\MR.png","res\\model\\QoP.png","res\\model\\Jugg.png","res\\model\\TK.png","res\\model\\DS.png",
                                               "res\\model\\PA.png","res\\model\\TW.png","res\\model\\GG.png","res\\model\\GS.png","res\\model\\DK.png",
                                               "res\\model\\TA.png","res\\model\\DRK.png","res\\model\\GT.png","res\\model\\TH.png","res\\model\\COCO.png",
                                               "res\\model\\M1.png","res\\model\\M2.png","res\\model\\M3.png","res\\model\\M4.png","res\\model\\M5.png",
                                               "res\\model\\M6.png","res\\model\\M7.png","res\\model\\M8.png","res\\model\\M9.png","res\\model\\M10.png" };
    const std::string SpriteInShop[21] = { "","res\\shop\\Axe_SHOP.png","res\\shop\\CG_SHOP.png","res\\shop\\BH_SHOP.png","res\\shop\\DR_SHOP.png","res\\shop\\CK_SHOP.png",
                                             "res\\shop\\MR_SHOP.png","res\\shop\\QoP_SHOP.png","res\\shop\\Jugg_SHOP.png","res\\shop\\TK_SHOP.png","res\\shop\\DS_SHOP.png",
                                             "res\\shop\\PA_SHOP.png","res\\shop\\TW_SHOP.png","res\\shop\\GG_SHOP.png","res\\shop\\GS_SHOP.png","res\\shop\\DK_SHOP.png",
                                             "res\\shop\\TA_SHOP.png","res\\shop\\DRK_SHOP.png","res\\shop\\GT_SHOP.png","res\\shop\\TH_SHOP.png","res\\shop\\COCO_SHOP.png" };
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
    if (this == nullptr || targetChess == nullptr)
        return 0;

    //donghua

    this->ChessBase::attack(targetChess);

    if (targetChess->getHP() < 1e-3)
    {
        //死亡动画
        this->chessType = ChessType::noChess;
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
    chessType = chess.chessType;


    if (this->sprite != nullptr)
    {
        this->sprite->removeFromParent();
        this->sprite = nullptr;
    }
    if (this->chessType != noChess)
    {

        this->sprite = Sprite::create(ChessInitData::SpriteInMap[chessType]);
        //this->sprite->setOpacity(255);
        this->sprite->setScale(2);
    }

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


    return *this;
};


void ChessWithSprite::init(const int level)
{
    //数据初始化
    setMp(0);
    setRA(0);
    setMR(ChessInitData::MR[chessType]);
    setAR(ChessInitData::AR[chessType]);
    setPrice(ChessInitData::Price[chessType]);
    this->level = level;

    setHp(ChessInitData::Hp[chessType] * level);
    setAT(ChessInitData::AT[chessType] * level);
    //setAR(AR[chessType - 1]);

    this->player = 0;
    if (this->sprite != nullptr)
    {
        this->sprite->removeFromParent();
        this->sprite = nullptr;
    }
    if (this->chessType != noChess)
    {

        this->sprite = Sprite::create(ChessInitData::SpriteInMap[chessType]);
        this->sprite->setScale(2);
    }


}


void ChessWithSprite::initInShop(const int level)
{
    //数据初始化
    setMp(0);
    setRA(0);
    setMR(ChessInitData::MR[chessType]);
    setAR(ChessInitData::AR[chessType]);
    setPrice(ChessInitData::Price[chessType]);
    this->level = level;

    setHp(ChessInitData::Hp[chessType] * level);
    setAT(ChessInitData::AT[chessType] * level);
    //setAR(AR[chessType - 1]);

    this->player = 0;
    if (this->sprite != nullptr)
    {
        this->sprite->removeFromParent();
        this->sprite = nullptr;
    }
    if (this->chessType != noChess)
    {

        this->sprite = Sprite::create(ChessInitData::SpriteInShop[chessType]);
    }


}
