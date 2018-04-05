#include <QTimer>
#include <QPainter>
#include <QDebug>

#include "positionmatrix.h"

PositionMatrix::PositionMatrix(QWidget *parent)
    : QWidget(parent)
{

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&QWidget::update));
    timer->start(500);

    Position_Num = 1;
    Position_color_toggle = false;

    setWindowTitle(tr("Position Matrx"));
    resize(198, 198);

}

void PositionMatrix::setPostion(int position)
{
    Position_Num = position;
    update();
}

void PositionMatrix::paintEvent(QPaintEvent *)
{
    static const QPoint matrix_line_1_1 = QPoint(-33, -99);
    static const QPoint matrix_line_1_2 = QPoint(-33, 99);

    static const QPoint matrix_line_2_1 = QPoint(33, -99);
    static const QPoint matrix_line_2_2 = QPoint(33, 99);

    static const QPoint matrix_line_3_1 = QPoint(-99, 33);
    static const QPoint matrix_line_3_2 = QPoint(99, 33);

    static const QPoint matrix_line_4_1 = QPoint(-99, -33);
    static const QPoint matrix_line_4_2 = QPoint(99, -33);

    static const QPoint PositionBlock[4] = {
        QPoint(-33, -33),
        QPoint(33, -33),
        QPoint(33, 33),
        QPoint(-33, 33)
    };

    QColor matrix_line_color(0, 0, 0);

    int side = qMin(width(), height());

    QPainter painter(this);
    //painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    painter.scale(side / 198.0, side / 198.0);

    painter.setPen(matrix_line_color);

    painter.drawLine(matrix_line_1_1,matrix_line_1_2);
    painter.drawLine(matrix_line_2_1,matrix_line_2_2);
    painter.drawLine(matrix_line_3_1,matrix_line_3_2);
    painter.drawLine(matrix_line_4_1,matrix_line_4_2);

    painter.save();
    painter.setPen(Qt::NoPen);
    painter.setBrush(matrix_line_color);

    if(!Position_color_toggle){
    switch (Position_Num){
    case 1:
        painter.translate(QPoint(-66,-66));
        painter.drawConvexPolygon(PositionBlock, 4);
        break;

    case 2:
        painter.translate(QPoint(0,-66));
        painter.drawConvexPolygon(PositionBlock, 4);
        break;

    case 3:
        painter.translate(QPoint(66,-66));
        painter.drawConvexPolygon(PositionBlock, 4);
        break;

    case 4:
        painter.translate(QPoint(-66,0));
        painter.drawConvexPolygon(PositionBlock, 4);
        break;

    case 5:
        //painter.translate(QPoint(0,0));
        painter.drawConvexPolygon(PositionBlock, 4);
        break;

    case 6:
        painter.translate(QPoint(66,0));
        painter.drawConvexPolygon(PositionBlock, 4);
        break;

    case 7:
        painter.translate(QPoint(-66,66));
        painter.drawConvexPolygon(PositionBlock, 4);
        break;

    case 8:
        painter.translate(QPoint(0,66));
        painter.drawConvexPolygon(PositionBlock, 4);

    case 9:
        painter.translate(QPoint(66,66));
        painter.drawConvexPolygon(PositionBlock, 4);
        break;

    default:
        qDebug() << "Nope";
        break;
    }

    Position_Num++;
    if(Position_Num>9)
        Position_Num = Position_Num-9;
    }

    Position_color_toggle = !Position_color_toggle;
    painter.restore();


}

