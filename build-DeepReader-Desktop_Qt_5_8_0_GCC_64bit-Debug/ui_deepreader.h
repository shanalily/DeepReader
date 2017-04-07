/********************************************************************************
** Form generated from reading UI file 'deepreader.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEEPREADER_H
#define UI_DEEPREADER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeepReader
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DeepReader)
    {
        if (DeepReader->objectName().isEmpty())
            DeepReader->setObjectName(QStringLiteral("DeepReader"));
        DeepReader->resize(400, 300);
        menuBar = new QMenuBar(DeepReader);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        DeepReader->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DeepReader);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DeepReader->addToolBar(mainToolBar);
        centralWidget = new QWidget(DeepReader);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        DeepReader->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(DeepReader);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DeepReader->setStatusBar(statusBar);

        retranslateUi(DeepReader);

        QMetaObject::connectSlotsByName(DeepReader);
    } // setupUi

    void retranslateUi(QMainWindow *DeepReader)
    {
        DeepReader->setWindowTitle(QApplication::translate("DeepReader", "DeepReader", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DeepReader: public Ui_DeepReader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEEPREADER_H
