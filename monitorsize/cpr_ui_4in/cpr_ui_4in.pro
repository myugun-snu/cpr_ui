#-------------------------------------------------
#
# Project created by QtCreator 2018-03-09T15:36:24
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cpr_ui_4in
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    positionmatrixplugin.cpp \
    positionmatrix.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    positionmatrixplugin.h \
    positionmatrix.h

FORMS    += mainwindow.ui
