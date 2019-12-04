#ifndef BULLET_H
#define BULLET_H

#include "object.h"
#include <QtWidgets>
#include <utility>
#include <fstream>
#include <iostream>
class Bullet : public Object
{
    friend class Control;
public:
    Bullet();
    Bullet(warPart part, int x, int y, const std::string &imageFile, const QPointF &dir, int power);
    std::pair<qreal, qreal> updatePOsition();
    bool hit(QGraphicsScene *scene);

private:
    QPointF dir;
    int power;
};

#endif // BULLET_H