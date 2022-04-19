#include "paintscene.h"
#include "paint.h"
#include "paint.cpp"
#include "romb.h"
#include "triangle.h"
#include "square.h"
#include "ellipse.h"
#include "line.h"

paintscene::paintscene(QObject *parent) : QGraphicsScene(parent)
{

}

paintscene::~paintscene()
{

}


void paintscene::setTypeFigure(const int type)
{
    m_typeFigure = type;
}

int paintscene::typeFigure() const
{
    return m_typeFigure;
}

//void paintscene::setBrushWidth(const int width)
//{
//    m_typeFigure = width;
//}

//int paintscene::widthBrush() const
//{
//    return m_brushWidth;
//}

void paintscene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
//    int width = 0;
//    int height = 0;
//    switch (m_brushWidth)
//    {
//    default:
//        width = 1;
//        height = 1;
//        break;

//    case Three:
//        width = 3;
//        height = 3;
//        break;

//    case Five:
//        width = 5;
//        height = 5;
//        break;

//    case Seven:
//        width = 7;
//        height = 7;
//        break;

//    case Ten:
//        width = 10;
//        height = 10;
//        break;
//    }

    switch (m_typeFigure)
    {
    case SquareType:
    {
        Square *item = new Square(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        this->addItem(tempFigure);
        break;
    }

    case RombType:
    {
        Romb *item = new Romb(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        this->addItem(tempFigure);
        break;
    }

    case TriangleType:
    {
        Triangle *item = new Triangle(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        this->addItem(tempFigure);
        break;
    }

    case EllipseType:
    {
        Ellipse *item = new Ellipse(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        this->addItem(tempFigure);
        break;
    }

    case LineType:
    {
        line *item = new line(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        this->addItem(tempFigure);
        break;
    }

    case NON:
    {
        addEllipse(event->scenePos().x() - 3,
                   event->scenePos().y() - 3,
                   5,
                   5,
                   QPen(Qt::NoPen),
                   QBrush(Qt::black));
        previousPoint = event->scenePos();
    }

    case Eraser:
    {
        addEllipse(event->scenePos().x() - 3,
                   event->scenePos().y() - 3,
                   5,
                   5,
                   QPen(Qt::NoPen),
                   QBrush(Qt::white));
        previousPoint = event->scenePos();
    }
    }
}

void paintscene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
//    int width = 0;
//    switch (m_brushWidth)
//    {
//    default:
//        width = 1;
//        break;

//    case Three:
//        width = 3;
//        break;

//    case Five:
//        width = 5;
//        break;

//    case Seven:
//        width = 7;
//        break;

//    case Ten:
//        width = 10;
//        break;
//    }

    switch (m_typeFigure)
    {
    default:
    {
        tempFigure->setEndPoint(event->scenePos());
        this->update(QRectF(0,0,this->width(), this->height()));
        return;
    }
    case NON:
    {
        addLine(previousPoint.x(),
                previousPoint.y(),
                event->scenePos().x(),
                event->scenePos().y(),
                QPen(Qt::black,5,Qt::SolidLine,Qt::RoundCap));
        previousPoint = event->scenePos();
        return;
    }
    case Eraser:
    {
        addLine(previousPoint.x(),
                previousPoint.y(),
                event->scenePos().x(),
                event->scenePos().y(),
                QPen(Qt::white,5,Qt::SolidLine,Qt::RoundCap));
        previousPoint = event->scenePos();
        return;
    }
    }
}
