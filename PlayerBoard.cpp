#include"PlayerBoard.h"


//////////////////////////////////////////////////////////////////////////////////////////////////

myMenu* PlayerBoard::getBoardScene()
{
    return this->boardScene;
}
void PlayerBoard::setBoardScene(myMenu* toSet)
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
