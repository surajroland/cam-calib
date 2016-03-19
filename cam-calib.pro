#-------------------------------------------------
#
# Project created by QtCreator 2016-03-18T13:55:37
#
#-------------------------------------------------

QT       += core
QT       += gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
TARGET = opencv
TEMPLATE = app
DESTDIR = $$PWD
INCLUDEPATH += /usr/include/opencv \
    ./resources

LIBS += -L/lib -I/usr/include/opencv -lopencv_core -lopencv_cudaimgproc -lopencv_cudaobjdetect -lopencv_imgcodecs -lopencv_imgproc -lopencv_objdetect -lopencv_video -lopencv_videoio -lopencv_videostab


TARGET = cam-calib
TEMPLATE = app


SOURCES +=  main.cpp\
            gui/mainwindow.cpp\
            processors/improc.cpp

HEADERS  += gui/mainwindow.h \
            processors/improc.h

FORMS    += gui/mainwindow.ui
