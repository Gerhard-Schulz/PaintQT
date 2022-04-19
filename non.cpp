#include "non.h"

NON::NON(QPointF point, QObject *parent) :
    figure(point,parent)
{
    Q_UNUSED(point)
}


NON::~NON()
{

}

//// Реализуем метод отрисовки
//void NON::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
//{
//    painter->setPen(QPen(Qt::black, 2));

//    QRectF Ellipse(event->scenePos().x() - 5,
//                      event->scenePos().y() - 5,
//                      10,
//                      10,
//                      QPen(Qt::NoPen),
//                      QBrush(Qt::black));
//    previousPoint = event->scenePos();


//    painter->drawEllipse(Ellipse);

//    Q_UNUSED(option)
//    Q_UNUSED(widget)
//}
