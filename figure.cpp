#include "figure.h"
#include <QPainter>

figure::figure(QPointF point, QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    this->setStartPoint(mapFromScene(point));
    this->setEndPoint(mapFromScene(point));
    connect(this, &figure::pointChanged, this, &figure::updateRomb);
}

figure::~figure()
{

}

QRectF figure::boundingRect() const
{
    return QRectF((endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) - 5,
                  (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) - 5,
                  qAbs(endPoint().x() - startPoint().x()) + 10,
                  qAbs(endPoint().y() - startPoint().y()) + 10);
}

void figure::updateRomb()
{
    this->update((endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) - 5,
                 (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) - 5,
                 qAbs(endPoint().x() - startPoint().x()) + 10,
                 qAbs(endPoint().y() - startPoint().y()) + 10);
}

void figure::setStartPoint(const QPointF point)
{
    m_startPoint = mapFromScene(point);
    emit pointChanged();
}

void figure::setEndPoint(const QPointF point)
{
    m_endPoint = mapFromScene(point);
    emit pointChanged();
}

QPointF figure::startPoint() const
{
    return m_startPoint;
}

QPointF figure::endPoint() const
{
    return m_endPoint;
}
