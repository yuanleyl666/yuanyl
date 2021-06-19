#include"PlayerBoard.h"
using namespace cocos2d;

//////////////////////////////////////////////////////////////////////////////////////////////////

Scene* PlayerBoard::getBoardScene()
{
    return this->boardScene;
}
void PlayerBoard::setBoardScene(Scene* toSet)
{
    this->boardScene = toSet;
}
Player* PlayerBoard::getPlayer()
{
    return this->player;
}
void PlayerBoard::setPlayer(Player* toSet)
{
    this->player = toSet;
}
bool PlayerBoard::setChess(const int& row, const int& column, ChessWithSprite* chess)
{
    ChessBoard::setChess(row, column, chess);
    this->chess[row][column].setPlayer(this->player->getPlayerRank());
    return 1;
}
PlayerBoard::PlayerBoard()
{

    //这里需要重新设定scene
    //
    //设置事件读取

}
