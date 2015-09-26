TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CFLAGS += -std=c11

SOURCES += main.c \
    functions.c \
    ../in.c

HEADERS += \
    functions.h \
    list.h \
    ../in.h

