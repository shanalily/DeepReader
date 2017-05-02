#include "deepreader.h"
#include <QApplication>
#include <QDebug>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QtWidgets>
#include <poppler-qt5.h>
#include <cstdio>
#include <ctime>
#include <QLabel>
#include <QTimer>
#include <QPaintDevice> // do I need this or anything else though

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DeepReader w;

    w.show();

    return a.exec();
}
