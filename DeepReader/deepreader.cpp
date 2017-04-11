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
    studySession = false;

    ui->search->setPlaceholderText("Search");
    ui->start_page->setPlaceholderText("Start Page");
    ui->end_page->setPlaceholderText("End page");
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

void DeepReader::pageText() {
    QString text = doc->page(pageCounter)->text(QRectF(0,0,1000,1000));
    qDebug() << text;
    // I should probably get rid of all the empty strings this makes
    words = text.split(" ");
    // for testing, should delete
    for (int i = 0; i < words.length(); ++i) {
        qDebug() << words[i];
    }
}

bool DeepReader::goodNotes() {
    // placeholder code before I think of a better way to judge
    // the quality of the notes
    QStringList notes = ui->textEditor->toPlainText().split(" ");
    qDebug() << notes;
    if (notes.length() > 10)
        return true;
    return false;
}

void DeepReader::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,
         tr("Open Document"), "", tr("PDF Files (*.pdf)"));
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
    // should study session end after last page?
    // i.e. endPage + 1, or after good notes have
    // been taken on that page
    if (studySession) {
        if (pageCounter >= endPage) {
            studySession == false;
            ++pageCounter;
            showPage();
        }
        else if (goodNotes()) {
            ++pageCounter;
            showPage();
        }
    } else {
        ++pageCounter;
        showPage();
    }
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

void DeepReader::on_actionOpen_Text_File_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,
         tr("Open File"), "", tr("Text Files (*.txt)"));
    QFile file(filename);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream ReadFile(&file);
    ui->textEditor->setPlainText(ReadFile.readAll());
}

void DeepReader::on_zoom_out_clicked()
{
    ui->textEditor->zoomOut(3);
}

void DeepReader::on_zoom_in_clicked()
{
    ui->textEditor->zoomIn(3);
}

void DeepReader::on_start_clicked()
{
    // now that studySession is true, it should be impossible
    // to move to the next page without meeting certain requirements
    // I will have to add conditions in other functions based on
    // whether studySession is true or not
    studySession = true;
    startPage = ui->start_page->text().toInt();
    endPage = ui->end_page->text().toInt();
    if (pageCounter != startPage) {
        pageCounter = startPage;
        showPage();
    }
    // I may want to make words a private variable and pageText() a
    // private function so that I don't have to copy over an entire
    // list every time. This depends on what I end up having to extract
    // text for
    pageText();
    qDebug() << goodNotes();
}
