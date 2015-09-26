TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

QMAKE_CXXFLAGS += -fexceptions

include(deployment.pri)
qtcAddDeployment()

SOURCES += main.cpp

HEADERS += \
    doublylinkedlist.h \
    listExcp.h

