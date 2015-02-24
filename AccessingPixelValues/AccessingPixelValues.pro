#-------------------------------------------------
#
# Project created by QtCreator 2015-02-23T22:21:57
#
#-------------------------------------------------
# $2.2 Accessing Pixel Values
# $2.3

QT       += core

QT       -= gui

TARGET = AccessingPixelValues
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

INCLUDEPATH += /usr/local/include \
                /usr/local/include/opencv \
                /usr/local/include/opencv2

LIBS += /usr/local/lib/libopencv_highgui.so \
        /usr/local/lib/libopencv_core.so    \
        /usr/local/lib/libopencv_imgproc.so
