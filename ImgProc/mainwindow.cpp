#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    connect(filePathTxt, &QPushButton::released, this, &MainWindow::on_filePathTxt_clicked);
    connect(openImageBtn, &QPushButton::released, this, &MainWindow::on_openImageBtn_clicked);
    connect(viewImageBtn, &QPushButton::released, this, &MainWindow::on_viewImageBtn_clicked);
    connect(viewNewImageBtn, &QPushButton::released, this, &MainWindow::on_viewNewImageBtn_clicked);
    connect(saveImageBtn, &QPushButton::released, this, &MainWindow::on_saveImageBtn_clicked);

    // Enhancement check boxes
    connect(histBx, SIGNAL(clicked(bool)), this, SLOT(on_histBx_clicked(bool)));
    connect(hpBx, SIGNAL(clicked(bool)), this, SLOT(on_hpBx_clicked(bool)));
    connect(lpBx, SIGNAL(clicked(bool)), this, SLOT(on_lpBx_clicked(bool)));

    // Segmentation check boxes
    connect(threshBx, SIGNAL(clicked(bool)), this, SLOT(on_threshBx_clicked(bool)));
    connect(kirBx, SIGNAL(clicked(bool)), this, SLOT(on_kirBx_clicked(bool)));
    connect(gausBx, SIGNAL(clicked(bool)), this, SLOT(on_gausBx_clicked(bool)));
    connect(prewBx, SIGNAL(clicked(bool)), this, SLOT(on_prewBx_clicked(bool)));
    connect(waterBx, SIGNAL(clicked(bool)), this, SLOT(on_waterBx_clicked(bool)));
    connect(sobBx, SIGNAL(clicked(bool)), this, SLOT(on_sobBx_clicked(bool)));
    connect(eroBx, SIGNAL(clicked(bool)), this, SLOT(on_eroBx_clicked(bool)));
    connect(diaBx, SIGNAL(clicked(bool)), this, SLOT(on_diaBx_clicked(bool)));
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
    *img = new Image(filename);
    *e = new Enhancement(img);
    *s = new Segmentation(img);
}

//  on_viewImageBtn_clicked: displays new window with Img* image obj
//
//  Input:
//  Output:
//
void MainWindow::on_viewImageBtn_clicked()
{
    img.displayOgImg();
}

void MainWindow::on_viewNewImageBtn_clicked()
{
    img.displayImg();
}

void MainWindow::on_saveImageBtn_clicked()
{
    img.saveImage();
}

void MainWindow::on_histBx_clicked(bool checked)
{
    if (checked)
    {
        e.histogramEquilization();
    }
}

void MainWindow::on_hpBx_clicked(bool checked)
{
    if (checked)
    {
        e.highPassFilter()
    }
}

void MainWindow::on_lpBx_clicked(bool checked)
{
    if (checked)
    {
        e.lowPassFilter();
    }
}

void MainWindow::on_threshBx_clicked(bool)
{
    if (checked)
    {

    }
}

void MainWindow::on_kirBx_clicked(bool)
{
    if (checked)
    {

    }
}
void MainWindow::on_gausBx_clicked(bool)
{
    if (checked)
    {

    }
}

void MainWindow::on_prewBx_clicked(bool)
{
    if (checked)
    {

    }
}

void MainWindow::on_waterBx_clicked(bool)
{
    if (checked)
    {

    }
}

void MainWindow::on_sobBx_clicked(bool)
{
    if (checked)
    {

    }
}

void MainWindow::on_eroBx_clicked(bool)
{
    if (checked)
    {

    }
}

void MainWindow::on_diaBx_clicked(bool)
{
    if (checked)
    {

    }
}
