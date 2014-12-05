#-------------------------------------------------
#
# Project created by QtCreator 2014-12-02T22:56:16
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ClientGeomarketing
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mytcpsocket.cpp

HEADERS  += mainwindow.h \
    mytcpsocket.h

FORMS    += mainwindow.ui
