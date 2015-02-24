#-------------------------------------------------
#
# Project created by QtCreator 2015-02-24T12:24:33
#
#-------------------------------------------------
# $2.6 Scanning an image with neighbor access
# Oh, I think this code have some bug. Because the result image is not same as figure 2.4 on page 48.
QT       += core

QT       -= gui

TARGET = ScanningAnImageWithNeighborAccess
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
