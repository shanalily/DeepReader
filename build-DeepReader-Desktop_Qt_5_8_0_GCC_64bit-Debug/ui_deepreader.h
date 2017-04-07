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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeepReader
{
public:
    QAction *actionOpen;
    QAction *actionSave_As;
    QWidget *centralWidget;
    QGraphicsView *mainImage;
    QLineEdit *lineEdit;
    QPlainTextEdit *textEditor;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *previous;
    QPushButton *next;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DeepReader)
    {
        if (DeepReader->objectName().isEmpty())
            DeepReader->setObjectName(QStringLiteral("DeepReader"));
        DeepReader->resize(1199, 772);
        actionOpen = new QAction(DeepReader);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave_As = new QAction(DeepReader);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        centralWidget = new QWidget(DeepReader);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        mainImage = new QGraphicsView(centralWidget);
        mainImage->setObjectName(QStringLiteral("mainImage"));
        mainImage->setGeometry(QRect(10, 10, 621, 631));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(80, 650, 113, 25));
        textEditor = new QPlainTextEdit(centralWidget);
        textEditor->setObjectName(QStringLiteral("textEditor"));
        textEditor->setGeometry(QRect(650, 10, 521, 631));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 650, 61, 27));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        previous = new QPushButton(widget);
        previous->setObjectName(QStringLiteral("previous"));

        horizontalLayout->addWidget(previous);

        next = new QPushButton(widget);
        next->setObjectName(QStringLiteral("next"));

        horizontalLayout->addWidget(next);

        DeepReader->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DeepReader);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1199, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        DeepReader->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DeepReader);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DeepReader->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DeepReader);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DeepReader->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave_As);

        retranslateUi(DeepReader);

        QMetaObject::connectSlotsByName(DeepReader);
    } // setupUi

    void retranslateUi(QMainWindow *DeepReader)
    {
        DeepReader->setWindowTitle(QApplication::translate("DeepReader", "DeepReader", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("DeepReader", "Open File", Q_NULLPTR));
        actionSave_As->setText(QApplication::translate("DeepReader", "Save As", Q_NULLPTR));
        previous->setText(QApplication::translate("DeepReader", "<-", Q_NULLPTR));
        next->setText(QApplication::translate("DeepReader", "->", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("DeepReader", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DeepReader: public Ui_DeepReader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEEPREADER_H
