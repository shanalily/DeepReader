#ifndef DEEPREADER_H
#define DEEPREADER_H

#include <QMainWindow>
#include <QTimer>
#include <poppler-qt5.h>

namespace Ui {
class DeepReader;
}

class DeepReader : public QMainWindow {
    Q_OBJECT
public:
    explicit DeepReader(QWidget *parent = 0);
    ~DeepReader();
    // loads new page based on current value of pageCounter and displays it
    void showPage();
    // determines whether notes are relevant to material on current page
    bool relevantNotes(QStringList words, QStringList notes, int previousLength);
    //updates counter of relevant note words
    void updateCounter();
    // extracts text from pdf page
    void pageText(); // I'm not sure what this should return yet
    // determines whether notes are good enough to move to the next page
    bool goodNotes();
    void checkTime();
    int goodNotesCounter(QStringList words, QStringList notes, int previousText);
private slots:
    void on_actionOpen_triggered();
    void on_previous_clicked();
    void on_next_clicked();
    void on_lineEdit_returnPressed();
    void on_actionSave_As_triggered();
    void on_actionOpen_Text_File_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actionCut_triggered();
    void on_actionCopy_triggered();
    void on_actionPaste_triggered();
    void on_actionSelect_All_triggered();
    //void on_actionBullet_List_triggered()
    void on_bold_clicked();
    void on_italic_clicked();
    void on_underline_clicked();
    void on_font_currentFontChanged();
    void on_font_size_valueChanged();
    void on_alignleft_clicked();
    void on_aligncenter_clicked();
    void on_alignright_clicked();
    void on_alignjustify_clicked();
    void on_zoom_out_clicked();
    void on_zoom_in_clicked();
    void on_start_clicked();
    void on_zoom_out_pdf_clicked();
    void on_zoom_in_pdf_clicked();
    void on_search_returnPressed();
    void on_actionSet_Timer_triggered();
    void on_actionStart_triggered();
    void on_actionStop_triggered();
    void setTimerDisplay();
    void on_actionChange_relevance_weight_triggered();
    void on_actionStop_Study_Session_triggered();

private:
    Ui::DeepReader *ui;
    // pdf document
    Poppler::Document *doc;
    // image of current page
    QImage image;
    // page that should be viewed
    int pageCounter;
    int zoom;
    bool studySession;
    float weightFactor;
    int startPage;
    int endPage;
    clock_t startTime;
    double timeDuration;
    QStringList words;
    // so that words in notes from
    // previous pages can be ignored
    int previousText;
    QString currentWord;
    // in case coloring search word is implemented
    QList<QList<QRectF> > locs;
    // pages on which search word is found
    QList<int> pages;
    int pagesIndex;
    bool timerOn;
    //timer per page
    QTimer *timer;
};

#endif // DEEPREADER_H
