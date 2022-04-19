#include "line.h"
#include <QPainter>

line::line(QPointF point, QObject *parent) :
    figure(point,parent)
{
    Q_UNUSED(point)
}


line::~line()
{

}

void line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 5));

    QLineF line (endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x(),
                 endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y(),
                 qAbs(endPoint().x() - startPoint().x()),
                 qAbs(endPoint().y() - startPoint().y()));


    painter->drawLine(line);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

