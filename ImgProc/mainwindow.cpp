#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

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
    connect(ui->loadImgBtn, SIGNAL(clicked()), this,SLOT(on_filePathTxt_clicked()));
    connect(ui->openImageBtn, SIGNAL(clicked()), this, SLOT(on_openImageBtn_clicked()));
    connect(ui->viewImageBtn, SIGNAL(clicked()), this, SLOT(on_viewImageBtn_clicked()));
    connect(ui->viewNewImageBtn, SIGNAL(clicked()), this, SLOT(on_viewNewImageBtn_clicked()));
    connect(ui->saveImageBtn, SIGNAL(clicked()), this, SLOT(on_saveImageBtn_clicked()));

    // Enhancement check boxes
    connect(ui->histBx, SIGNAL(clicked(bool)), this, SLOT(on_histBx_clicked(bool)));
    connect(ui->hpBx, SIGNAL(clicked(bool)), this, SLOT(on_hpBx_clicked(bool)));
    connect(ui->lpBx, SIGNAL(clicked(bool)), this, SLOT(on_lpBx_clicked(bool)));

    // Segmentation check boxes
    connect(ui->threshBx, SIGNAL(clicked(bool)), this, SLOT(on_threshBx_clicked(bool)));
    connect(ui->kirBx, SIGNAL(clicked(bool)), this, SLOT(on_kirBx_clicked(bool)));
    connect(ui->gausBx, SIGNAL(clicked(bool)), this, SLOT(on_gausBx_clicked(bool)));
    connect(ui->prewBx, SIGNAL(clicked(bool)), this, SLOT(on_prewBx_clicked(bool)));
    connect(ui->waterBx, SIGNAL(clicked(bool)), this, SLOT(on_waterBx_clicked(bool)));
    connect(ui->sobBx, SIGNAL(clicked(bool)), this, SLOT(on_sobBx_clicked(bool)));
    connect(ui->eroBx, SIGNAL(clicked(bool)), this, SLOT(on_eroBx_clicked(bool)));
    connect(ui->diaBx, SIGNAL(clicked(bool)), this, SLOT(on_diaBx_clicked(bool)));
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
}

//  on_filePathTxt_clicked: saves user defined image file path and outputs to window
//
//  Input:
//  Output:
//
void MainWindow::on_filePathTxt_clicked()
{
    filename = QFileDialog::getOpenFileName(this, "Choose File");

    if(filename.isEmpty())
        return;

    ui->filePathTxt->clear();
    ui->filePathTxt->setPlainText(filename);
}

//  on_openImageBtn_clicked: creates Img* obj using filepath to the image
//
//  Input:
//  Output:
//
void MainWindow::on_openImageBtn_clicked()
{
    Image i(filename.toStdString());
    img = &i;
    Enhancement enh(img);
    Segmentation seg(img);
    e = &enh;
    s = &seg;
}

//  on_viewImageBtn_clicked: displays new window with Img* image obj
//
//  Input:
//  Output:
//
void MainWindow::on_viewImageBtn_clicked()
{
    img->displayOgImg();
}

void MainWindow::on_viewNewImageBtn_clicked()
{
    img->displayImg();
}

void MainWindow::on_saveImageBtn_clicked()
{
    img->saveImage();
}

void MainWindow::on_histBx_clicked(bool checked)
{
    if (checked)
    {
        e->histogramEquilization();
    }
}

void MainWindow::on_hpBx_clicked(bool checked)
{
    if (checked)
    {
        e->highPassFilter();
    }
}

void MainWindow::on_lpBx_clicked(bool checked)
{
    if (checked)
    {
        e->lowPassFilter();
    }
}

void MainWindow::on_threshBx_clicked(bool checked)
{
    if (checked)
    {
        s->thresh(ui->threshVal->text().toInt());
    }
}

void MainWindow::on_kirBx_clicked(bool checked)
{
    if (checked)
    {

    }
}
void MainWindow::on_gausBx_clicked(bool checked)
{
    if (checked)
    {

    }
}

void MainWindow::on_prewBx_clicked(bool checked)
{
    if (checked)
    {

    }
}

void MainWindow::on_waterBx_clicked(bool checked)
{
    if (checked)
    {

    }
}

void MainWindow::on_sobBx_clicked(bool checked)
{
    if (checked)
    {

    }
}

void MainWindow::on_eroBx_clicked(bool checked)
{
    if (checked)
    {

    }
}

void MainWindow::on_diaBx_clicked(bool checked)
{
    if (checked)
    {

    }
}
