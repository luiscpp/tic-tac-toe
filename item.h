#ifndef ITEM_H
#define ITEM_H
#include <QGraphicsItem>
#include <QPixmap>
#include <QPointF>
#include <QList>
#include <QSizeF>
#include <QGraphicsSceneMouseEvent>

class Escena;

class Item: public QGraphicsItem{
private:
    QPixmap imagen;
    bool seleccion;
    QSizeF tamanio;
    qint32 fila;
    qint32 columna;
public:
    Item(QPixmap imagen, QPointF punto);
    void setImagen(QPixmap);
    QPixmap getImagen();
    void setTamanio(QSizeF tamanio);
    QSizeF getTamanio();
    void setSeleccion(bool seleccion);
    bool getSeleccion();
    int getFila();
    void setFila(qint32 fila);
    int getColumna();
    void setColumna(qint32 columna);

    static void reiniciarJuego();
    static qint32 matriz[3][3];
    static QList<Item*> elementos;
    static void inicializarMatriz();
    static bool posicionValida(qint32 fila,qint32 columna);
    static bool jugador1;
    static bool jugador2;
    static qint32 movimientos;
    static QPointF puntoA;
    static QPointF puntoB;
    bool ticTacToe(qint32 valor);
    static Item* obtenerItem(qint32 fila, qint32 columna);
    static void inhabilitar();
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};
#endif // ITEM_H
