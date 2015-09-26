TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    taylor.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS +=

