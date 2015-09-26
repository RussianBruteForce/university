TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    mylist.cpp \
    mylist2.cpp

include(deployment.pri)
qtcAddDeployment()

