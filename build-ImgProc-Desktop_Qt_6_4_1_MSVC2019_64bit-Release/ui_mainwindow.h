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
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
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
    QPushButton *viewNewImageBtn;
    QPushButton *saveImageBtn;
    QLineEdit *diaKern;
    QLineEdit *eroKern;
    QLineEdit *gausKern;
    QLineEdit *sobKern;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *loadImgBtn;
    QLineEdit *threshVal;
    QPushButton *clearBtn;
    QLineEdit *hpKern;
    QLineEdit *lpKern;
    QLineEdit *brightNum;
    QCheckBox *brightBtn;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QCheckBox *threshBx;
    QCheckBox *gausBx;
    QCheckBox *sobBx;
    QCheckBox *diaBx;
    QCheckBox *eroBx;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QLabel *label_11;
    QLabel *label_8;
    QLabel *label_2;
    QLabel *label_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(824, 511);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
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
        openImageBtn->setCheckable(false);
        viewImageBtn = new QPushButton(centralwidget);
        viewImageBtn->setObjectName("viewImageBtn");
        viewImageBtn->setGeometry(QRect(610, 30, 191, 31));
        viewImageBtn->setFont(font1);
        viewImageBtn->setCheckable(false);
        histBx = new QCheckBox(centralwidget);
        histBx->setObjectName("histBx");
        histBx->setGeometry(QRect(22, 142, 228, 33));
        histBx->setFont(font1);
        hpBx = new QCheckBox(centralwidget);
        hpBx->setObjectName("hpBx");
        hpBx->setGeometry(QRect(22, 182, 161, 33));
        hpBx->setFont(font1);
        lpBx = new QCheckBox(centralwidget);
        lpBx->setObjectName("lpBx");
        lpBx->setGeometry(QRect(22, 222, 154, 33));
        lpBx->setFont(font1);
        viewNewImageBtn = new QPushButton(centralwidget);
        viewNewImageBtn->setObjectName("viewNewImageBtn");
        viewNewImageBtn->setGeometry(QRect(350, 390, 161, 31));
        viewNewImageBtn->setFont(font1);
        viewNewImageBtn->setCheckable(false);
        saveImageBtn = new QPushButton(centralwidget);
        saveImageBtn->setObjectName("saveImageBtn");
        saveImageBtn->setGeometry(QRect(540, 390, 121, 31));
        saveImageBtn->setFont(font1);
        saveImageBtn->setStyleSheet(QString::fromUtf8(""));
        saveImageBtn->setCheckable(false);
        diaKern = new QLineEdit(centralwidget);
        diaKern->setObjectName("diaKern");
        diaKern->setGeometry(QRect(571, 271, 57, 31));
        diaKern->setFont(font1);
        eroKern = new QLineEdit(centralwidget);
        eroKern->setObjectName("eroKern");
        eroKern->setGeometry(QRect(571, 313, 57, 31));
        eroKern->setFont(font1);
        gausKern = new QLineEdit(centralwidget);
        gausKern->setObjectName("gausKern");
        gausKern->setGeometry(QRect(571, 187, 57, 31));
        gausKern->setFont(font1);
        sobKern = new QLineEdit(centralwidget);
        sobKern->setObjectName("sobKern");
        sobKern->setGeometry(QRect(571, 229, 57, 31));
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
        loadImgBtn->setCheckable(false);
        threshVal = new QLineEdit(centralwidget);
        threshVal->setObjectName("threshVal");
        threshVal->setGeometry(QRect(571, 145, 57, 31));
        threshVal->setFont(font1);
        clearBtn = new QPushButton(centralwidget);
        clearBtn->setObjectName("clearBtn");
        clearBtn->setGeometry(QRect(160, 390, 161, 31));
        clearBtn->setFont(font1);
        clearBtn->setCheckable(false);
        hpKern = new QLineEdit(centralwidget);
        hpKern->setObjectName("hpKern");
        hpKern->setGeometry(QRect(200, 185, 59, 31));
        hpKern->setFont(font1);
        lpKern = new QLineEdit(centralwidget);
        lpKern->setObjectName("lpKern");
        lpKern->setGeometry(QRect(200, 227, 59, 31));
        lpKern->setFont(font1);
        brightNum = new QLineEdit(centralwidget);
        brightNum->setObjectName("brightNum");
        brightNum->setGeometry(QRect(200, 269, 59, 31));
        brightNum->setFont(font1);
        brightBtn = new QCheckBox(centralwidget);
        brightBtn->setObjectName("brightBtn");
        brightBtn->setGeometry(QRect(22, 262, 154, 33));
        brightBtn->setFont(font1);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(270, 180, 94, 121));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName("label_12");
        label_12->setFont(font1);

        verticalLayout_3->addWidget(label_12);

        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName("label_13");
        label_13->setFont(font1);

        verticalLayout_3->addWidget(label_13);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName("label_14");
        label_14->setFont(font1);

        verticalLayout_3->addWidget(label_14);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(430, 140, 145, 195));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        threshBx = new QCheckBox(layoutWidget1);
        threshBx->setObjectName("threshBx");
        threshBx->setFont(font1);

        verticalLayout->addWidget(threshBx);

        gausBx = new QCheckBox(layoutWidget1);
        gausBx->setObjectName("gausBx");
        gausBx->setFont(font1);

        verticalLayout->addWidget(gausBx);

        sobBx = new QCheckBox(layoutWidget1);
        sobBx->setObjectName("sobBx");
        sobBx->setFont(font1);

        verticalLayout->addWidget(sobBx);

        diaBx = new QCheckBox(layoutWidget1);
        diaBx->setObjectName("diaBx");
        diaBx->setFont(font1);

        verticalLayout->addWidget(diaBx);

        eroBx = new QCheckBox(layoutWidget1);
        eroBx->setObjectName("eroBx");
        eroBx->setFont(font1);

        verticalLayout->addWidget(eroBx);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(640, 144, 160, 201));
        verticalLayout_5 = new QVBoxLayout(layoutWidget2);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName("label");
        label->setFont(font1);

        verticalLayout_5->addWidget(label);

        label_11 = new QLabel(layoutWidget2);
        label_11->setObjectName("label_11");
        label_11->setFont(font1);

        verticalLayout_5->addWidget(label_11);

        label_8 = new QLabel(layoutWidget2);
        label_8->setObjectName("label_8");
        label_8->setFont(font1);

        verticalLayout_5->addWidget(label_8);

        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName("label_2");
        label_2->setFont(font1);

        verticalLayout_5->addWidget(label_2);

        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName("label_3");
        label_3->setFont(font1);

        verticalLayout_5->addWidget(label_3);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

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
        viewNewImageBtn->setText(QCoreApplication::translate("MainWindow", "View New Image", nullptr));
        saveImageBtn->setText(QCoreApplication::translate("MainWindow", "Save Image", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Enhancement", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Segmentation", nullptr));
        loadImgBtn->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        clearBtn->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        brightBtn->setText(QCoreApplication::translate("MainWindow", "Brightness", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Kernel size", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Kernel size", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Units", nullptr));
        threshBx->setText(QCoreApplication::translate("MainWindow", "Thresholding", nullptr));
        gausBx->setText(QCoreApplication::translate("MainWindow", "Gaussian", nullptr));
        sobBx->setText(QCoreApplication::translate("MainWindow", "Sobel", nullptr));
        diaBx->setText(QCoreApplication::translate("MainWindow", "Dialation", nullptr));
        eroBx->setText(QCoreApplication::translate("MainWindow", "Erosion", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Max Value (0-255)", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Kernel size", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Kernel size", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Kernel size", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Kernel size", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
