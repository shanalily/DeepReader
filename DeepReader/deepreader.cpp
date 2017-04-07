#include "deepreader.h"
#include "ui_deepreader.h"

DeepReader::DeepReader(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DeepReader)
{
    ui->setupUi(this);
}

DeepReader::~DeepReader()
{
    delete ui;
}
