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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeepReader
{
public:
    QAction *actionOpen;
    QAction *actionSave_As;
    QAction *actionOpen_Text_File;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGraphicsView *mainImage;
    QPlainTextEdit *textEditor;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *previous;
    QPushButton *next;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer;
    QLineEdit *start_page;
    QLineEdit *end_page;
    QPushButton *pushButton;
    QLineEdit *search;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DeepReader)
    {
        if (DeepReader->objectName().isEmpty())
            DeepReader->setObjectName(QStringLiteral("DeepReader"));
        DeepReader->resize(1359, 844);
        actionOpen = new QAction(DeepReader);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave_As = new QAction(DeepReader);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionOpen_Text_File = new QAction(DeepReader);
        actionOpen_Text_File->setObjectName(QStringLiteral("actionOpen_Text_File"));
        centralWidget = new QWidget(DeepReader);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        mainImage = new QGraphicsView(centralWidget);
        mainImage->setObjectName(QStringLiteral("mainImage"));

        gridLayout->addWidget(mainImage, 0, 0, 1, 1);

        textEditor = new QPlainTextEdit(centralWidget);
        textEditor->setObjectName(QStringLiteral("textEditor"));

        gridLayout->addWidget(textEditor, 0, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        previous = new QPushButton(centralWidget);
        previous->setObjectName(QStringLiteral("previous"));
        previous->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(previous);

        next = new QPushButton(centralWidget);
        next->setObjectName(QStringLiteral("next"));
        next->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(next);


        horizontalLayout_2->addLayout(horizontalLayout);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(lineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        start_page = new QLineEdit(centralWidget);
        start_page->setObjectName(QStringLiteral("start_page"));
        start_page->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(start_page);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        end_page = new QLineEdit(centralWidget);
        end_page->setObjectName(QStringLiteral("end_page"));
        end_page->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(end_page);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(pushButton);

        search = new QLineEdit(centralWidget);
        search->setObjectName(QStringLiteral("search"));
        search->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_3->addWidget(search);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        DeepReader->setCentralWidget(centralWidget);
        mainImage->raise();
        lineEdit->raise();
        textEditor->raise();
        search->raise();
        menuBar = new QMenuBar(DeepReader);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1359, 22));
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
        menuFile->addAction(actionOpen_Text_File);
        menuFile->addAction(actionSave_As);

        retranslateUi(DeepReader);

        QMetaObject::connectSlotsByName(DeepReader);
    } // setupUi

    void retranslateUi(QMainWindow *DeepReader)
    {
        DeepReader->setWindowTitle(QApplication::translate("DeepReader", "DeepReader", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("DeepReader", "Open File", Q_NULLPTR));
        actionSave_As->setText(QApplication::translate("DeepReader", "Save As", Q_NULLPTR));
        actionOpen_Text_File->setText(QApplication::translate("DeepReader", "Open Text File", Q_NULLPTR));
        previous->setText(QApplication::translate("DeepReader", "<-", Q_NULLPTR));
        next->setText(QApplication::translate("DeepReader", "->", Q_NULLPTR));
        pushButton->setText(QApplication::translate("DeepReader", "Start", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("DeepReader", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DeepReader: public Ui_DeepReader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEEPREADER_H
