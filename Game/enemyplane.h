#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H
#include "plane.h"

enum enemyType{
    ORD,
    BOSS
};

class enemyPlane: protected Plane
{
    friend class Control;
public:
    enemyPlane();
    enemyPlane(int x, int y, const QString &imageFile,
               QGraphicsScene *scene, enemyType type, int life);
    std::pair<int, int> updatePosition();

protected:
    enemyType type;
};

#endif // ENEMYPLANE_H
