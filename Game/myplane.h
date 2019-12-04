#ifndef MYPLANE_H
#define MYPLANE_H
#include "plane.h"

class myPlane: protected Plane
{
    friend class Control;
public:
    myPlane();
    myPlane(int x, int y, const std::string &imageFile,
            QGraphicsScene *scene, int life, int skill);

private:
    int skill;
};

#endif // MYPLANE_H
