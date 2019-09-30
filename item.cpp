#include "item.h"
#include <escena.h>
#include <QPainter>
#include <QPointF>
#include <QDebug>
#include <QList>
#include <QWidget>
#include <QMessageBox>
#include <QFont>
#include <QGraphicsTextItem>
Item::Item(QPixmap imagen, QPointF punto)
{
    this->imagen = imagen;
    this->setPos(punto);
    this->seleccion = false;
    this->tamanio = QSizeF(128.0,128.0);
    setAcceptedMouseButtons(Qt::LeftButton);
    //setEnabled(false);
    //setFlag(QGraphicsItem::ItemIsSelectable,false);
}

void Item::setImagen(QPixmap imagen){
    this->imagen = imagen;
}

QPixmap Item::getImagen(){
    return imagen;
}

void Item::setTamanio(QSizeF tamanio){
    this->tamanio = tamanio;
}

QSizeF Item::getTamanio(){
    return tamanio;
}

void Item::setSeleccion(bool seleccion){
    this->seleccion = seleccion;
}

bool Item::getSeleccion(){
    return seleccion;
}

int Item::getFila()
{
    return this->fila;
}

void Item::setFila(qint32 fila)
{
    this->fila = fila;
}

int Item::getColumna()
{
    return this->columna;
}

void Item::setColumna(qint32 columna)
{
    this->columna = columna;
}

void Item::reiniciarJuego()
{
    Item::inicializarMatriz();
    for(int i=0; i<Item::elementos.size();i++){
        elementos.at(i)->setImagen(QPixmap(""));
    }
    Item::elementos.clear();
    Item::jugador1 = true;
    Item::jugador2 = false;
    Item::movimientos = 0;
}

qint32 Item::matriz[3][3];//inicializar variables estáticas antes de utilizarlas
bool Item::jugador1 = true;
bool Item::jugador2 = false;
qint32 Item::movimientos = 0;
QPointF Item::puntoA = QPoint(0,0);
QPointF Item::puntoB = QPoint(0,0);
QList<Item*> Item::elementos;

void Item::inicializarMatriz()
{
    for(int i = 0; i<3 ;i++){
        for(int j = 0; j<3 ;j++){
            Item::matriz[i][j] = 0;
        }
    }
}

bool Item::posicionValida(qint32 fila, qint32 columna)
{
    if(Item::matriz[fila][columna] == 0){
        return true;
    }
    return false;
}

Item* Item::obtenerItem(qint32 fila, qint32 columna)
{
    for(int i=0; i<Item::elementos.size();i++){
        if(fila == elementos.at(i)->getFila() && columna == elementos.at(i)->getColumna()){
            return elementos.at(i);
        }
    }
    return nullptr;
}

void Item::inhabilitar()
{
    for(int i=0; i<Item::elementos.size();i++){
        elementos.at(i)->setEnabled(false);
    }
}

bool Item::ticTacToe(qint32 valor)
{
    qint32 contador;
    //Horizontales
    for(int i=0;i<3;i++){
        contador = 0;
        for(int j=0;j<3;j++){
            if(Item::matriz[i][j] == valor){
                Item *a = obtenerItem(i,j);
                contador++;
                if(contador == 1){
                    Item::puntoA = QPointF(a->pos().rx(),a->pos().ry()+(128/2));
                }else if(contador == 3){
                    Item::puntoB = QPointF(a->pos().rx()+128,a->pos().ry()+(128/2));
                }
            }
        }
        if(contador == 3){
            return true;
        }
    }
    //Verticales
    for(int i=0;i<3;i++){
        contador = 0;
        for(int j=0;j<3;j++){
            if(Item::matriz[j][i] == valor){
                Item *a = obtenerItem(j,i);
                contador++;
                if(contador == 1){
                    Item::puntoA = QPointF(a->pos().rx()+(128/2),a->pos().ry());
                }else if(contador == 3){
                    Item::puntoB = QPointF(a->pos().rx()+(128/2),a->pos().ry()+128);
                }
            }
        }
        if(contador == 3){
            return true;
        }
    }
    //Diagonal principal
    contador = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i == j){
                if(Item::matriz[i][j] == valor){
                    Item *a = obtenerItem(i,j);
                    contador++;
                    if(contador == 1){
                        Item::puntoA = QPointF(a->pos().rx(),a->pos().ry());
                    }else if(contador == 3){
                        Item::puntoB = QPointF(a->pos().rx()+128,a->pos().ry()+128);
                    }
                }
            }

        }
    }
    if(contador == 3){
        return true;
    }

    //Diagonal secundaria
    contador = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if((i+j) == 2){
                if(Item::matriz[i][j] == valor){
                    Item *a = obtenerItem(i,j);
                    contador++;
                    if(contador == 1){
                        Item::puntoA = QPointF(a->pos().rx()+128,a->pos().ry());
                    }else if(contador == 3){
                        Item::puntoB = QPointF(a->pos().rx(),a->pos().ry()+128);
                    }
                }
            }

        }
    }
    if(contador == 3){
        return true;
    }

    return false;
}

QRectF Item::boundingRect() const{
    return QRectF(QPointF(0,0),tamanio);
}

void Item::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->drawPixmap(0,0,this->tamanio.width(),tamanio.height(),imagen);
    scene()->update();
}

void Item::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(Item::posicionValida(getFila(),getColumna())){
        if(Item::jugador1){
            // !Item::ticTacToe(matriz[getFila()][getColumna()])
            Item::matriz[getFila()][getColumna()] = 1;
            Item::jugador1 = false;
            Item::jugador2 = true;
            setImagen(QPixmap(":/imagenes/x.png"));
            Item::movimientos++;
        }else{
            Item::matriz[getFila()][getColumna()] = 2;
            Item::jugador1 = true;
            Item::jugador2 = false;
            setImagen(QPixmap(":/imagenes/o.png"));
            Item::movimientos++;
        }
        if(ticTacToe(matriz[getFila()][getColumna()])){
            QPen pen = QPen(Qt::blue);
            pen.setWidth(3);
            pen.setColor(Qt::red);
            scene()->addLine(Item::puntoA.rx(),Item::puntoA.ry(),Item::puntoB.rx(),Item::puntoB.ry(),pen);
            Item::inhabilitar();
            QFont tam;
            tam.setPointSize(35);
            if(!Item::jugador1){
                QGraphicsTextItem *texto = scene()->addText("Ganan las X",tam);
                texto->setDefaultTextColor(QColor(61,33,104));
                texto->setPos(60,155);
            }else{
                QGraphicsTextItem *texto = scene()->addText("Ganan las O",tam);
                texto->setDefaultTextColor(QColor(61,33,104));
                texto->setPos(60,155);
            }
        }else if(Item::movimientos > 8 ){
            QFont tam;
            tam.setPointSize(35);
            QGraphicsTextItem *texto = scene()->addText("Empate",tam);
            texto->setDefaultTextColor(QColor(61,33,104));
            texto->setPos(105,155);
        }
    }

}
