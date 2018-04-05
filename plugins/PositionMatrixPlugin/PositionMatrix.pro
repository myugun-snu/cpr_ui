#-------------------------------------------------
#
# Project created by QtCreator 2018-04-03T15:27:05
#
#-------------------------------------------------

QT       += widgets uiplugin

QTDIR_build {
# This is only for the Qt build. Do not use externally. We mean it.
PLUGIN_TYPE = designer
PLUGIN_CLASS_NAME = PositionMatrixPlugin
load(qt_plugin)
CONFIG += install_ok
} else {
# Public example:

CONFIG  += plugin
TEMPLATE = lib

TARGET = $$qtLibraryTarget($$TARGET)

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS += target

}

SOURCES = positionmatrix.cpp \
    positionmatrixplugin.cpp


HEADERS  = positionmatrix.h \
    positionmatrixplugin.h

OTHER_FILES +=positionmatrix.json
