#ifndef CUSTOMWEIDGETPLUGIN_H
#define CUSTOMWEIDGETPLUGIN_H

#include <QtUiPlugin/QDesignerCustomWidgetInterface>

class PositionMatrixPlugin : public QObject, public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "your-string-here")
    Q_INTERFACES(QDesignerCustomWidgetInterface)

public:

    explicit PositionMatrixPlugin(QObject *parent = 0);

    bool isContainer() const;
    bool isInitialized() const;
    QIcon icon() const;
    QString domXml() const;
    QString group() const;
    QString includeFile() const;
    QString name() const;
    QString toolTip() const;
    QString whatsThis() const;
    QWidget *createWidget(QWidget *parent);
    void initialize(QDesignerFormEditorInterface *core);


private:
    bool initialized = false;

};

#endif // CUSTOMWEIDGETPLUGIN_H

