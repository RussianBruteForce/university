TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qtS
QMAKE_CFLAGS += -std=c11

SOURCES += main.c \
    func.c \
    ../in.c

HEADERS += \
    ../in.h \
    func.h \
    aeroflot.h

