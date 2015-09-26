TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CFLAGS += -std=c11

SOURCES += main.c \
    functions.c \
    ../in.c

HEADERS += \
    ../in.h \
    functions.h \
    note.h

