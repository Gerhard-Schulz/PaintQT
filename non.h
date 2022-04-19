#ifndef NON_H
#define NON_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

/* Наследуемся от класса Figure,
                         * в котором реализован общий для всех фигур функционал
                         * */
class NON : public figure
{
    Q_OBJECT

public:
    explicit NON(QPointF point, QObject *parent = 0);
    ~NON();

private:
    // Для Ромба реализуем только саму отрисовку
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // NON_H
