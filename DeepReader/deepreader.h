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

private slots:
    void on_actionOpen_triggered();

    void on_previous_clicked();

    void on_next_clicked();

    void on_lineEdit_returnPressed();

    void on_actionSave_As_triggered();

    void on_actionOpen_Text_File_triggered();

private:
    Ui::DeepReader *ui;
    Poppler::Document *doc;
    int pageCounter;
    int zoom;
};

#endif // DEEPREADER_H
