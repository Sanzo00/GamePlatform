#include "myplane.h"

myPlane::myPlane()
{

}

myPlane::myPlane(int x, int y, const QString &imageFile,
                 QGraphicsScene *scene, int life, int skill):
    Plane(x, y, imageFile, scene, life, ME)
{

}
