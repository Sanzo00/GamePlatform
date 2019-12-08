#include "myplane.h"

MyPlane::MyPlane()
{

}

MyPlane::MyPlane(int x, int y, const QString &imageFile,
                 QGraphicsScene *scene, int life, int skill):
    Plane(x, y, imageFile, scene, life, ME)
{

}
