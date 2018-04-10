 #ifndef POSITIONMATRIX_H
#define POSITIONMATRIX_H

#include <QWidget>
#include <QtUiPlugin/QDesignerExportWidget>

class QDESIGNER_WIDGET_EXPORT PositionMatrix : public QWidget
{
    Q_OBJECT

public:

    explicit PositionMatrix(QWidget *parent = nullptr);

    void setPostion(int position);

protected:

    int Position_Num;
    bool Position_color_toggle;

protected:
    void paintEvent(QPaintEvent *event) override;
};


#endif

