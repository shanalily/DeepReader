#include <poppler-qt5.h>
#include <QInputDialog>
#include <QDebug>
#include <QLabel>
#include <QGraphicsScene>
#include <QFileDialog>
#include <QMessageBox>
#include <QShortcut>
#include <QTextEdit>
#include <cstdio>
#include <ctime>
#include <QTimer>
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
    previousText = 0; // I should probably set this when I open a document, and reset it at points
    doc = NULL;

    ui->search->setPlaceholderText("Search");
    ui->start_page->setPlaceholderText("Start Page");
    ui->end_page->setPlaceholderText("End page");

    QShortcut *right = new QShortcut(QKeySequence(Qt::Key_Right), this, SLOT(on_next_clicked()));
    QShortcut *left = new QShortcut(QKeySequence(Qt::Key_Left), this, SLOT(on_previous_clicked()));
    // for when zoom is implemented
    QShortcut *in = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Plus), this, SLOT(on_zoom_in_pdf_clicked()));
    QShortcut *out = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Minus), this, SLOT(on_zoom_out_pdf_clicked()));

    //QShortcut *bullet = new QShortcut(QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_L), this, SLOT(on_action_Bullet_List_triggered()));

    // for text editor
    // QShortcut *text_zoom_in = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Plus), this, SLOT(on_zoom_in_clicked())); // zoom in doesn't work
    // QShortcut *text_zoom_out = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Minus), this, SLOT(on_zoom_out_clicked())); // does work

    ui->timer->hide();
    ui->word_count->hide();
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
    // QImage image = pdfpage->renderToImage(60+zoom,60+zoom, 0,0, dim.rwidth()+zoom,dim.rheight()+zoom);
    image = pdfpage->renderToImage(72.0 + zoom,72.0 + zoom);
    // args to renderToImage: double xres=72.0, double yres=72.0, int x=-1, int y=-1, int w=-1, int h=-1, Rotation rotate=Rotate0
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
    words = text.split(QRegExp("[:;.,]*\\s+"));
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

        // If the word in notes is within the common words, continue the loop
        if (HundredMostCommonWords.contains(notes.at(i) ) ){
            continue;
        }
        // If the word in notes is within the "important" words (Qwords), ++ the counter
        if (Qwords.contains(notes.at(i) ) ){
            counter++;
        }
    }

    // Defining a arbitrary weightFactor to determine if there are enough relevant words
    int weightFactor = 4;
    if (counter*weightFactor >= Qwords.size() ){
        return true;
    }

    else {
        qDebug() << "Relevant Word check failed";
        qDebug() << "# of relevant words in notes: " << counter;
        qDebug() << "# of relevant words " << Qwords.size();
        return false;
    }
 }
/*

int relevantNotesCounter(QStringList words, QStringList notes, int previousLength){
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
        
        // If the word in notes is within the common words, continue the loop
        if (HundredMostCommonWords.contains(notes.at(i) ) ){
            continue;
        }
        // If the word in notes is within the "important" words (Qwords), ++ the counter
        if (Qwords.contains(notes.at(i) ) ){
            counter++;
        }
    }
    
    // Defining a arbitrary weightFactor to determine if there are enough relevant words
    int weightFactor = 4;
    if (counter*weightFactor >= Qwords.size() ){
        return 0;
    }
    return Qwords.size() - (counter*weightFactor);
}

int goodNotesCounter(QStringList words, QStringList notes, int previousText) {
    
    float weightFactor = 0.05;
    int minWordNum = words.length() * weightFactor;

    // If no more nots are needed, return 0
    if ((notes.length() - previousText) > minWordNum ){
        return 0;
    }
    
    // Otherwise return the number of words more you need to write
    return minWordNum - (notes.length() - previousText);
}
 
 void DeepReader::updateCounter() {
    QStringList notes = ui->texteditor->toPlainText().split(QRegExp("[,;.]*\\s+"));
    // double secondsPassed = (clock() - startTime) / CLOCKS_PER_SEC;
    int gNC = goodNotesCounter(words, notes, previousText);
    int rNC = relevantNotesCounter(words, notes, previousText);
    ui->word_count.setText(gNC);
 }
 
*/



bool DeepReader::goodNotes() {
    // I should probably think of a way to read only the notes written
    // since the page was "turned"
    int minLength = 20;
    if (words.length() < minLength) {
        // there's very little text on the page. Go to the next page.
        return true;
    }
    // maybe have this as default, but figure out way for user to set this
    float weightFactor = 0.05;
    int minWordNum = words.length() * weightFactor;
    qDebug() << "words.length(): " << words.length();
    qDebug() << "minWordNum: " << minWordNum;
    QStringList notes = ui->texteditor->toPlainText().split(QRegExp("[,;.]*\\s+"));
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
    if (filename.contains(".pdf")) { // could I do this in a less trivial way?
        doc = Poppler::Document::load(filename);
        if (!doc || doc->isLocked()) {
            qDebug() << "doc variable is null or locked";
            delete doc;
        }
        pageCounter = 0;
        qDebug() << (doc == NULL);
        showPage();
    }
}

void DeepReader::on_previous_clicked()
{
    if (doc != NULL) {
        --pageCounter;
        if (pageCounter < 0)
            pageCounter = 0;
        showPage();
    }
}

void DeepReader::on_next_clicked()
{
    // should study session end after last page?
    // i.e. endPage + 1, or after good notes have
    // been taken on that page
    if (doc != NULL) {
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
}

void DeepReader::on_lineEdit_returnPressed()
{
    if (doc != NULL) {
        QString text = ui->lineEdit->text();
        if(text.toInt() != NULL) {
            if (text.toInt() < doc->numPages()) {
                pageCounter = text.toInt();
                showPage();
            }
        } else {
            qDebug() << "string entered was not a number";
        }
        qDebug() << text;
    }
}

void DeepReader::on_actionSave_As_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save File"), tr("Text files (*.txt)"));

    if (filename != "") {
        QFile file(filename);
        if (file.open(QIODevice::ReadWrite)) {
            QTextStream stream(&file);
            stream << ui->texteditor->toHtml();
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
         tr("Open File"), "", tr("Text Files (*.txt *.rtf)"));
    QFile file(filename);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream ReadFile(&file);
    if (filename.contains(".rtf")) {
        ui->texteditor->setHtml(ReadFile.readAll());
        previousText = ui->texteditor->toHtml().split(QRegExp("[\n]*\\s")).size();
    } else if (filename.contains(".txt")) {
        ui->texteditor->setPlainText(ReadFile.readAll());
        previousText = ui->texteditor->toPlainText().split(QRegExp("[\n]*\\s")).size();
    }
}

// Undoes the last operation
void DeepReader::on_actionUndo_triggered() {
    ui->texteditor->undo();
}

// Redoes the last operation
void DeepReader::on_actionRedo_triggered() {
    ui->texteditor->redo();
}

// Copies the selected text to the clipboard and deletes it from the file
void DeepReader::on_actionCut_triggered() {
    ui->texteditor->cut();
}

// Copies the selected text to the clipboard
void DeepReader::on_actionCopy_triggered() {
    ui->texteditor->copy();
}

// Pastes the text from the clipboard at the current cursor position
void DeepReader::on_actionPaste_triggered() {
    ui->texteditor->paste();
}

// Selects all text in the file
void DeepReader::on_actionSelect_All_triggered() {
    ui->texteditor->selectAll();
}

/*
// Insert bullet point
void DeepReader::on_actionBullet_List_triggered() {
    ui->texteditor->insertHtml("<ul type='disc'><li></li></ul>");
}
*/

// Bold or unbold
void DeepReader::on_bold_clicked() {
    // Current font weight
    int bold = ui->texteditor->fontWeight();

    // If current weight is normal, set to bold
    if(bold == 50) {
        ui->texteditor->setFontWeight(75);
    }
    // Else if current weight is bold, set to normal
    else if(bold == 75) {
        ui->texteditor->setFontWeight(50);
    }
    // Else there is an improper font weight
    else {
        QMessageBox::critical(this, tr("Error"), tr("Improper font weight"));
        return;
    }
}

// Italicize or unitalicize
void DeepReader::on_italic_clicked() {
    bool italic = ui->texteditor->fontItalic();
    ui->texteditor->setFontItalic(!italic);
}

// Underline or Un-underline
void DeepReader::on_underline_clicked() {
    bool underline = ui->texteditor->fontUnderline();
    ui->texteditor->setFontUnderline(!underline);
}

// Change font
void DeepReader::on_font_currentFontChanged() {
    QFont font = ui->font->currentFont();
    ui->texteditor->setCurrentFont(font);
}

// Change font size
void DeepReader::on_font_size_valueChanged() {
    int size = ui->font_size->value();
    ui->texteditor->setFontPointSize(size);
}

// Set alginment to the left
void DeepReader::on_alignleft_clicked() {
    ui->texteditor->setAlignment(Qt::AlignLeft);
}

// Set alignment to the center
void DeepReader::on_aligncenter_clicked() {
    ui->texteditor->setAlignment(Qt::AlignCenter);
}

// Set alignment to the left
void DeepReader::on_alignright_clicked() {
    ui->texteditor->setAlignment(Qt::AlignRight);
}

// Set alignment to justified
void DeepReader::on_alignjustify_clicked() {
    ui->texteditor->setAlignment(Qt::AlignJustify);
}

// text editor zoom-out
void DeepReader::on_zoom_out_clicked()
{
    ui->texteditor->zoomOut(3);
}

// text editor zoom-in
void DeepReader::on_zoom_in_clicked()
{
    ui->texteditor->zoomIn(3);
}

// I need to fix previousText variable so that if I go back a page, it doesn't use the
// current previousText value, meaning that I have to type additional notes
void DeepReader::on_start_clicked()
{
    // now that studySession is true, it should be impossible
    // to move to the next page without meeting certain requirements
    // I will have to add conditions in other functions based on
    // whether studySession is true or not
    if (doc != NULL) {
        startPage = ui->start_page->text().toInt();
        endPage = ui->end_page->text().toInt();
        // instead set endPage to doc->numPages()?
        if (endPage < doc->numPages() && startPage < endPage) {
            studySession = true;
            if (pageCounter != startPage) {
                pageCounter = startPage;
                showPage();
            }
            pageText();
            qDebug() << goodNotes();
        }
    }
}

// pdf viewer zoom-out
void DeepReader::on_zoom_out_pdf_clicked()
{
    if (doc != NULL) {
        zoom -= 10;
        showPage();
    }
}

// pdf viewer zoom-in
void DeepReader::on_zoom_in_pdf_clicked()
{
    if (doc != NULL) {
        zoom += 10;
        showPage();
    }
}

// checks if time is up and displays message that time is up
void DeepReader::checkTime() {
    double secondsPassed = (clock() - startTime) / CLOCKS_PER_SEC;
//    ui->timer->show();
//    ui->timer->setText(QString::number(secondsPassed));
    /*
    double secondsPassedUpdate = secondsPassed;
    if(secondsPassedUpdate >= 5){
        double secondsPassedUpdate -= secondsPassed;
        updateCounter();
    }
    */
    if(secondsPassed >= timeDuration){
        //TO DO: display that time is up (need to figure out where we want to display time up)
    }
}

// find word
void DeepReader::on_search_returnPressed()
{
    // I need a way to go through pages
    // I could store current word as variable, and when enter is pressed again and it's
    // the same word, just go to the next page in the pages array
    // search args : const QString &text, SearchFlags flags = 0, Rotation rotate = 0
    if (doc != NULL && !studySession) {
        QString word = ui->search->text();
        QList<QList<QRectF> > locs;
        QList<int> pages; // pages on which the word is found
        for (int i = 0; i < doc->numPages(); ++i) {
            QList<QRectF> loc = doc->page(i)->search(word);
            locs.append(loc);
            // change color in image variable at loc
            if (!loc.empty()) {
                pages.append(i);
                qDebug() << i;
            }
        }
        if (!pages.empty()) {
            pageCounter = pages[0];
            showPage();
            for (int i = 0; i < locs[0].size(); ++i) {
                // testing
                qDebug() << locs[0][i].x();
                qDebug() << locs[0][i].y();
            }
        }
    }
}

// this function allows the user to select the time duration
void DeepReader::on_actionSet_Timer_triggered()
{
    QInputDialog *timer_input = new QInputDialog();
    timer_input->setOptions(QInputDialog::NoButtons);
    bool ok;
    QString time_str = QInputDialog::getText(0, "Timer settings",
                      "Minutes per page", QLineEdit::Normal, "", &ok);
    timeDuration = time_str.toInt()*60;
}

// start timer for each page, time displays
void DeepReader::on_actionStart_triggered()
{
     startTime=clock();
     //create new timer
     QTimer *timer = new QTimer(this);
     //setup timer signal and slot
     //it automatically updates UI every second
     //stops when time runs out or stop triggered
     connect(timer, SIGNAL(timeout()), this, SLOT(setTimerDisplay()));
     //start is in milliseconds so multiply by 1000 to convert to seconds
     timer->start(timeDuration*1000);
    
    // PLEASE CALL THIS EVERY SECOND updateCounter()
}

// update display with timer
void DeepReader::setTimerDisplay()
{
   //this->timeValue->setHMS(0,this->timeValue->addSecs(-1).minute(),this->timeValue->addSecs(-1).second());
   //this->display(this->timeValue->toString());
    qDebug() << "Timer is running";
    //Need to add displaying the actual time of the timer
}

// stop timer
void DeepReader::on_actionStop_triggered()
{
//    timer->stop();
    qDebug() << "Time stopped!";
}
