TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    database.cpp \
    garagedatabase.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    list.h \
    database.h \
    garagedatabase.h \
    bus.h \
    antifool.h

