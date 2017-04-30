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
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeepReader
{
public:
    QAction *actionOpen;
    QAction *actionSave_As;
    QAction *actionOpen_Text_File;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionSelect_All;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionBullet;
    QAction *actionBullet_2;
    QAction *actionBullet_List;
    QAction *actionSet_Timer;
    QAction *actionStart;
    QAction *actionStop;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGraphicsView *mainImage;
    QTextEdit *texteditor;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *bold;
    QPushButton *italic;
    QPushButton *underline;
    QSpacerItem *horizontalSpacer_2;
    QFontComboBox *font;
    QSpinBox *font_size;
    QPushButton *alignleft;
    QPushButton *aligncenter;
    QPushButton *alignright;
    QPushButton *alignjustify;
    QPushButton *zoom_out;
    QPushButton *zoom_in;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_3;
    QLabel *timer;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *previous;
    QPushButton *next;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer;
    QLineEdit *start_page;
    QLineEdit *end_page;
    QPushButton *start;
    QLineEdit *search;
    QPushButton *zoom_out_pdf;
    QPushButton *zoom_in_pdf;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_4;
    QLabel *word_count;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuInsert;
    QMenu *menuTimer;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DeepReader)
    {
        if (DeepReader->objectName().isEmpty())
            DeepReader->setObjectName(QStringLiteral("DeepReader"));
        DeepReader->resize(1359, 856);
        DeepReader->setStyleSheet(QStringLiteral(""));
        actionOpen = new QAction(DeepReader);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave_As = new QAction(DeepReader);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionOpen_Text_File = new QAction(DeepReader);
        actionOpen_Text_File->setObjectName(QStringLiteral("actionOpen_Text_File"));
        actionCut = new QAction(DeepReader);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        actionCopy = new QAction(DeepReader);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        actionPaste = new QAction(DeepReader);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        actionSelect_All = new QAction(DeepReader);
        actionSelect_All->setObjectName(QStringLiteral("actionSelect_All"));
        actionUndo = new QAction(DeepReader);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionRedo = new QAction(DeepReader);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        actionBullet = new QAction(DeepReader);
        actionBullet->setObjectName(QStringLiteral("actionBullet"));
        actionBullet_2 = new QAction(DeepReader);
        actionBullet_2->setObjectName(QStringLiteral("actionBullet_2"));
        actionBullet_List = new QAction(DeepReader);
        actionBullet_List->setObjectName(QStringLiteral("actionBullet_List"));
        actionSet_Timer = new QAction(DeepReader);
        actionSet_Timer->setObjectName(QStringLiteral("actionSet_Timer"));
        actionStart = new QAction(DeepReader);
        actionStart->setObjectName(QStringLiteral("actionStart"));
        actionStop = new QAction(DeepReader);
        actionStop->setObjectName(QStringLiteral("actionStop"));
        centralWidget = new QWidget(DeepReader);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        mainImage = new QGraphicsView(centralWidget);
        mainImage->setObjectName(QStringLiteral("mainImage"));
        mainImage->setStyleSheet(QStringLiteral("background-color: white;"));

        gridLayout->addWidget(mainImage, 1, 0, 1, 1);

        texteditor = new QTextEdit(centralWidget);
        texteditor->setObjectName(QStringLiteral("texteditor"));
        texteditor->setStyleSheet(QStringLiteral("background-color: white;"));

        gridLayout->addWidget(texteditor, 1, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        bold = new QPushButton(centralWidget);
        bold->setObjectName(QStringLiteral("bold"));
        bold->setMaximumSize(QSize(30, 16777215));
        bold->setStyleSheet(QLatin1String("border: none;\n"
"background-color: #0099cc;\n"
"color: white;\n"
"padding: 4px 10px;\n"
"font-weight: bold;"));

        horizontalLayout_4->addWidget(bold);

        italic = new QPushButton(centralWidget);
        italic->setObjectName(QStringLiteral("italic"));
        italic->setMaximumSize(QSize(30, 16777215));
        italic->setStyleSheet(QLatin1String("border: none;\n"
"background-color: #0099cc;\n"
"color: white;\n"
"padding: 4px 11px;\n"
"font-weight: bold;"));

        horizontalLayout_4->addWidget(italic);

        underline = new QPushButton(centralWidget);
        underline->setObjectName(QStringLiteral("underline"));
        underline->setMaximumSize(QSize(30, 16777215));
        underline->setStyleSheet(QLatin1String("border: none;\n"
"background-color: #0099cc;\n"
"color: white;\n"
"padding: 4px 10px;\n"
"font-weight: bold;"));

        horizontalLayout_4->addWidget(underline);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        font = new QFontComboBox(centralWidget);
        font->setObjectName(QStringLiteral("font"));
        font->setStyleSheet(QLatin1String("QComboBox::drop-down {\n"
"	border: none;\n"
"	background-color: #0099cc;\n"
"	image: url(:/new/button_images/white_arrow_down.png);\n"
"	padding: 2px;\n"
"}"));

        horizontalLayout_4->addWidget(font);

        font_size = new QSpinBox(centralWidget);
        font_size->setObjectName(QStringLiteral("font_size"));
        font_size->setStyleSheet(QStringLiteral("background-color: white;"));
        font_size->setMinimum(1);
        font_size->setMaximum(100);
        font_size->setValue(12);

        horizontalLayout_4->addWidget(font_size);

        alignleft = new QPushButton(centralWidget);
        alignleft->setObjectName(QStringLiteral("alignleft"));
        alignleft->setMaximumSize(QSize(30, 16777215));
        alignleft->setStyleSheet(QLatin1String("border: none;\n"
"background-color: #0099cc;\n"
"color: white;\n"
"padding: 4px 4px;\n"
"font-weight: bold;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/align/Align Left-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        alignleft->setIcon(icon);

        horizontalLayout_4->addWidget(alignleft);

        aligncenter = new QPushButton(centralWidget);
        aligncenter->setObjectName(QStringLiteral("aligncenter"));
        aligncenter->setMaximumSize(QSize(30, 16777215));
        aligncenter->setStyleSheet(QLatin1String("border: none;\n"
"background-color: #0099cc;\n"
"color: white;\n"
"padding: 4px 4px;\n"
"font-weight: bold;"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/align/Align Center-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        aligncenter->setIcon(icon1);

        horizontalLayout_4->addWidget(aligncenter);

        alignright = new QPushButton(centralWidget);
        alignright->setObjectName(QStringLiteral("alignright"));
        alignright->setMaximumSize(QSize(30, 16777215));
        alignright->setStyleSheet(QLatin1String("border: none;\n"
"background-color: #0099cc;\n"
"color: white;\n"
"padding: 4px 4px;\n"
"font-weight: bold;"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/align/Align Right-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        alignright->setIcon(icon2);

        horizontalLayout_4->addWidget(alignright);

        alignjustify = new QPushButton(centralWidget);
        alignjustify->setObjectName(QStringLiteral("alignjustify"));
        alignjustify->setMaximumSize(QSize(30, 16777215));
        alignjustify->setStyleSheet(QLatin1String("border: none;\n"
"background-color: #0099cc;\n"
"color: white;\n"
"padding: 4px 4px;\n"
"font-weight: bold;"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/align/Align Justify-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        alignjustify->setIcon(icon3);

        horizontalLayout_4->addWidget(alignjustify);

        zoom_out = new QPushButton(centralWidget);
        zoom_out->setObjectName(QStringLiteral("zoom_out"));
        zoom_out->setMaximumSize(QSize(30, 16777215));
        zoom_out->setStyleSheet(QLatin1String("border: none;\n"
"background-color: #0099cc;\n"
"color: white;\n"
"padding: 4px 12px;\n"
"font-weight: bold;"));

        horizontalLayout_4->addWidget(zoom_out);

        zoom_in = new QPushButton(centralWidget);
        zoom_in->setObjectName(QStringLiteral("zoom_in"));
        zoom_in->setMaximumSize(QSize(30, 16777215));
        zoom_in->setStyleSheet(QLatin1String("border: none;\n"
"background-color: #0099cc;\n"
"color: white;\n"
"padding: 4px 11px;\n"
"font-weight: bold;"));

        horizontalLayout_4->addWidget(zoom_in);


        gridLayout->addLayout(horizontalLayout_4, 2, 1, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        timer = new QLabel(centralWidget);
        timer->setObjectName(QStringLiteral("timer"));
        timer->setMaximumSize(QSize(600, 16777215));

        horizontalLayout_9->addWidget(timer);


        gridLayout->addLayout(horizontalLayout_9, 0, 0, 1, 1);

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
        previous->setStyleSheet(QLatin1String("border: none;\n"
"background-color: #0099cc;\n"
"color: white;\n"
"padding: 4px 12px;"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/button_images/white_arrow_left.png"), QSize(), QIcon::Normal, QIcon::Off);
        previous->setIcon(icon4);

        horizontalLayout->addWidget(previous);

        next = new QPushButton(centralWidget);
        next->setObjectName(QStringLiteral("next"));
        next->setMaximumSize(QSize(30, 16777215));
        next->setStyleSheet(QLatin1String("border: none;\n"
"background-color: #0099cc;\n"
"color: white;\n"
"padding: 4px 12px;"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/button_images/white_arrow_right.png"), QSize(), QIcon::Normal, QIcon::Off);
        next->setIcon(icon5);

        horizontalLayout->addWidget(next);


        horizontalLayout_2->addLayout(horizontalLayout);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMaximumSize(QSize(100, 16777215));
        lineEdit->setStyleSheet(QStringLiteral("background-color: white;"));

        horizontalLayout_2->addWidget(lineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        start_page = new QLineEdit(centralWidget);
        start_page->setObjectName(QStringLiteral("start_page"));
        start_page->setMaximumSize(QSize(100, 16777215));
        start_page->setStyleSheet(QStringLiteral("background-color: white;"));

        horizontalLayout_2->addWidget(start_page);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        end_page = new QLineEdit(centralWidget);
        end_page->setObjectName(QStringLiteral("end_page"));
        end_page->setMaximumSize(QSize(100, 16777215));
        end_page->setStyleSheet(QStringLiteral("background-color: white;"));

        horizontalLayout_3->addWidget(end_page);

        start = new QPushButton(centralWidget);
        start->setObjectName(QStringLiteral("start"));
        start->setMaximumSize(QSize(50, 16777215));
        start->setStyleSheet(QLatin1String("border: none;\n"
"background-color: #0099cc;\n"
"color: white;\n"
"padding: 4px;\n"
"font-weight: bold;"));

        horizontalLayout_3->addWidget(start);

        search = new QLineEdit(centralWidget);
        search->setObjectName(QStringLiteral("search"));
        search->setMaximumSize(QSize(120, 16777215));
        search->setStyleSheet(QStringLiteral("background-color: white;"));

        horizontalLayout_3->addWidget(search);

        zoom_out_pdf = new QPushButton(centralWidget);
        zoom_out_pdf->setObjectName(QStringLiteral("zoom_out_pdf"));
        zoom_out_pdf->setMaximumSize(QSize(30, 16777215));
        zoom_out_pdf->setStyleSheet(QLatin1String("border: none;\n"
"background-color: #0099cc;\n"
"color: white;\n"
"padding: 4px 12px;\n"
"font-weight: bold;"));

        horizontalLayout_3->addWidget(zoom_out_pdf);

        zoom_in_pdf = new QPushButton(centralWidget);
        zoom_in_pdf->setObjectName(QStringLiteral("zoom_in_pdf"));
        zoom_in_pdf->setMaximumSize(QSize(30, 16777215));
        zoom_in_pdf->setStyleSheet(QLatin1String("border: none;\n"
"background-color: #0099cc;\n"
"color: white;\n"
"padding: 4px 11px;\n"
"font-weight: bold;"));

        horizontalLayout_3->addWidget(zoom_in_pdf);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_4);

        word_count = new QLabel(centralWidget);
        word_count->setObjectName(QStringLiteral("word_count"));

        horizontalLayout_10->addWidget(word_count);


        gridLayout->addLayout(horizontalLayout_10, 0, 1, 1, 1);

        DeepReader->setCentralWidget(centralWidget);
        mainImage->raise();
        texteditor->raise();
        menuBar = new QMenuBar(DeepReader);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1359, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuInsert = new QMenu(menuBar);
        menuInsert->setObjectName(QStringLiteral("menuInsert"));
        menuTimer = new QMenu(menuBar);
        menuTimer->setObjectName(QStringLiteral("menuTimer"));
        DeepReader->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DeepReader);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DeepReader->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DeepReader);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DeepReader->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuInsert->menuAction());
        menuBar->addAction(menuTimer->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionOpen_Text_File);
        menuFile->addAction(actionSave_As);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionSelect_All);
        menuInsert->addAction(actionBullet_List);
        menuTimer->addAction(actionSet_Timer);
        menuTimer->addAction(actionStart);
        menuTimer->addAction(actionStop);

        retranslateUi(DeepReader);

        QMetaObject::connectSlotsByName(DeepReader);
    } // setupUi

    void retranslateUi(QMainWindow *DeepReader)
    {
        DeepReader->setWindowTitle(QApplication::translate("DeepReader", "DeepReader", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("DeepReader", "Open Document", Q_NULLPTR));
        actionSave_As->setText(QApplication::translate("DeepReader", "Save Text As", Q_NULLPTR));
        actionOpen_Text_File->setText(QApplication::translate("DeepReader", "Open Text File", Q_NULLPTR));
        actionCut->setText(QApplication::translate("DeepReader", "Cut", Q_NULLPTR));
        actionCopy->setText(QApplication::translate("DeepReader", "Copy", Q_NULLPTR));
        actionPaste->setText(QApplication::translate("DeepReader", "Paste", Q_NULLPTR));
        actionSelect_All->setText(QApplication::translate("DeepReader", "Select All", Q_NULLPTR));
        actionUndo->setText(QApplication::translate("DeepReader", "Undo", Q_NULLPTR));
        actionRedo->setText(QApplication::translate("DeepReader", "Redo", Q_NULLPTR));
        actionBullet->setText(QApplication::translate("DeepReader", "Bullet", Q_NULLPTR));
        actionBullet_2->setText(QApplication::translate("DeepReader", "Bullet", Q_NULLPTR));
        actionBullet_List->setText(QApplication::translate("DeepReader", "Bullet List", Q_NULLPTR));
        actionSet_Timer->setText(QApplication::translate("DeepReader", "Set", Q_NULLPTR));
        actionStart->setText(QApplication::translate("DeepReader", "Start", Q_NULLPTR));
        actionStop->setText(QApplication::translate("DeepReader", "Stop", Q_NULLPTR));
        bold->setText(QApplication::translate("DeepReader", "B", Q_NULLPTR));
        italic->setText(QApplication::translate("DeepReader", "I", Q_NULLPTR));
        underline->setText(QApplication::translate("DeepReader", "U", Q_NULLPTR));
        alignleft->setText(QString());
        aligncenter->setText(QString());
        alignright->setText(QString());
        alignjustify->setText(QString());
        zoom_out->setText(QApplication::translate("DeepReader", "-", Q_NULLPTR));
        zoom_in->setText(QApplication::translate("DeepReader", "+", Q_NULLPTR));
        timer->setText(QApplication::translate("DeepReader", "TextLabel", Q_NULLPTR));
        previous->setText(QString());
        next->setText(QString());
        start->setText(QApplication::translate("DeepReader", "Start", Q_NULLPTR));
        zoom_out_pdf->setText(QApplication::translate("DeepReader", "-", Q_NULLPTR));
        zoom_in_pdf->setText(QApplication::translate("DeepReader", "+", Q_NULLPTR));
        word_count->setText(QApplication::translate("DeepReader", "TextLabel", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("DeepReader", "File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("DeepReader", "Edit", Q_NULLPTR));
        menuInsert->setTitle(QApplication::translate("DeepReader", "Insert", Q_NULLPTR));
        menuTimer->setTitle(QApplication::translate("DeepReader", "Timer", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DeepReader: public Ui_DeepReader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEEPREADER_H
