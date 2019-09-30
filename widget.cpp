#include "widget.h"
#include "ui_widget.h"
#include <QGraphicsScene>
#include <QPixmap>
#include "escena.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    on_reiniciar_clicked();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_reiniciar_clicked()
{
    Item::reiniciarJuego();
    escena = new Escena(this);
    QPen pen = QPen(Qt::black);
    pen.setWidth(3);
    //agregando marcos
    /*
    QLineF top(escena->sceneRect().topLeft(),escena->sceneRect().topRight());
    QLineF bottom(escena->sceneRect().bottomLeft(),escena->sceneRect().bottomRight());
    QLineF left(escena->sceneRect().topLeft(),escena->sceneRect().bottomLeft());
    QLineF right(escena->sceneRect().topRight(),escena->sceneRect().bottomRight());
    escena->addLine(top,pen);
    escena->addLine(bottom,pen);
    escena->addLine(left,pen);
    escena->addLine(right,pen);*/
    //agregando lineas 128,256, 384
    escena->addLine(128,0,128,384,pen);
    escena->addLine(256,0,256,384,pen);
    escena->addLine(0,128,384,128,pen);
    escena->addLine(0,256,384,256,pen);
    ui->graphicsView->setScene(escena);
}

void Widget::on_Jugar_clicked()
{
    on_reiniciar_clicked();
    ui->vistas->setCurrentIndex(1);
}

void Widget::on_salir_clicked()//Este es el boton menu
{
    ui->vistas->setCurrentIndex(0);
}

void Widget::on_quit_clicked()
{
    exit(0);
}
