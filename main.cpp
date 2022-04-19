#include "paint.h"

#include <QMainWindow>
#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    paint w;
    w.show();
    return a.exec();
}
