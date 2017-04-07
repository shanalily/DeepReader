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

private:
    Ui::DeepReader *ui;
    Poppler::Document *doc;
    int pageCounter;
    int zoom;
};

#endif // DEEPREADER_H
