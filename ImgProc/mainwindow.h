#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Image.h"
#include "Enhancement.h"
#include "Segmentation.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void on_filePathTxt_clicked();
    void on_openImageBtn_clicked();
    void on_viewImageBtn_clicked();
    void on_viewNewImageBtn_clicked();
    void on_saveImageBtn_clicked();
    void on_histBx_clicked(bool);
    void on_hpBx_clicked(bool);
    void on_lpBx_clicked(bool);
    void on_threshBx_clicked(bool);
    void on_kirBx_clicked(bool);
    void on_gausBx_clicked(bool);
    void on_prewBx_clicked(bool);
    void on_waterBx_clicked(bool);
    void on_sobBx_clicked(bool);
    void on_eroBx_clicked(bool);
    void on_diaBx_clicked(bool);
private:
    Ui::MainWindow *ui;
    Image *img;
    Enhancement *e;
    Segmentation *s;
    QString filename;
};
#endif // MAINWINDOW_H
