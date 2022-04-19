#include "paint.h"
#include "ui_paint.h"
#include "paintscene.h"

paint::paint(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::paint)
{
    ui->setupUi(this);
    scene = new paintscene();
    ui->gvPaint->setScene(scene);
    ui->gvPaint->setRenderHint(QPainter::Antialiasing);
    ui->gvPaint->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->gvPaint->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &paint::slotTimer);
    timer->start(100);
}

paint::~paint()
{
    delete ui;
}

void paint::slotTimer()
{
    timer->stop();
    scene->setSceneRect(0,0, ui->gvPaint->width() - 20, ui->gvPaint->height() - 20);
}

void paint::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QWidget::resizeEvent(event);
}

void paint::on_btnRomb_clicked()
{
    scene->setTypeFigure(paintscene::RombType);
}

void paint::on_btnSquare_clicked()
{
    scene->setTypeFigure(paintscene::SquareType);
}

void paint::on_btnTriangle_clicked()
{
    scene->setTypeFigure(paintscene::TriangleType);
}

void paint::on_btnEllips_clicked()
{
    scene->setTypeFigure(paintscene::EllipseType);
}

void paint::on_btnPen_clicked()
{
    scene->setTypeFigure(paintscene::NON);
}

void paint::on_btnEraser_clicked()
{
    scene->setTypeFigure(paintscene::Eraser);
}

void paint::on_btnLine_clicked()
{
    scene->setTypeFigure(paintscene::LineType);
}


//void paint::on_cbxSize_currentIndexChanged(int index)
//{
//    switch(ui->cbxSize->currentIndex())
//    {
//    case 0:
//        scene->setBrushWidth(paintscene::One);
//        break;
//    case 1:
//        scene->setBrushWidth(paintscene::Three);
//        break;
//    case 2:
//        scene->setBrushWidth(paintscene::Five);
//        break;
//    case 3:
//        scene->setBrushWidth(paintscene::Seven);
//        break;
//    case 4:
//        scene->setBrushWidth(paintscene::Ten);
//        break;
//    }
//}

