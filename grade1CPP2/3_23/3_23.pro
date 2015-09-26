TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    profiler_and_sorting.cpp

HEADERS += \
    profiler_and_sorting.h \
    hoare.h

