#-------------------------------------------------
#
# Project created by QtCreator 2015-02-27T23:02:03
#
#-------------------------------------------------
# $3.3
# The original code example is for MFC.
# You should reference $1.6 to check how to use QFileDialog to pick up a file.
# And the OK and CANCEL button not worked.
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Controller
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    main.h

FORMS    += mainwindow.ui
INCLUDEPATH += /usr/local/include \
               /usr/local/include/opencv2 \
               /usr/local/include/opencv
LIBS += /usr/local/lib/libopencv_core.so \
        /usr/local/lib/libopencv_highgui.so \
        /usr/local/lib/libopencv_imgproc.so
