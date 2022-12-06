#include "mainwindow.h"

#include <QApplication>

//  main: generated GUI obj and envokes method to build the UI
//
//  Input:  int - user terminal I/O
//          char - user terminal I/O
//  Output:
//
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Image Processing App");
    w.show();
    return a.exec();
}
