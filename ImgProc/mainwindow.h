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

private:
    Ui::MainWindow *ui;
    Image *img;
    QString filename;
};
#endif // MAINWINDOW_H
