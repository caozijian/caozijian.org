#-------------------------------------------------
#
# Project created by QtCreator 2015-03-01T10:30:33
#
#-------------------------------------------------
# $3.4 Sigleton
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Singleton
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    main.h

FORMS    += mainwindow.ui
INCLUDEPATH += /usr/local/include\
               /usr/local/include/opencv2\
               /usr/local/include/opencv/
LIBS += /usr/local/lib/libopencv_core.so\
        /usr/local/lib/libopencv_highgui.so\
        /usr/local/lib/libopencv_imgproc.so
