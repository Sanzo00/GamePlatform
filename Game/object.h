#ifndef OBJECT_H
#define OBJECT_H

#include <QtWidgets>
#include <string>
enum warPart{
    ME,
    ENEMY,
    LIFESUPPLY
};

class Object : public QGraphicsPixmapItem
{
public:
    Object();
    Object(warPart part, const QString &inmageFile);
    ~Object();
    void synScreen(QGraphicsScene *scene);
    void delScreen(QGraphicsScene *scene);

protected:
    enum warPart part;
};

#endif // OBJECT_H
