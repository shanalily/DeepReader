#ifndef DEEPREADER_H
#define DEEPREADER_H

#include <QMainWindow>
#include <poppler-qt5.h>

namespace Ui {
class DeepReader;
}

class DeepReader : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeepReader(QWidget *parent = 0);
    ~DeepReader();
    void showPage();
    QStringList pageText(); // I'm not sure what this should return yet

private slots:
    void on_actionOpen_triggered();

    void on_previous_clicked();

    void on_next_clicked();

    void on_lineEdit_returnPressed();

    void on_actionSave_As_triggered();

    void on_actionOpen_Text_File_triggered();

    void on_zoom_out_clicked();

    void on_zoom_in_clicked();

    void on_start_clicked();

private:
    Ui::DeepReader *ui;
    Poppler::Document *doc;
    int pageCounter;
    int zoom;
    bool studySession;
};

#endif // DEEPREADER_H
