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
    connect(histBx, &QCheckBox::clicked, this, &MainWindow::on_histBx_clicked);
    connect(hpBx, &QCheckBox::clicked, this, &MainWindow::on_hpBx_clicked);
    connect(lpBx, &QCheckBox::clicked, this, &MainWindow::on_lpBx_clicked);

    // Segmentation check boxes
    connect(threshBx, &QCheckBox::clicked, this, &MainWindow::on_threshBx_clicked);
    connect(kirBx, &QCheckBox::clicked, this, &MainWindow::on_kirBx_clicked);
    connect(gausBx, &QCheckBox::clicked, this, &MainWindow::on_gausBx_clicked);
    connect(prewBx, &QCheckBox::clicked, this, &MainWindow::on_prewBx_clicked);
    connect(waterBx, &QCheckBox::clicked, this, &MainWindow::on_waterBx_clicked);
    connect(sobBx, &QCheckBox::clicked, this, &MainWindow::on_sobBx_clicked);
    connect(eroBx, &QCheckBox::clicked, this, &MainWindow::on_eroBx_clicked);
    connect(diaBx, &QCheckBox::clicked, this, &MainWindow::on_diaBx_clicked);
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
    *img = new img(filename);
}

//  on_viewImageBtn_clicked: dislays new window with Img* image obj
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