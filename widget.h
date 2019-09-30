#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "item.h"
#include "escena.h"
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    Escena *escena;

private slots:
    void on_reiniciar_clicked();

    void on_Jugar_clicked();

    void on_salir_clicked();

    void on_pushButton_clicked();

    void on_menu_clicked();

    void on_salir_2_clicked();

    void on_quit_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
