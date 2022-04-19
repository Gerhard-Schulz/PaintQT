#ifndef LINE_H
#define LINE_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class line : public figure
{
    Q_OBJECT

public:
    explicit line(QPointF point, QObject *parent = 0);
    ~line();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // LINE_H
