#include"Shop.h"
using namespace cocos2d;


Shop::Shop(Player* player)
{
    this->whoOpenThis = player;

    for (int i = 0; i < 5; i++)
    {
        int rate = random() % 100;
        //����ĳ������
        if (rate < 1)
        {
            ChessLibrary[i].setChessType(ChessWithSprite::ChessType::firstType);
            ChessLibrary[i].init();
        }
    }

    player->setShop(this);
    //����ui�Ͱ�ť
    //�����̵�Ĵ����
    this->setSprite(Sprite::create("ͼƬ��"));
    //���̵��зֱ���þ��飻
    for (int i = 0; i < 5; i++)
    {
        //�������Ӿ���
        auto chessSprite = this->ChessLibrary[0].getSprite();
        //��chessSprite��ʾ��ȥ
        chessSprite->setPosition(Vec2(i * 100, 200));

        //���ð�ť����һ����Ҫ�Ǿ��飬�����������ֻ࣬Ҫ�ܵ��ù������
        //��ʾ�����õ���¼����������this-��buychess��i��
         //����button����
        auto buyButton = Sprite::create("res\\shop\\BH_SHOP.png");

        //����btn��λ��
        buyButton->setPosition(Vec2(300, 200));

        this->getPlayer()->getPlayerBoard()->getBoardScene()->addChild(buyButton, 1);
        auto listener1 = EventListenerTouchOneByOne::create();
        listener1->setSwallowTouches(true);//�����¼���û�����������ε�������������ȡ�����¼�
        // trigger when you push down
        listener1->onTouchBegan = [=](Touch* touch, Event* event) {
            auto target = static_cast<Sprite*>(event->getCurrentTarget());

            Point pos = Director::getInstance()->convertToGL(touch->getLocationInView());

            /* �жϵ���������Ƿ��ھ���ķ�Χ�� */
            if (target->getBoundingBox().containsPoint(pos))
            {
                /* ���þ����͸����Ϊ100 */
                target->setOpacity(0);
                return true;
            }

            return false;
        };
        // trigger when you let up
        listener1->onTouchEnded = [](Touch* touch, Event* event) {
            // your code
            CCLOG("����ended");
        };
        /* ע������¼����󶨾���1 */
        this->getPlayer()->getPlayerBoard()->getBoardScene()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1, buyButton);

        //
        this->getSprite()->addChild(buyButton, 0, i + 5);



    }
    //���ùرհ�ť
    auto closeButton = Sprite::create("�ر�");
    this->getSprite()->addChild(closeButton, 0, -1);
    //�����¼����������closeShop����

}

void Shop::setSprite(Sprite* toSet)
{
    this->shopSprite = toSet;
}
bool Shop::buyChess(const int rank)
{

    if (rank < 0 || rank>4)
        return 0;
    if (this->whoOpenThis->getGold() < this->ChessLibrary[rank].getPrice())
        return 0;
    bool reseverIsFull = 1;
    for (int i = 0; i < 5; i++)
    {
        if (this->whoOpenThis->getReserve(i)->getChessType() == ChessWithSprite::ChessType::noChess)
        {

            reseverIsFull = 0;

            this->whoOpenThis->setGold(this->whoOpenThis->getGold() - this->ChessLibrary[rank].getPrice());
            this->ChessLibrary[rank].changeChessToOtherChess(this->whoOpenThis->getReserve(i));
            //ui

            //
            break;
        }
    }
    if (reseverIsFull)
        return 0;
    //�۳���ҽ��

    return 1;
}
void Shop::closeShop()
{
    this->whoOpenThis->getSprite()->removeAllChildren();
    this->whoOpenThis->setShop(nullptr);
    this->whoOpenThis = nullptr;
    //ui�ر��̵����
    //
    delete this;
}


Player* Shop::getPlayer()
{
    return this->whoOpenThis;
}
void Shop::setPlayer(Player* toSet)
{
    this->whoOpenThis = toSet;
}
