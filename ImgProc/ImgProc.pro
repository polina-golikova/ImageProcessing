QT       += core gui widgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Enhancement.cpp \
    Image.cpp \
    Segmentation.cpp \
    main.cpp \
    mainwindow.cpp \
    Image.cpp \
    Enhancement.cpp \
    Segmentation.cpp

HEADERS += \
    Enhancement.h \
    Image.h \
    Segmentation.h \
    mainwindow.h \
    Image.h \
    Enhancement.h \
    Segmentation.h

FORMS += \
    mainwindow.ui

INCLUDEPATH += "C:/Program Files (x86)/opencv/build/include/"
LIBS += "C:/Program Files (x86)/opencv/build/bin/*.dll"

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
