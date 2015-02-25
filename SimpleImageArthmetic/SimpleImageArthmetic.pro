#-------------------------------------------------
#
# Project created by QtCreator 2015-02-25T18:56:11
#
#-------------------------------------------------
# $2.7, $2.8
# Attention imread's parameters.
QT       += core

QT       -= gui

TARGET = SimpleImageArthmetic
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp
# Oh, MGD, I forget the "/"
#INCLUDEPATH += usr/local/include \
#               usr/local/include/opencv \
#               usr/local/include/opencv2

#LIBS += usr/local/lib/libopencv_highgui.so \
#        usr/local/lib/libopencv_core.so \
#        usr/local/lib/libopencv_imgproc.so

INCLUDEPATH += /usr/local/include \
                /usr/local/include/opencv \
                /usr/local/include/opencv2

LIBS += /usr/local/lib/libopencv_highgui.so \
        /usr/local/lib/libopencv_core.so    \
        /usr/local/lib/libopencv_imgproc.so
