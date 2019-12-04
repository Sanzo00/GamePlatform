#include "plane.h"

Plane::Plane()
{

}

Plane::Plane(int x, int y, const std::string &imageFile,
             QGraphicsScene *scene, int life, enum warPart part):
    Object(part, imageFile)
{
    setPos(x, y);
    this->life = life;
    scene->addItem(this);
    update();
}

bool Plane::crash(QGraphicsScene *scene) {
    bool flag;
    if (life <= 0) flag = false;
    else if (--life <= 0) {
        delScreen(scene);
        flag = false;
    }else flag = true;
    return flag;
}
