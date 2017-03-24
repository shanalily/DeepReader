#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QtWidgets>
#include <poppler-qt5.h>
#include <QLabel>
#include <QPaintDevice>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
