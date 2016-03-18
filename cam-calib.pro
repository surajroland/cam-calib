#-------------------------------------------------
#
# Project created by QtCreator 2016-03-18T13:55:37
#
#-------------------------------------------------

QT       += core gui
Qt       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cam-calib
TEMPLATE = app


SOURCES +=  main.cpp\
            gui/mainwindow.cpp

HEADERS  += gui/mainwindow.h\
            gui/displaywidget.h

FORMS    += gui/mainwindow.ui
