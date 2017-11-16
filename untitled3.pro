#-------------------------------------------------
#
# Project created by QtCreator 2017-11-04T23:29:26
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = untitled3
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS
SOURCES += main.cpp\
        mainwindow.cpp \
    mainscene.cpp \
    lefttoolbar.cpp \
    toptoolbar.cpp \
    tools/abstracttool.cpp \
    figures/fpolyline.cpp \
    figures/abstractfigure.cpp \
    tools/tpolyline.cpp \
    tools/trectangle.cpp \
    figures/frect.cpp \
    figures/fellipse.cpp \
    tools/tellipse.cpp \
    figures/fline.cpp \
    tools/tline.cpp \
    tools/tmagnifier.cpp \
    fixedsize.cpp

HEADERS  += mainwindow.h \
    mainscene.h \
    lefttoolbar.h \
    toptoolbar.h \
    tools/abstracttool.h \
    figures/fpolyline.h \
    figures/abstractfigure.h \
    tools/tpolyline.h \
    tools/trectangle.h \
    sceneinfo.h \
    figures/frect.h \
    figures/fellipse.h \
    tools/tellipse.h \
    figures/fline.h \
    tools/tline.h \
    tools/tmagnifier.h \
    fixedsize.h

FORMS    += mainwindow.ui







