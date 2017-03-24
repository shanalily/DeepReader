#include <poppler-qt5.h>
#include <QDebug>
#include <QLabel>
#include <QGraphicsScene>
#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pageCounter = 0;
    zoom = 0;

    // load pdf into document pointer
    QString filename = "/home/main/Documents/FOCS.pdf";
    doc = Poppler::Document::load(filename);
    if (!doc || doc->isLocked()) {
        qDebug() << "doc variable is null or locked";
        delete doc;
    }
    qDebug() << (doc == NULL);

    showPage();

    // testing whether I can read text from a pdf
    QString text = doc->page(300)->text(QRectF(0,0,1000,1000));
    qDebug() << text;

    // attempts to show the index for textbooks that have them
    // QDomNode protected?
    //
    // if (doc != NULL && doc->toc() != NULL && doc->toc()->documentElement() != NULL) {
    //     QDomElement docElem = doc->toc()->documentElement();
    // }

    // figure out how to change path for file manager depending on operating system

    #ifdef W_OS_LINUX
        qDebug() << "Linux version";
    #elif defined(W_OS_CYGWIN)
        qDebug() << "Cygwin version";
    #else
//    #error "We don't support that version yet...";
        qDebug() << "We don't support that version yet...";
    #endif
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showPage() {
    ui->lineEdit->setText(QString::number(pageCounter));
    // find poppler page
    Poppler::Page *pdfpage = doc->page(pageCounter);
    if (pdfpage == 0) {
        qDebug() << "you chose page 0, pick again";
    }

    // find dimensions of page
    QSizeF dim = pdfpage->pageSizeF();

    // make page into image
    QImage image = pdfpage->renderToImage(60+zoom,60+zoom, 0,0, dim.rwidth()+zoom,dim.rheight()+zoom);
    // QImage image = pdfpage->renderToImage(10*physicalDpiX(), 10*physicalDpiY());
    if (image.isNull()) {
        qDebug() << "image is null";
    }

    // display image
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->addPixmap(QPixmap::fromImage(image));
    scene->setSceneRect(QPixmap::fromImage(image).rect());
    ui->mainImage->setScene(scene);
}

// next page
void MainWindow::on_pushButton_clicked()
{
    ++pageCounter;
    showPage();
}

// previous page
void MainWindow::on_pushButton_2_clicked()
{
    --pageCounter;
    showPage();
}

// jump to page
void MainWindow::on_lineEdit_returnPressed()
{
    QString text = ui->lineEdit->text();
    if(text.toInt() != NULL) {
        pageCounter = text.toInt();
        showPage();
    } else {
        qDebug() << "string entered was not a number";
    }
    qDebug() << text;
}

// choose pdf to view
void MainWindow::on_actionOpen_File_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,
         tr("Open Image"), "/home/main", tr("PDF Files (*.pdf)"));
    doc = Poppler::Document::load(filename);
    if (!doc || doc->isLocked()) {
        qDebug() << "doc variable is null or locked";
        delete doc;
    }
    pageCounter = 0;
    qDebug() << (doc == NULL);
    showPage();
}

// zoom in
void MainWindow::on_pushButton_3_clicked()
{
    zoom += 10;
    showPage();
}

// zoom out
void MainWindow::on_pushButton_4_clicked()
{
    zoom -= 10;
    showPage();
}
