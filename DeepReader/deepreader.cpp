#include <poppler-qt5.h>
#include <QDebug>
#include <QLabel>
#include <QGraphicsScene>
#include <QFileDialog>
#include <QMessageBox>
#include <QShortcut>
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
    previousText = 0;

    ui->search->setPlaceholderText("Search");
    ui->start_page->setPlaceholderText("Start Page");
    ui->end_page->setPlaceholderText("End page");

//    this->setStyleSheet("background-color: #0099cc");

    QShortcut *right = new QShortcut(QKeySequence(Qt::Key_Right), this, SLOT(on_next_clicked()));
    QShortcut *left = new QShortcut(QKeySequence(Qt::Key_Left), this, SLOT(on_previous_clicked()));
    // for when zoom is implemented
//    QShortcut *in = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Plus), this, SLOT(on_previous_clicked()));
//    QShortcut *out = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Minus), this, SLOT(on_previous_clicked()));


    /* Start of PDF Zoom implementation (not finished or tested yet)

    double width, height;

    curr_page = poppler_document_get_page(ui, 0);

    poppler_page_get_size(curr_page, &width, &height);
    //need to figure out how scroll bar is drawn in our implementation
    gtk_widget_set_size_request(viewer.drawingarea, (int)width, (int)height);
    update_statusbar();

    */
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
    words = text.split(QRegExp("\\s+"));
    for (int i = 0; i < words.length(); ++i) {
        qDebug() << words[i];
    }
}

bool relevantNotes(QStringList words, QStringList notes, int previousLength){
    // Used set to increase efficiency
    QSet<QString> HundredMostCommonWords({"the","be","to","of","and","a","in","that","have","I","it","for",
            "not","on","with","he","as","you","do","at","this","but","his","by","from","they","we","say",
            "her","she","or","an","will","my","one","all","would","there","their","what","so","up","out",
            "if","about","who","get","which","go","me","when","make","can","like","time","no","just","him",
            "know","take","people","into","year","your","good","some","could","them","see","other","than",
            "then","now","look","only","come","its","over","think","also","back","after","use","two","how",
            "our","work","first","well","way","even","new","want","because","any","these","give","day",
            "most","us"});
    //https://en.wikipedia.org/wiki/Most_common_words_in_English
    QStringList Qwords = QStringList(words); //new QStringList with elements the same as words
    Qwords.removeDuplicates();
    for (int i = 0; i < words.size(); i++){
        if(HundredMostCommonWords.contains(words.at(i) ) ){
            Qwords.removeAt(i);
        }
    }

    // Qwords now contains words minus the common words

    int counter = 0;
    for (int i=previousLength; i < notes.size();i++){
        if (HundredMostCommonWords.contains(notes.at(i) ) ){
            continue;
        }
        if (Qwords.contains(notes.at(i) ) ){
            counter++;
        }
    }
    int weightFactor = 4;
    if (counter*weightFactor > Qwords.size() ){
        return true;
    }
    return false;
 }

bool DeepReader::goodNotes() {
    // I should probably think of a way to read only the notes written
    // since the page was "turned"
    if (words.length() < 20) {
        // there's very little text on the page. Go to the next page.
        return true;
    }
    int minWordNum = words.length() * 0.05;
    qDebug() << words.length();
    qDebug() << minWordNum;
    QStringList notes = ui->textEditor->toPlainText().split(QRegExp("[,;.]\\s+"));
    qDebug() << notes;

    if ((notes.length() - previousText) > minWordNum && relevantNotes(notes, words, previousText) ){
        previousText = notes.length();
        qDebug() << "notes length: " << notes.length() << " notes from current page: " << notes.length() - previousText;
        return true;
    }

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
    if (pageCounter < 0)
        pageCounter = 0;
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
            if (pageCounter >= doc->numPages())
                pageCounter = doc->numPages() - 1;
            showPage();
        }
    } else {
        ++pageCounter;
        if (pageCounter >= doc->numPages())
            pageCounter = doc->numPages() - 1;
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

void DeepReader::change_font_size() {

}

void DeepReader::on_zoom_out_clicked()
{
    ui->textEditor->zoomOut(3);
    /* Start of PDF Zoom implementation (not finished or tested yet)

    curr_page = poppler_document_get_page(ui, 0);

    poppler_page_get_size(ui, &width, &height);
    gtk_widget_set_size_request(viewer.drawingarea, (int)(width-3), (int)(height-3));
    update_statusbar();

    */
}

void DeepReader::on_zoom_in_clicked()
{
    ui->textEditor->zoomIn(3);
    /* Start of PDF Zoom implementation (not finished or tested yet)

    double width, height;

    curr_page = poppler_document_get_page(ui, 0);

    poppler_page_get_size(curr_page, &width, &height);
    gtk_widget_set_size_request(viewer.drawingarea, (int)(width+3), (int)(height+3));
    update_statusbar();

    */
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
