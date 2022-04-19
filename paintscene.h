#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QDebug>
#include "figure.h"

class paintscene : public QGraphicsScene
{
    Q_OBJECT
    Q_PROPERTY(int typeFigure
               READ typeFigure WRITE setTypeFigure
               NOTIFY typeFigureChanged)

//    Q_PROPERTY(int widthBrush
//               READ widthBrush WRITE setBrushWidth
//               NOTIFY widthBrushChanged)

public:
    explicit paintscene(QObject *parent = 0);
    ~paintscene();

    int typeFigure() const;
    void setTypeFigure(const int type);
//    int widthBrush() const;
//    void setBrushWidth(const int width);

    enum FigureTypes {
        SquareType,
        RombType,
        TriangleType,
        Triangle90Type,
        EllipseType,
        LineType,
        NON,
        Eraser
    };

//    enum BrushWidth {
//        One,
//        Three,
//        Five,
//        Seven,
//        Ten
//    };

signals:
    void typeFigureChanged();
//    void widthBrushChanged();

private:
    QPointF previousPoint;
    figure *tempFigure;
    int m_typeFigure;
//    int m_brushWidth;

private:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PAINTSCENE_H
