#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->plot_depth->addGraph();
    ui->plot_depth->graph(0)->setKeyAxis(ui->plot_depth->xAxis2);
    ui->plot_depth->graph(0)->setScatterStyle(QCPScatterStyle::ssDot);
    ui->plot_depth->graph(0)->setLineStyle(QCPGraph::lsLine);

    ui->plot_depth->xAxis->setVisible(false);
    ui->plot_depth->xAxis2->setVisible(true);
    ui->plot_depth->xAxis2->grid()->setVisible(true);


    //drawing reference line on depth section (5 cm)

    QCPItemStraightLine *ref_line=new QCPItemStraightLine(ui->plot_depth);

    ref_line_pen.setStyle(Qt::DashLine);

    ref_line->setPen(ref_line_pen);
    ref_line->point1->setCoords(0,5);
    ref_line->point2->setCoords(1,5);


    ui->plot_depth->yAxis->setRangeReversed(true);
    ui->plot_depth->yAxis->setRange(0, 6);

    ui->plot_ETCO2->addGraph();
    ui->plot_ETCO2->graph(0)->setScatterStyle(QCPScatterStyle::ssDot);
    ui->plot_ETCO2->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->plot_ETCO2->yAxis->setRange(0, 40);

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    ui->plot_depth->xAxis2->setTicker(timeTicker);
    ui->plot_ETCO2->xAxis->setTicker(timeTicker);

    QTimer *dataTimer = new QTimer(this);
    connect(dataTimer, SIGNAL(timeout()) , this, SLOT(realtimeDataPlotSlot()));
    dataTimer->start(0);

    ui->pushButton_stop->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_lcd(double x, double y)
{
    ui->lcdNumber_CPM->display(x);
    ui->lcdNumber_EtCO2->display(y);
}

void MainWindow::on_pushButton_start_clicked()
{

    if(start_activation)
        start();

    else
        pause();

    if(stop_activation)
        restart();

    stop_activation = false;
    start_activation = !start_activation;

//        QFile file("../patientCPRdata.csv");
//    if(file.open(QFile::Append))
//    {
//            QTextStream output(&file);
//            output << tick << ";" << ui->doubleSpinBox_depth->value() << ";" << ui->doubleSpinBox_ETCO2->value() << ";" << ui->spinBox_position->value() << "\n" ;
//}
//            file.close();

//         tick++;

}

void MainWindow::on_pushButton_stop_clicked()
{
    if (!stop_activation)
        stop();
}

void MainWindow::on_spinBox_position_valueChanged(int position)
{
    ui->position_matrix->setPostion(position);
}

void MainWindow::realtimeDataPlotSlot()
{
    static QTime time(QTime::currentTime());
    double key = time.elapsed()/1000.0;
    static double lastPointKey = 0;
    static double progressPointKey = 0;
    static double elapsedPointKey = 0;

    if (start_activation){

        progressPointKey = key-elapsedPointKey;

        if (progressPointKey-lastPointKey > 0.01) // at most add point every 10 ms
        {
        // add data to lines:
        ui->plot_depth->graph(0)->addData(progressPointKey, 3+2*qSin(progressPointKey*5)+1*qCos(progressPointKey*2));
        ui->plot_ETCO2->graph(0)->addData(progressPointKey, 20+10*qCos(progressPointKey*3)-2*qSin(progressPointKey*10));
        update_lcd(120,20+10*qCos(progressPointKey*3)-2*qSin(progressPointKey*10));
        // rescale value (vertical) axis to fit the current data:
        //ui->customPlot->graph(0)->rescaleValueAxis();
        ui->plot_ETCO2->graph(0)->rescaleValueAxis(true);
        lastPointKey = progressPointKey;
        }
        // make key axis range scroll with the data (at a constant range size of 5):
        ui->plot_depth->xAxis2->setRange(progressPointKey, 5, Qt::AlignRight);
        ui->plot_ETCO2->xAxis->setRange(progressPointKey, 5, Qt::AlignRight);
        ui->plot_depth->replot();
        ui->plot_ETCO2->replot();
    }

    else if (!start_activation && !stop_activation){
        elapsedPointKey = key - progressPointKey;
    }

    if (stop_activation)
    {
        elapsedPointKey = key;
        lastPointKey = 0;
    }
}

void MainWindow::start()
{
    ui->pushButton_start->setText(tr("Start"));
}

void MainWindow::pause()
{
    ui->pushButton_start->setText(tr("Pause"));
    ui->pushButton_stop->setEnabled(true);
}

void MainWindow::stop()
{
    ui->pushButton_start->setText(tr("Start"));
    ui->pushButton_stop->setEnabled(false);
    start_activation = false;
    stop_activation = true;
}

void MainWindow::restart()
{
    tick = 0;
    ui->plot_depth->graph(0)->data().data()->clear();
    ui->plot_ETCO2->graph(0)->data().data()->clear();
    ui->plot_depth->replot();
    ui->plot_ETCO2->replot();
    ui->plot_depth->update();
    ui->plot_ETCO2->update();
}

