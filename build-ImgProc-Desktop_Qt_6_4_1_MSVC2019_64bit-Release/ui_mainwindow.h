/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *filePathTxt;
    QPushButton *openImageBtn;
    QPushButton *viewImageBtn;
    QCheckBox *histBx;
    QCheckBox *hpBx;
    QCheckBox *lpBx;
    QCheckBox *kirBx;
    QCheckBox *threshBx;
    QCheckBox *gausBx;
    QCheckBox *prewBx;
    QCheckBox *waterBx;
    QCheckBox *sobBx;
    QCheckBox *eroBx;
    QCheckBox *diaBx;
    QPushButton *viewNewImageBtn;
    QPushButton *saveImageBtn;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *diaKern;
    QLineEdit *eroKern;
    QLineEdit *gausKern;
    QLabel *label_6;
    QLineEdit *kirKern;
    QLabel *label_7;
    QLineEdit *preKern;
    QLabel *label_8;
    QLineEdit *sobKern;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *loadImgBtn;
    QLineEdit *threshVal;
    QLabel *label_11;
    QPushButton *clearBtn;
    QLineEdit *hpKern;
    QLabel *label_12;
    QLineEdit *lpKern;
    QLabel *label_13;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuClose;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(824, 511);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        filePathTxt = new QTextEdit(centralwidget);
        filePathTxt->setObjectName("filePathTxt");
        filePathTxt->setGeometry(QRect(20, 30, 371, 61));
        QFont font;
        font.setPointSize(10);
        filePathTxt->setFont(font);
        openImageBtn = new QPushButton(centralwidget);
        openImageBtn->setObjectName("openImageBtn");
        openImageBtn->setGeometry(QRect(500, 30, 101, 31));
        QFont font1;
        font1.setPointSize(12);
        openImageBtn->setFont(font1);
        viewImageBtn = new QPushButton(centralwidget);
        viewImageBtn->setObjectName("viewImageBtn");
        viewImageBtn->setGeometry(QRect(610, 30, 191, 31));
        viewImageBtn->setFont(font1);
        histBx = new QCheckBox(centralwidget);
        histBx->setObjectName("histBx");
        histBx->setGeometry(QRect(21, 141, 182, 28));
        histBx->setFont(font1);
        hpBx = new QCheckBox(centralwidget);
        hpBx->setObjectName("hpBx");
        hpBx->setGeometry(QRect(21, 176, 131, 28));
        hpBx->setFont(font1);
        lpBx = new QCheckBox(centralwidget);
        lpBx->setObjectName("lpBx");
        lpBx->setGeometry(QRect(21, 211, 127, 28));
        lpBx->setFont(font1);
        kirBx = new QCheckBox(centralwidget);
        kirBx->setObjectName("kirBx");
        kirBx->setGeometry(QRect(421, 199, 65, 22));
        kirBx->setFont(font1);
        threshBx = new QCheckBox(centralwidget);
        threshBx->setObjectName("threshBx");
        threshBx->setGeometry(QRect(421, 141, 131, 22));
        threshBx->setFont(font1);
        gausBx = new QCheckBox(centralwidget);
        gausBx->setObjectName("gausBx");
        gausBx->setGeometry(QRect(421, 170, 85, 22));
        gausBx->setFont(font1);
        prewBx = new QCheckBox(centralwidget);
        prewBx->setObjectName("prewBx");
        prewBx->setGeometry(QRect(421, 228, 111, 22));
        prewBx->setFont(font1);
        waterBx = new QCheckBox(centralwidget);
        waterBx->setObjectName("waterBx");
        waterBx->setGeometry(QRect(421, 286, 98, 22));
        waterBx->setFont(font1);
        sobBx = new QCheckBox(centralwidget);
        sobBx->setObjectName("sobBx");
        sobBx->setGeometry(QRect(421, 257, 61, 22));
        sobBx->setFont(font1);
        eroBx = new QCheckBox(centralwidget);
        eroBx->setObjectName("eroBx");
        eroBx->setGeometry(QRect(421, 344, 111, 22));
        eroBx->setFont(font1);
        diaBx = new QCheckBox(centralwidget);
        diaBx->setObjectName("diaBx");
        diaBx->setGeometry(QRect(421, 315, 111, 22));
        diaBx->setFont(font1);
        viewNewImageBtn = new QPushButton(centralwidget);
        viewNewImageBtn->setObjectName("viewNewImageBtn");
        viewNewImageBtn->setGeometry(QRect(350, 410, 161, 31));
        viewNewImageBtn->setFont(font1);
        saveImageBtn = new QPushButton(centralwidget);
        saveImageBtn->setObjectName("saveImageBtn");
        saveImageBtn->setGeometry(QRect(540, 410, 121, 31));
        saveImageBtn->setFont(font1);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(620, 140, 161, 21));
        label->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(620, 320, 161, 21));
        label_2->setFont(font1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(620, 350, 161, 21));
        label_3->setFont(font1);
        diaKern = new QLineEdit(centralwidget);
        diaKern->setObjectName("diaKern");
        diaKern->setGeometry(QRect(570, 320, 41, 21));
        diaKern->setFont(font1);
        eroKern = new QLineEdit(centralwidget);
        eroKern->setObjectName("eroKern");
        eroKern->setGeometry(QRect(570, 350, 41, 21));
        eroKern->setFont(font1);
        gausKern = new QLineEdit(centralwidget);
        gausKern->setObjectName("gausKern");
        gausKern->setGeometry(QRect(570, 170, 41, 21));
        gausKern->setFont(font1);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(620, 200, 161, 21));
        label_6->setFont(font1);
        kirKern = new QLineEdit(centralwidget);
        kirKern->setObjectName("kirKern");
        kirKern->setGeometry(QRect(570, 200, 41, 21));
        kirKern->setFont(font1);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(620, 230, 161, 21));
        label_7->setFont(font1);
        preKern = new QLineEdit(centralwidget);
        preKern->setObjectName("preKern");
        preKern->setGeometry(QRect(570, 230, 41, 21));
        preKern->setFont(font1);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(620, 260, 161, 21));
        label_8->setFont(font1);
        sobKern = new QLineEdit(centralwidget);
        sobKern->setObjectName("sobKern");
        sobKern->setGeometry(QRect(570, 260, 41, 21));
        sobKern->setFont(font1);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(40, 100, 171, 31));
        QFont font2;
        font2.setPointSize(14);
        label_9->setFont(font2);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(440, 100, 171, 31));
        label_10->setFont(font2);
        loadImgBtn = new QPushButton(centralwidget);
        loadImgBtn->setObjectName("loadImgBtn");
        loadImgBtn->setGeometry(QRect(400, 30, 91, 31));
        loadImgBtn->setFont(font1);
        threshVal = new QLineEdit(centralwidget);
        threshVal->setObjectName("threshVal");
        threshVal->setGeometry(QRect(570, 140, 41, 21));
        threshVal->setFont(font1);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(620, 170, 161, 21));
        label_11->setFont(font1);
        clearBtn = new QPushButton(centralwidget);
        clearBtn->setObjectName("clearBtn");
        clearBtn->setGeometry(QRect(160, 410, 161, 31));
        clearBtn->setFont(font1);
        hpKern = new QLineEdit(centralwidget);
        hpKern->setObjectName("hpKern");
        hpKern->setGeometry(QRect(220, 180, 41, 21));
        hpKern->setFont(font1);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(270, 180, 101, 21));
        label_12->setFont(font1);
        lpKern = new QLineEdit(centralwidget);
        lpKern->setObjectName("lpKern");
        lpKern->setGeometry(QRect(220, 210, 41, 21));
        lpKern->setFont(font1);
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(270, 210, 101, 21));
        label_13->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 824, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuClose = new QMenu(menubar);
        menuClose->setObjectName("menuClose");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuClose->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        openImageBtn->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        viewImageBtn->setText(QCoreApplication::translate("MainWindow", "View Original Image", nullptr));
        histBx->setText(QCoreApplication::translate("MainWindow", "Histogram Equilization", nullptr));
        hpBx->setText(QCoreApplication::translate("MainWindow", "High Pass Filter", nullptr));
        lpBx->setText(QCoreApplication::translate("MainWindow", "Low Pass Filter", nullptr));
        kirBx->setText(QCoreApplication::translate("MainWindow", "Kirsch", nullptr));
        threshBx->setText(QCoreApplication::translate("MainWindow", "Thresholding", nullptr));
        gausBx->setText(QCoreApplication::translate("MainWindow", "Gaussian", nullptr));
        prewBx->setText(QCoreApplication::translate("MainWindow", "Prewitt", nullptr));
        waterBx->setText(QCoreApplication::translate("MainWindow", "Watershed", nullptr));
        sobBx->setText(QCoreApplication::translate("MainWindow", "Sobel", nullptr));
        eroBx->setText(QCoreApplication::translate("MainWindow", "Erosion", nullptr));
        diaBx->setText(QCoreApplication::translate("MainWindow", "Dialation", nullptr));
        viewNewImageBtn->setText(QCoreApplication::translate("MainWindow", "View New Image", nullptr));
        saveImageBtn->setText(QCoreApplication::translate("MainWindow", "Save Image", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Max Value (0-255)", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Kernel size", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Kernel size", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Kernel size", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Kernel size", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Kernel size", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Enhancement", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Segmentation", nullptr));
        loadImgBtn->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Kernel size", nullptr));
        clearBtn->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Kernel size", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Kernel size", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuClose->setTitle(QCoreApplication::translate("MainWindow", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
