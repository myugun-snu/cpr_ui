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

    void update_lcd(double x, double y);

    double tick = 0;


private slots:

    //button for testing
    void on_pushButton_start_clicked();
    void on_pushButton_stop_clicked();
    void on_spinBox_position_valueChanged(int position);
    void realtimeDataPlotSlot();
    void start();
    void pause();
    void stop();
    void restart();

private:
    Ui::MainWindow *ui;

    //freqeuncy of sensor (recieving data(EtCO2, Position etc.))
    double freq = 2;
    double plot_time = 5;
    bool start_activation = false;
    bool stop_activation = true;

    QPen ref_line_pen;

//    // to use QStandardItemModel Class
//    QStandardItemModel *csvModel;
};

#endif // MAINWINDOW_H
