#ifndef PLANE_H
#define PLANE_H
#include "bullet.h"
#include "object.h"
#include <QtWidgets>
#include <string>
#include <vector>

class Plane : public Object
{
    friend class Control;
public:
    Plane();
    Plane(int x, int y, const std::string &imageFile,
          QGraphicsScene *scene, int life, enum warPart part);
    // 飞机碰撞
    bool crash(QGraphicsScene *scene);

protected:
    int life;
};

#endif // PLANE_H
