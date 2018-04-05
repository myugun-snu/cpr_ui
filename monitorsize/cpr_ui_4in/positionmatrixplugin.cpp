#include "positionmatrix.h"
#include "positionmatrixplugin.h"

#include <QtPlugin>

PositionMatrixPlugin::PositionMatrixPlugin(QObject *parent)
    : QObject(parent)
{
}

void PositionMatrixPlugin::initialize(QDesignerFormEditorInterface */* core */)
{
    if (initialized)
        return;

    initialized = true;
}

bool PositionMatrixPlugin::isInitialized() const
{
    return initialized;
}

QWidget *PositionMatrixPlugin::createWidget(QWidget *parent)
{
    return new PositionMatrix(parent);
}

QString PositionMatrixPlugin::name() const
{
    return QStringLiteral("PositionMatrix");
}

QString PositionMatrixPlugin::group() const
{
    return QStringLiteral("Display Widgets [Examples]");
}

QIcon PositionMatrixPlugin::icon() const
{
    return QIcon();
}

QString PositionMatrixPlugin::toolTip() const
{
    return QString();
}

QString PositionMatrixPlugin::whatsThis() const
{
    return QString();
}

bool PositionMatrixPlugin::isContainer() const
{
    return false;
}

QString PositionMatrixPlugin::domXml() const
{
    return "<ui language=\"c++\">\n"
           " <widget class=\"PositionMatrix\" name=\"positionMatrix\">\n"
           "  <property name=\"geometry\">\n"
           "   <rect>\n"
           "    <x>0</x>\n"
           "    <y>0</y>\n"
           "    <width>98</width>\n"
           "    <height>98</height>\n"
           "   </rect>\n"
           "  </property>\n"
           "  <property name=\"toolTip\" >\n"
           "   <string>The current position</string>\n"
           "  </property>\n"
           "  <property name=\"whatsThis\" >\n"
           "   <string>The matrix shows the position of CPR.</string>\n"
           "  </property>\n"
           " </widget>\n"
           "</ui>\n";
}

QString PositionMatrixPlugin::includeFile() const
{
    return QStringLiteral("positionmatrix.h");
}
