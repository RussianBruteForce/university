TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

CONFIG += c++11

SOURCES += main.cpp \
        ../in.c

include(deployment.pri)
qtcAddDeployment()


HEADERS += \
    ../in.h

