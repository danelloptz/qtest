TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    myfunc.c \
    urav.c

HEADERS += \
    myfunc.h \
    urav.h

QMAKE_CFLAGS += -Wall -Wextra

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
