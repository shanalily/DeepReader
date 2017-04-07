#include <poppler-qt5.h>
#include <QDebug>
#include <QLabel>
#include <QGraphicsScene>
#include <QFileDialog>
#include <QMessageBox>
#include "deepreader.h"
#include "ui_deepreader.h"

DeepReader::DeepReader(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DeepReader)
{
    ui->setupUi(this);
    pageCounter = 0;
    zoom = 0;
}

DeepReader::~DeepReader()
{
    delete ui;
}

void DeepReader::showPage() {
    ui->lineEdit->setText(QString::number(pageCounter));
    // find poppler page
    Poppler::Page *pdfpage = doc->page(pageCounter);
    if (pdfpage == 0) {
        qDebug() << "you chose page 0, pick again";
    }

    // find dimensions of page
    QSizeF dim = pdfpage->pageSizeF();

    // make page into image
    // we need to figure out page dimensions and zoom
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

void DeepReader::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,
         tr("Open Image"), "", tr("PDF Files (*.pdf)"));
    doc = Poppler::Document::load(filename);
    if (!doc || doc->isLocked()) {
        qDebug() << "doc variable is null or locked";
        delete doc;
    }
    pageCounter = 0;
    qDebug() << (doc == NULL);
    showPage();
}

void DeepReader::on_previous_clicked()
{
    --pageCounter;
    showPage();
}

void DeepReader::on_next_clicked()
{
    ++pageCounter;
    showPage();
}

void DeepReader::on_lineEdit_returnPressed()
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

void DeepReader::on_actionSave_As_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save File"), tr("Text files (*.txt)"));

    if (filename != "") {
        QFile file(filename);
        if (file.open(QIODevice::ReadWrite)) {
            QTextStream stream(&file);
            stream << ui->textEditor->toPlainText();
            file.flush();
            file.close();
        }
        else {
            QMessageBox::critical(this, tr("Error"), tr("Could not save file"));
            return;
        }
    }
}
