#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <poppler-qt5.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showPage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_returnPressed();

    void on_actionOpen_File_triggered();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_Font_clicked();

    void on_zoom_in_clicked();

    void on_zoom_out_clicked();

    void on_actionSave_triggered();

    void on_find_returnPressed();

private:
    Ui::MainWindow *ui;
    Poppler::Document *doc;
    int pageCounter;
    int zoom;
};

#endif // MAINWINDOW_H
