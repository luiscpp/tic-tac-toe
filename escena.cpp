#include "escena.h"
#define XPOS 0.0
#define YPOS 0.0
#define WIDTH 384.0
#define HEIGHT 384.0

Escena::Escena(QObject *padre): QGraphicsScene(XPOS, YPOS, WIDTH, HEIGHT, padre){
    Item *i = new Item(QPixmap(""),QPointF(0,0));
    i->setFila(0);
    i->setColumna(0);
    addItem(i);
    Item::elementos.append(i);
    Item *i2 = new Item(QPixmap(""),QPointF(128,0));
    i2->setFila(0);
    i2->setColumna(1);
    addItem(i2);
    Item::elementos.append(i2);
    Item *i3 = new Item(QPixmap(""),QPointF(256,0));
    i3->setFila(0);
    i3->setColumna(2);
    addItem(i3);
    Item::elementos.append(i3);
    Item *i4 = new Item(QPixmap(""),QPointF(0,128));
    i4->setFila(1);
    i4->setColumna(0);
    addItem(i4);
    Item::elementos.append(i4);
    Item *i5 = new Item(QPixmap(""),QPointF(128,128));
    i5->setFila(1);
    i5->setColumna(1);
    addItem(i5);
    Item::elementos.append(i5);
    Item *i6 = new Item(QPixmap(""),QPointF(256,128));
    i6->setFila(1);
    i6->setColumna(2);
    addItem(i6);
    Item::elementos.append(i6);
    Item *i7 = new Item(QPixmap(""),QPointF(0,256));
    i7->setFila(2);
    i7->setColumna(0);
    addItem(i7);
    Item::elementos.append(i7);
    Item *i8 = new Item(QPixmap(""),QPointF(128,256));
    i8->setFila(2);
    i8->setColumna(1);
    addItem(i8);
    Item::elementos.append(i8);
    Item *i9 = new Item(QPixmap(""),QPointF(256,256));
    i9->setFila(2);
    i9->setColumna(2);
    addItem(i9);
    Item::elementos.append(i9);
}
