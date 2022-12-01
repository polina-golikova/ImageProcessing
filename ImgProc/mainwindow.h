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
private:
    Ui::MainWindow *ui;
    Image *img;
    Enhancement *e;
    Segmentation *s;
    QString filename;
    std::string modifier;
private slots:
    void on_openImageBtn();
    void on_filePathTxt();
    void on_viewImageBtn();
    void on_clear();
    void on_viewNewImageBtn();
    void on_saveImageBtn();
};
#endif // MAINWINDOW_H
