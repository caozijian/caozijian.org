#-------------------------------------------------
#
# Project created by QtCreator 2015-02-24T10:25:11
#
#-------------------------------------------------
# $2.5 Writing efficient image scanning loops
# -5,7,8,9
# -isContinuous();

QT       += core

QT       -= gui

TARGET = WritingEfficientImageScanningLoops
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
