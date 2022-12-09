#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <regex>

// regular expressions to filter out non int numbers for only pos and pos & neg numbers
#define REG_NEG regex("(^-?0\.[0-9]*[1-9]+[0-9]*$)|(^-?[1-9]+[0-9]*((\.[0-9]*[1-9]+[0-9]*$)|(\.[0-9]+)))|(^-?[1-9]+[0-9]*$)|(^0$){1}")
#define REG_POS regex("^[1-9]+[0-9]*$")

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

//  ~MainWindow: deallocates memory
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
    // Show error window if kernel size isn't odd or other unique text error
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
    // read from images in current directory
    std::string name = "images/";
    std::filesystem::path cwd = std::filesystem::current_path() / name;
    filename = QFileDialog::getOpenFileName(this, "Choose File",
                                            QString::fromStdString(cwd.string()),
                                            tr("*.png *.jpg *.jpeg *.bmp *.dib *.jpe *.jp2 *.webp *.pbm, *.pgm, *.ppm *.pxm, *.pnm *.sr, *.ras *.tiff, *.tif *.exr *.hdr, *.pic"));

    ui->filePathTxt->clear();
    ui->filePathTxt->setPlainText(filename);
}

//  on_openImageBtn: creates Img* obj using filepath to the image, and Enhancement and Segmentation objs with Img*
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
    ui->colorMpBtn->setCheckState(Qt::Unchecked);

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

    // Histogram
    if (ui->histBx->isChecked())
    {
        e->histogramEquilization();
        modifier += " hist equil";
    }
    // High Pass
    if (ui->hpBx->isChecked())
    {

        try
        {
            if (regex_match(ui->hpKern->text().toStdString(), REG_NEG))
            {
                e->highPassFilter(ui->hpKern->text().toInt());
                modifier = modifier +  " hp " + ui->hpKern->text().toStdString();
            }
           else throw std::invalid_argument( "received wrong type of value" );
        }
        catch( const std::invalid_argument& e )
        {
            printOddError("Kernel must be int and >= 0");
            return;
        }
    }
    // Low Pass
    if (ui->lpBx->isChecked())
    {
        try
        {
            if (regex_match(ui->lpKern->text().toStdString(), REG_NEG))
            {
                e->lowPassFilter(ui->lpKern->text().toInt());
                modifier = modifier +  " lp " + ui->lpKern->text().toStdString();
            }
            else throw std::invalid_argument( "received wrong type of value" );
        }
        catch( const std::invalid_argument& e )
        {
            printOddError("Kernel must be int and >= 0");
            return;
        }
    }
    // Brightness
    if (ui->brightBtn->isChecked())
    {
        try
        {
            if (regex_match(ui->brightNum->text().toStdString(), REG_NEG))
            {
                e->brightness(ui->brightNum->text().toInt());
                modifier = modifier +  " brightness " + ui->brightNum->text().toStdString();
            }
            else throw std::invalid_argument( "received wrong type of value" );
        }
        catch( const std::invalid_argument& e )
        {
            printOddError("Kernel must be int and >= 0");
            return;
        }
    }
    // Color map
    if (ui->colorMpBtn->isChecked())
    {
        modifier = modifier +  " color";
        if (ui->colorMpBx->currentText().toStdString() == "Autumn")
        {
            e->colorMap(COLORMAP_AUTUMN);
            modifier += "_au";
        }
        else if (ui->colorMpBx->currentText().toStdString() == "Bone")
        {
            e->colorMap(COLORMAP_BONE);
            modifier += "_bon";
        }
        else if (ui->colorMpBx->currentText().toStdString() == "Jet")
        {
            e->colorMap(COLORMAP_JET);
            modifier += "_jet";
        }
        else if (ui->colorMpBx->currentText().toStdString() == "Winter")
        {
            e->colorMap(COLORMAP_WINTER);
            modifier += "_win";
        }
        else if (ui->colorMpBx->currentText().toStdString() == "Rainbow")
        {
            e->colorMap(COLORMAP_RAINBOW);
            modifier += "_rai";
        }
        else if (ui->colorMpBx->currentText().toStdString() == "Ocean")
        {
            e->colorMap(COLORMAP_OCEAN);
            modifier += "_ocea";
        }
        else if (ui->colorMpBx->currentText().toStdString() == "Summer")
        {
            e->colorMap(COLORMAP_SUMMER);
            modifier += "_sum";
        }
        else if (ui->colorMpBx->currentText().toStdString() == "Spring")
        {
            e->colorMap(COLORMAP_SPRING);
            modifier += "_spri";
        }
        else if (ui->colorMpBx->currentText().toStdString() == "Cool")
        {
            e->colorMap(COLORMAP_COOL);
            modifier += "_coo";
        }
        else if (ui->colorMpBx->currentText().toStdString() == "HSV")
        {
            e->colorMap(COLORMAP_HSV);
            modifier += "_h";
        }
        else if (ui->colorMpBx->currentText().toStdString() == "Pink")
        {
            e->colorMap(COLORMAP_PINK);
            modifier += "_pi";
        }
        else if (ui->colorMpBx->currentText().toStdString() == "Hot")
        {
            e->colorMap(COLORMAP_HOT);
            modifier += "_ho";
        }
        else if (ui->colorMpBx->currentText().toStdString() == "Parula")
        {
            e->colorMap(COLORMAP_PARULA);
            modifier += "_par";
        }
        else if (ui->colorMpBx->currentText().toStdString() == "Magma")
        {
            e->colorMap(COLORMAP_MAGMA);
            modifier += "_mag";
        }
        else if (ui->colorMpBx->currentText().toStdString() == "Inferno")
        {
            e->colorMap(COLORMAP_INFERNO);
            modifier += "_inf";
        }
        else if (ui->colorMpBx->currentText().toStdString() == "Plasma")
        {
            e->colorMap(COLORMAP_PLASMA);
            modifier += "_plas";
        }
        else if (ui->colorMpBx->currentText().toStdString() == "Viridis")
        {
            e->colorMap(COLORMAP_VIRIDIS);
            modifier += "_vir";
        }
        else if (ui->colorMpBx->currentText().toStdString() == "Cividis")
        {
            e->colorMap(COLORMAP_CIVIDIS);
            modifier += "_civ";
        }
        else if (ui->colorMpBx->currentText().toStdString() == "Twilight")
        {
            e->colorMap(COLORMAP_TWILIGHT);
            modifier += "_twi";
        }
        else if (ui->colorMpBx->currentText().toStdString() == "TwilightShifted")
        {
            e->colorMap(COLORMAP_TWILIGHT_SHIFTED);
            modifier += "_twis";
        }
        else if (ui->colorMpBx->currentText().toStdString() == "Turbo")
        {
            e->colorMap(COLORMAP_TURBO);
            modifier += "_tur";
        }
        else if (ui->colorMpBx->currentText().toStdString() == "DeepGreen")
        {
            e->colorMap(COLORMAP_DEEPGREEN);
            modifier += "_dg";
        }
    }

    // Segmentation processes

    // Threshold
    if (ui->threshBx->isChecked())
    {
        try
        {
            if (ui->threshVal->text().toInt() >= 0 && ui->threshVal->text().toInt() <= 255 && regex_match(ui->threshVal->text().toStdString(), REG_POS))
            {
                s->thresh(ui->threshVal->text().toInt());
                modifier += " thresh";
            }
            else throw std::invalid_argument( "received wrong type of value" );
        }
        catch( const std::invalid_argument& e )
        {
            printOddError("Threshold must be within int and 0-255.");
            return;
        }
    }
    // Gaussian Blur
    if (ui->gausBx->isChecked())
    {
        try
        {
            if (ui->gausKern->text().toInt() > 0 && ui->gausKern->text().toInt() % 2 == 1 && regex_match(ui->gausKern->text().toStdString(), REG_POS))
            {
                s->gauss(ui->gausKern->text().toInt());
                modifier = modifier +  " gauss " + ui->gausKern->text().toStdString();
            }
            else throw std::invalid_argument( "received wrong type of value" );
        }
        catch( const std::invalid_argument& e )
        {
            printOddError("Kernel must int, >=0, and odd.");
            return;
        }
    }
    // Sobel
    if (ui->sobBx->isChecked())
    {
        try
        {
            if (ui->sobKern->text().toInt() <= 31 && ui->sobKern->text().toInt() % 2 == 1 && regex_match(ui->sobKern->text().toStdString(), REG_POS))
            {
                s->sobel(ui->sobKern->text().toInt());
                modifier = modifier +  " sob " + ui->sobKern->text().toStdString();
            }
            else throw std::invalid_argument( "received wrong type of value" );
        }
        catch( const std::invalid_argument& e )
        {
            printOddError("Kernel must be int, <= 31, and odd");
            return;
        }
    }
    // Erosion
    if (ui->eroBx->isChecked())
    {
        try
        {
            if (ui->eroKern->text().toInt() >= 0 && regex_match(ui->eroKern->text().toStdString(), REG_POS))
            {
                s->erosion(ui->eroKern->text().toInt());
                modifier = modifier +  " erosion " + ui->eroKern->text().toStdString();
            }
            else throw std::invalid_argument( "received wrong type of value" );
        }
        catch( const std::invalid_argument& e )
        {
            printOddError("Kernel must be int and >= 0");
            return;
        }
    }
    // Dialation
    if (ui->diaBx->isChecked())
    {
        try
        {
            if (ui->diaKern->text().toInt() >= 0 && regex_match(ui->diaKern->text().toStdString(), REG_POS))
            {
                s->dialation(ui->diaKern->text().toInt());
                modifier = modifier +  " dialation " + ui->diaKern->text().toStdString();
            }
            else throw std::invalid_argument( "received wrong type of value" );
        }
        catch( const std::invalid_argument& e )
        {
            printOddError("Kernel must be >= 0");
            return;
        }
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

