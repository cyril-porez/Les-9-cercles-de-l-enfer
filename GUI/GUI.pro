QT += core gui widgets

TARGET = GUI
TEMPLATE = app

SOURCES += \
    ../../src/main.cpp \
    ../../src/mainwindow.cpp \
    ../../src/homescreen.cpp \
    ../../src/clientlistitem.cpp

HEADERS += \
    ../../src/../headers/mainwindow.h \
    ../../src/../headers/homescreen.h \
    ../../src/../headers/clientlistitem.h

FORMS += \
    ../../src/mainwindow.ui \
    ../../src/homescreen.ui \
    ../../src/clientlistitem.ui

INCLUDEPATH += $$PWD/../../src/../headers
