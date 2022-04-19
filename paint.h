#ifndef PAINT_H
#define PAINT_H

#include <QMainWindow>
#include <QTimer>
#include <QResizeEvent>
#include <QObject>
#include "paintscene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class paint; }
QT_END_NAMESPACE

class paint : public QMainWindow
{
    Q_OBJECT

public:
    paint(QWidget *parent = nullptr);
    ~paint();

private:
    Ui::paint *ui;
    QTimer *timer;
    paintscene *scene;

private:
    void resizeEvent(QResizeEvent * event);

private slots:
    void slotTimer();
    void on_btnSquare_clicked();
    void on_btnRomb_clicked();
    void on_btnTriangle_clicked();
    void on_btnEllips_clicked();
    void on_btnPen_clicked();
    void on_btnEraser_clicked();
    void on_btnLine_clicked();
    void on_cbxSize_currentIndexChanged(int index);
};
#endif // PAINT_H
