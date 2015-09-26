#-------------------------------------------------
#
# Project created by QtCreator 2015-04-07T22:22:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 6_25
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        mt.cpp \
    mtmodel.cpp

HEADERS  += mt.h \
    mtmodel.h \
    doublylinkedlist.h

FORMS    += mt.ui
