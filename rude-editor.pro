#-------------------------------------------------
#
# Project created by QtCreator 2014-03-29T13:52:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rude-editor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialoginput.cpp \
    dialogopenfile.cpp \
    filesystem.cpp \
    dialogmessage.cpp \
    semaphore.cpp \
    sharedmemory.cpp \
    process.cpp

HEADERS  += mainwindow.h \
    dialoginput.h \
    dialogopenfile.h \
    filesystem.h \
    dialogmessage.h \
    semaphore.h \
    sharedmemory.h \
    process.h

FORMS    += mainwindow.ui
