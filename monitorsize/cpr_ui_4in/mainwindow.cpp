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

    tick = 0;
    freq = 5;
}

MainWindow::~MainWindow()
{

    delete ui;
    //    delete csvModel;
}

void MainWindow::addPoint(double x, double y)
{
    qv_tick.append(tick/freq);
    qv_depth.append(x);
    qv_etco2.append(y);
}

void MainWindow::plot()
{
    if(tick>(freq*5))
    {
        // maintaining 5 sec width
        ui->plot_depth->xAxis2->setRange(((tick/freq)-5),tick/freq);
        ui->plot_ETCO2->xAxis->setRange(((tick/freq)-5),tick/freq);
    }

    ui->plot_depth->graph(0)->setData(qv_tick, qv_depth);
    ui->plot_ETCO2->graph(0)->setData(qv_tick, qv_etco2);
    ui->plot_depth->replot();
    ui->plot_ETCO2->replot();
    ui->plot_depth->update();
    ui->plot_ETCO2->update();
}

void MainWindow::update_lcd(double x, double y, int z)
{
    ui->lcdNumber_CPM->display(x);
    ui->lcdNumber_EtCO2->display(y);

     ui->position_matrix->setPostion(z);
    //ui->lcdNumber_position->display(z);
}

void MainWindow::on_pushButton_add_clicked()
{
    addPoint(ui->doubleSpinBox_depth->value(), ui->doubleSpinBox_ETCO2->value());
    update_lcd(ui->doubleSpinBox_depth->value(), ui->doubleSpinBox_ETCO2->value(),ui->spinBox_position->value());
    plot();

        QFile file("../patientCPRdata.csv");
    if(file.open(QFile::Append))
    {
            QTextStream output(&file);
            output << tick << ";" << ui->doubleSpinBox_depth->value() << ";" << ui->doubleSpinBox_ETCO2->value() << ";" << ui->spinBox_position->value() << "\n" ;
}
            file.close();

         tick++;

}

//============loading csv text================================
//    csvModel = new QStandardItemModel(this);
//    csvModel->setColumnCount(2);

//    csvModel->setHorizontalHeaderLabels(QStringList() << "Time" << "Position");
//    ui->tableView->setModel(csvModel);

//    QFile file("../data.csv");
//    if ( !file.open(QFile::ReadOnly | QFile::Text)){
//        qDebug() << "File not exists";
//    }
//    else {
//            // Create a thread to retrieve data from a file
//            QTextStream in(&file);
//            //Reads the data up to the end of file
//            while (!in.atEnd())
//            {
//                QString line = in.readLine();
//                // Adding to the model in line with the elements
//                QList<QStandardItem *> standardItemsList;
//                QStringList data_list = line.split(";");
//                for (int i=0; i<data_list.size();i++)
//                {
//                  standardItemsList.append(new QStandardItem(data_list[i]));
//                }
////                QString tmp = data_list[2];
////                float tmpf = tmp.toFloat();
//                 csvModel->insertRow(csvModel->rowCount(), standardItemsList);
//            }
//            file.close();
//    }
