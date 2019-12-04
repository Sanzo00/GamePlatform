#include "bullet.h"

Bullet::Bullet()
{

}

Bullet::Bullet(warPart part, int x, int y, const std::string &imageFile, const QPointF &dir, int power):
    Object(part, imageFile)
{
    setPos(x, y);
    this->dir = dir;
    this->power = power;
}

std::pair<qreal, qreal> Bullet::updatePOsition() {
    return std::make_pair(x() + dir.x(), y()+dir.y());
}

bool Bullet::hit(QGraphicsScene *scene) {
    bool flag;
    if (power <= 0) flag = false;
    else if (--power <= 0) {
        delScreen(scene);
        flag = false;
    }else flag = false;
    return flag;
}
