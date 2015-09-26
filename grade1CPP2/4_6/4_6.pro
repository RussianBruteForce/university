TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    mylist.cpp \
    mylib.cpp

include(deployment.pri)
qtcAddDeployment()

