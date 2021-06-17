#include"ChessBoard.h"


const positionOnMap FightBoard::findNextMove(const int xInBoard, const int yInBoard)
{
    auto AimPosition = findPossibleAttackAim(xInBoard, yInBoard);

    if (AimPosition == positionOnMap(-1, -1))
        return positionOnMap(xInBoard, yInBoard);

    if (1)
    {
        double EnemyDistance = fabs(yInBoard - AimPosition.y) < fabs(xInBoard - AimPosition.x) ? fabs(xInBoard - AimPosition.x) : fabs(yInBoard - AimPosition.y);
        log("%f", EnemyDistance);
        log("%f", chess[yInBoard][xInBoard].getRA());
        if (EnemyDistance <= chess[yInBoard][xInBoard].getRA())
        {
            return positionOnMap(xInBoard, yInBoard);
        }
    }

    if (1)
    {
        positionOnMap positionToReturn(xInBoard, yInBoard);
        double MinDistanceToEnemy = 110;
        for (int i = -1; i < 2; i++)
            for (int k = -1; k < 2; k++)
            {
                if (xInBoard + k < 0 || xInBoard + k>7 || yInBoard + i < 0 || yInBoard + i>7 || chess[yInBoard + i][xInBoard + k].getChessType() != ChessWithSprite::ChessType::noChess)
                    continue;

                double EnemyDistance = fabs(yInBoard + i - AimPosition.y) < fabs(xInBoard + k - AimPosition.x) ? fabs(xInBoard + k - AimPosition.x) : fabs(yInBoard + i - AimPosition.y);
                if (EnemyDistance < MinDistanceToEnemy)
                {
                    positionToReturn = positionOnMap(xInBoard + k, yInBoard + i);
                    MinDistanceToEnemy = EnemyDistance;
                }
            }
        return positionToReturn;
    }



}

//为某坐标上的棋子寻找最近的敌人的位置
const positionOnMap FightBoard::findPossibleAttackAim(const int xInBoard, const int yInBoard)
{
    positionOnMap toReturn(-1, -1);
    double distance = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int k = 0; k < 8; k++)
        {
            if (this->chess[i][k].getChessType() == ChessWithSprite::ChessType::noChess)
                continue;

            if (this->chess[i][k].getPlayer() != this->chess[yInBoard][xInBoard].getPlayer())
            {
                double dis = fabs(yInBoard - i) < fabs(xInBoard - k) ? fabs(xInBoard - k) : fabs(yInBoard - i);

                if (dis > distance)
                {
                    toReturn.x = k;
                    toReturn.y = i;
                    distance = dis;
                }
            }
        }
    }
    return toReturn;
}

