#-------------------------------------------------
#
# Project created by QtCreator 2015-02-26T23:00:30
#
#-------------------------------------------------
# $3.2 Strategy Pattern
QT       += core

QT       -= gui

TARGET = Strategy
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp
INCLUDEPATH += /usr/local/include/opencv2\
               /usr/local/include/opencv\
               /usr/local/include
LIBS += /usr/local/lib/libopencv_highgui.so\
        /usr/local/lib/libopencv_core.so\
        /usr/local/lib/libopencv_imgproc.so
