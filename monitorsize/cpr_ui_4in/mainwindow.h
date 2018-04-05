#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QPen>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addPoint(double x, double y);
    void plot();
    void update_lcd(double x, double y, int z);

    double tick;

    //freqeuncy of sensor (recieving data(EtCO2, Position etc.))
    double freq;

private slots:

    //button for testing
    void on_pushButton_add_clicked();

private:
    Ui::MainWindow *ui;

    QVector<double> qv_tick, qv_depth, qv_etco2;
    QPen ref_line_pen;

//    // to use QStandardItemModel Class
//    QStandardItemModel *csvModel;
};

#endif // MAINWINDOW_H
