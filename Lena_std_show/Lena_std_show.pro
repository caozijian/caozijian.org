#-------------------------------------------------
#
# Project created by QtCreator 2015-02-22T23:53:20
#
#-------------------------------------------------
# OpenCV 2 Computer Vision Application Programming Cookbook
# $1.5 Loading, Displaying, and saving images

# Call by qmake
# If you want to provide cross plaform support, should do something in this file.
# like
# unix{
# }
# win32{
# }
#

QT       += core

QT       -= gui

TARGET = Lena_std_show
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    Lena_std_show.cpp
INCLUDEPATH += /usr/local/include \
                /usr/local/include/opencv \
                /usr/local/include/opencv2

LIBS += /usr/local/lib/libopencv_highgui.so \
        /usr/local/lib/libopencv_core.so    \
        /usr/local/lib/libopencv_imgproc.so
