#ifndef ESCENA_H
#define ESCENA_H
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include "item.h"

class Item;
class Escena:public QGraphicsScene{
public:
    Escena(QObject *padre = nullptr);
};

#endif // ESCENA_H
