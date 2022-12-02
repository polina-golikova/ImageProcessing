#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

//  MainWindow: creates MainWindow constructor to generate the UI backend
//
//  Input: QWidget
//  Output:
//
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect buttons to signals

    // File and image I/O, view buttons
    connect(ui->loadImgBtn, SIGNAL(clicked()), this,SLOT(on_filePathTxt()));
    connect(ui->openImageBtn, SIGNAL(clicked()), this, SLOT(on_openImageBtn()));
    connect(ui->viewImageBtn, SIGNAL(clicked()), this, SLOT(on_viewImageBtn()));
    connect(ui->viewNewImageBtn, SIGNAL(clicked()), this, SLOT(on_viewNewImageBtn()));
    connect(ui->saveImageBtn, SIGNAL(clicked()), this, SLOT(on_saveImageBtn()));
    connect(ui->clearBtn, SIGNAL(clicked()), this, SLOT(on_clear()));
}

//  MainWindow: creates MainWindow destructor to deallocate memory
//
//  Input:
//  Output:
//
MainWindow::~MainWindow()
{
    // Deallocate memory
    delete ui;
    delete img;
    delete e;
    delete s;
}

//  printOddError: displays an error window box
//
//  Input:
//  Output:
//
void MainWindow::printOddError(std::string error)
{
    // Show error window if kernel size isn't odd
    QString str = QString::fromStdString(error);
    QMessageBox messageBox;
    messageBox.critical(0, "Error", str);
    messageBox.setFixedSize(500,200);
}

//  on_filePathTxt: saves user defined image file path and outputs to window
//
//  Input:
//  Output:
//
void MainWindow::on_filePathTxt()
{
    filename = QFileDialog::getOpenFileName(this, "Choose File");

    ui->filePathTxt->clear();
    ui->filePathTxt->setPlainText(filename);
}

//  on_openImageBtn: creates Img* obj using filepath to the image
//
//  Input:
//  Output:
//
void MainWindow::on_openImageBtn()
{
    img = new Image(filename.toStdString());
    e = new Enhancement(img);
    s = new Segmentation(img);
}

//  on_clear: resets all inputs, checkboxes, clears & undoes processes on images, re-Grays the image
//
//  Input:
//  Output:
//
void MainWindow::on_clear()
{
    modifier = "";

    // reset checked boxes
    ui->histBx->setCheckState(Qt::Unchecked);
    ui->hpBx->setCheckState(Qt::Unchecked);
    ui->lpBx->setCheckState(Qt::Unchecked);
    ui->threshBx->setCheckState(Qt::Unchecked);
    ui->gausBx->setCheckState(Qt::Unchecked);
    ui->sobBx->setCheckState(Qt::Unchecked);
    ui->eroBx->setCheckState(Qt::Unchecked);
    ui->diaBx->setCheckState(Qt::Unchecked);
    ui->brightBtn->setCheckState(Qt::Unchecked);

    // clear text boxes
    ui->brightNum->clear();
    ui->hpKern->clear();
    ui->lpKern->clear();
    ui->threshVal->clear();
    ui->gausKern->clear();
    ui->sobKern->clear();
    ui->eroKern->clear();
    ui->diaKern->clear();

    // reset image to original image
    img->reset();

    // make image grayscale
    img->makeGray();
}

//  on_viewImageBtn: displays new window with original loaded Img* image obj
//
//  Input:
//  Output:
//
void MainWindow::on_viewImageBtn()
{
    img->displayOgImg();
}

//  on_viewNewImageBtn: calls enhancement and segmentation methods with Img* obj
//
//  Input:
//  Output:
//
void MainWindow::on_viewNewImageBtn()
{
    modifier = "";

    // Enhancement processes
    if (ui->histBx->isChecked())
    {
        e->histogramEquilization();
        modifier += " hist equil";
    }
    if (ui->hpBx->isChecked())
    {
        e->highPassFilter(ui->hpKern->text().toInt());
        modifier = modifier +  " hp " + ui->hpKern->text().toStdString();
    }
    if (ui->lpBx->isChecked())
    {
        e->lowPassFilter(ui->lpKern->text().toInt());
        modifier = modifier +  " lp " + ui->lpKern->text().toStdString();
    }
    if (ui->brightBtn->isChecked())
    {
        e->brightness(ui->brightNum->text().toInt());
        modifier = modifier +  " brightness" + ui->brightNum->text().toStdString();
    }

    // Segmentation processes
    if (ui->threshBx->isChecked())
    {
        s->thresh(ui->threshVal->text().toInt());
        modifier += " thresh";
    }
    if (ui->gausBx->isChecked())
    {
        if ((ui->gausKern->text().toInt() > 0) && (ui->gausKern->text().toInt() % 2 == 1))
        {
            s->gauss(ui->gausKern->text().toInt());
            modifier = modifier +  " gauss " + ui->gausKern->text().toStdString();
        }
        else
        {
            printOddError("Kernel must be >=0 and odd.");
            return;
        }
    }
    if (ui->sobBx->isChecked())
    {
        if ((ui->sobKern->text().toInt() <= 31) && (ui->sobKern->text().toInt() % 2 == 1))
        {
            s->sobel(ui->sobKern->text().toInt());
            modifier = modifier +  " sob " + ui->sobKern->text().toStdString();
        }
        else
        {
            printOddError("Kernel must be odd and <= 31");
            return;
        }
    }
    if (ui->eroBx->isChecked())
    {
        s->erosion(ui->eroKern->text().toInt());
        modifier = modifier +  " erosion " + ui->eroKern->text().toStdString();
    }
    if (ui->diaBx->isChecked())
    {
        s->dialation(ui->diaKern->text().toInt());
        modifier = modifier +  " dialation " + ui->diaKern->text().toStdString();
    }
    // Dislay the newly modified image
    img->displayImg(modifier);
}

//  on_saveImageBtn: saves modified image using title modifier with all the applied operations
//
//  Input:
//  Output:
//
void MainWindow::on_saveImageBtn()
{
    img->saveImage(modifier);
}

