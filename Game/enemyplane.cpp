#include "enemyplane.h"

enemyPlane::enemyPlane()
{

}

enemyPlane::enemyPlane(int x, int y, const QString &imageFile,
                       QGraphicsScene *scene, enemyType type, int life)
{
    this->type = type;
}

std::pair<int, int> enemyPlane::updatePosition() {
    return std::make_pair(x(), y()+2);
}

