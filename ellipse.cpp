#include "ellipse.h"
#include <QPainter>

Ellipse::Ellipse(QPointF point, QObject *parent) :
    figure(point,parent)
{
    Q_UNUSED(point)
}


Ellipse::~Ellipse()
{

}

void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 5));

    QRectF rect(endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x(),
                endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y(),
                qAbs(endPoint().x() - startPoint().x()),
                qAbs(endPoint().y() - startPoint().y()));

    painter->drawEllipse(rect);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
