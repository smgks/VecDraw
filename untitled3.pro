#-------------------------------------------------
#
# Project created by QtCreator 2017-11-04T23:29:26
#
#-------------------------------------------------

QT       += core gui svg xml widgets
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
    tools/tpolyline.cpp \
    tools/trectangle.cpp \
    figures/frect.cpp \
    figures/fellipse.cpp \
    tools/tellipse.cpp \
    figures/fline.cpp \
    tools/tline.cpp \
    tools/tmagnifier.cpp \
    fixedsize.cpp \
    tools/tselection.cpp \
    figures/abstractfigure.cpp \
    toolbtns/abstractTB.cpp \
    tools/cursor.cpp \
    toolbtns/penradius.cpp \
    toolbtns/pencolor.cpp \
    toolbtns/brushstyle.cpp \
    toolbtns/brushcolor.cpp \
    toolbtns/recta.cpp \
    svgreader.cpp \
    vgi.cpp \
    loadfromvgi.cpp \
    figures/abstractfigure.cpp \
    figures/fellipse.cpp \
    figures/fline.cpp \
    figures/fpolyline.cpp \
    figures/frect.cpp \
    toolbtns/abstractTB.cpp \
    toolbtns/brushcolor.cpp \
    toolbtns/brushstyle.cpp \
    toolbtns/pencolor.cpp \
    toolbtns/penradius.cpp \
    toolbtns/recta.cpp \
    tools/abstracttool.cpp \
    tools/cursor.cpp \
    tools/tellipse.cpp \
    tools/tline.cpp \
    tools/tmagnifier.cpp \
    tools/tpolyline.cpp \
    tools/trectangle.cpp \
    tools/tselection.cpp \
    fixedsize.cpp \
    lefttoolbar.cpp \
    loadfromvgi.cpp \
    main.cpp \
    mainscene.cpp \
    mainwindow.cpp \
    svgreader.cpp \
    toptoolbar.cpp \
    vgi.cpp \
    urGroups/abstractevent.cpp \
    urGroups/addfigureevent.cpp \
    urGroups/removefigureevent.cpp
HEADERS  += mainwindow.h \
    mainscene.h \
    lefttoolbar.h \
    toptoolbar.h \
    tools/abstracttool.h \
    figures/fpolyline.h \
    tools/tpolyline.h \
    tools/trectangle.h \
    sceneinfo.h \
    figures/frect.h \
    figures/fellipse.h \
    tools/tellipse.h \
    figures/fline.h \
    tools/tline.h \
    tools/tmagnifier.h \
    fixedsize.h \
    tools/tselection.h \
    figures/abstractfigure.h \
    toolbtns/abstractTB.h \
    tools/cursor.h \
    toolbtns/penradius.h \
    toolbtns/pencolor.h \
    toolbtns/brushstyle.h \
    toolbtns/brushcolor.h \
    toolbtns/recta.h \
    svgreader.h \
    vgi.h \
    loadfromvgi.h \
    figures/abstractfigure.h \
    figures/fellipse.h \
    figures/fline.h \
    figures/fpolyline.h \
    figures/frect.h \
    toolbtns/abstractTB.h \
    toolbtns/brushcolor.h \
    toolbtns/brushstyle.h \
    toolbtns/pencolor.h \
    toolbtns/penradius.h \
    toolbtns/recta.h \
    tools/abstracttool.h \
    tools/cursor.h \
    tools/tellipse.h \
    tools/tline.h \
    tools/tmagnifier.h \
    tools/tpolyline.h \
    tools/trectangle.h \
    tools/tselection.h \
    fixedsize.h \
    lefttoolbar.h \
    loadfromvgi.h \
    mainscene.h \
    mainwindow.h \
    sceneinfo.h \
    svgreader.h \
    toptoolbar.h \
    ui_mainwindow.h \
    vgi.h \
    urGroups/addfigureevent.h \
    urGroups/removefigureevent.h
FORMS    += mainwindow.ui
#══════════████████═════██████
#═════════█░░░░░░░░██═██░░░░░░█
#════════█░░░░░░░░░░░█░░░░░░░░░█
#═══════█░░░░░░░███░░░█░░░░░░░░░█
#═══════█░░░░███░░░███░█░░░████░█
#══════█░░░██░░░░░░░░███░██░░░░██
#═════█░░░░░░░░░░░░░░░░░█░░░░░░░░███
#════█░░░░░░░░░░░░░██████░░░░░████░░█
#════█░░░░░░░░░█████░░░████░░██░░██░░█
#═══██░░░░░░░███░░░░░░░░░░█░░░░░░░░███
#══█░░░░░░░░░░░░░░█████████░░█████████
#═█░░░░░░░░░░█████═████══████═█████══█
#═█░░░░░░░░░░█════█═███══█═══███═█═══█
#█░░░░░░░░░░░░█═══████═████══██═██████
#░░░░░░░░░░░░░█████████░░░████████░░░█
#░░░░░░░░░░░░░░░░█░░░░░█░░░░░░░░░░░░█
#░░░░░░░░░░░░░░░░░░░░██░░░░█░░░░░░██
#░░░░░░░░░░░░░░░░░░██░░░░░░░███████
#░░░░░░░░░░░░░░░░██░░░░░░░░░░█░░░░░█
#░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█
#░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█
#░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█
#░░░░░░░░░░░█████████░░░░░░░░░░░░░░██
#░░░░░░░░░░█▒▒▒▒▒▒▒▒███████████████▒▒█
#░░░░░░░░░█▒▒███████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█
#░░░░░░░░░█▒▒▒▒▒▒▒▒▒█████████████████
#░░░░░░░░░░████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█
#░░░░░░░░░░░░░░░░░░██████████████████
#░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█
#██░░░░░░░░░░░░░░░░░░░░░░░░░░░██
#▓██░░░░░░░░░░░░░░░░░░░░░░░░██
#▓▓▓███░░░░░░░░░░░░░░░░░░░░█
#▓▓▓▓▓▓███░░░░░░░░░░░░░░░██
#▓▓▓▓▓▓▓▓▓███████████████▓▓█
#▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██
#▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█
#▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█






