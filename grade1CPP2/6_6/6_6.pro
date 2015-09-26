TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    mystring.cpp \
    myarrau.cpp

include(deployment.pri)
qtcAddDeployment()

