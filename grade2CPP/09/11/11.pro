TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    taylor_series.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    taylor_series.h \
    antifool.h

