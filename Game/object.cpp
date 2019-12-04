#include "object.h"

Object::Object()
{

}

Object::Object(warPart, const std::string &imageFile):
    QGraphicsPixmapItem(QPixmap(QString::fromStdString(imageFile))) {
    this->part = part;
}

Object::~Object(){

}

void Object::synScreen(QGraphicsScene *scene) {
    if (scene->items().contains(this)) return;
    scene->addItem(this);
    update();
}

void Object::delScreen(QGraphicsScene *scene) {
    scene->removeItem(this);
    update();
}
