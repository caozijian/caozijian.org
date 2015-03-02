#-------------------------------------------------
#
# Project created by QtCreator 2015-03-01T16:21:20
#
#-------------------------------------------------
# $4.2 $4.3
# lookup table can do some image process work.
# $4.4
QT       += core

QT       -= gui

TARGET = Histogram1D
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    histogram1d.cpp

HEADERS += \
    histogram1d.h
INCLUDEPATH +=  /usr/local/include \
                /usr/local/include/opencv2\
                /usr/local/include/opencv
LIBS += /usr/local/lib/libopencv_core.so\
        /usr/local/lib/libopencv_highgui.so\
        /usr/local/lib/libopencv_imgproc.so
