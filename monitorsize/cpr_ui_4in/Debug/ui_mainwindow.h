/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "positionmatrix.h"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_data;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QCustomPlot *plot_depth;
    QCustomPlot *plot_ETCO2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpinBox *spinBox_position;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox_depth;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_ETCO2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_add;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QLCDNumber *lcdNumber_CPM;
    QLabel *label_CPM;
    PositionMatrix *position_matrix;
    QLabel *label_Position;
    QLCDNumber *lcdNumber_EtCO2;
    QLabel *label_ETCO2;
    QWidget *tab_settings;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 781, 461));
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tab_data = new QWidget();
        tab_data->setObjectName(QStringLiteral("tab_data"));
        horizontalLayout = new QHBoxLayout(tab_data);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, 9, -1);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        plot_depth = new QCustomPlot(tab_data);
        plot_depth->setObjectName(QStringLiteral("plot_depth"));

        verticalLayout->addWidget(plot_depth);

        plot_ETCO2 = new QCustomPlot(tab_data);
        plot_ETCO2->setObjectName(QStringLiteral("plot_ETCO2"));

        verticalLayout->addWidget(plot_ETCO2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_3 = new QLabel(tab_data);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        spinBox_position = new QSpinBox(tab_data);
        spinBox_position->setObjectName(QStringLiteral("spinBox_position"));

        horizontalLayout_2->addWidget(spinBox_position);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label = new QLabel(tab_data);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        doubleSpinBox_depth = new QDoubleSpinBox(tab_data);
        doubleSpinBox_depth->setObjectName(QStringLiteral("doubleSpinBox_depth"));

        horizontalLayout_2->addWidget(doubleSpinBox_depth);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_2 = new QLabel(tab_data);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setEnabled(true);

        horizontalLayout_2->addWidget(label_2);

        doubleSpinBox_ETCO2 = new QDoubleSpinBox(tab_data);
        doubleSpinBox_ETCO2->setObjectName(QStringLiteral("doubleSpinBox_ETCO2"));

        horizontalLayout_2->addWidget(doubleSpinBox_ETCO2);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        pushButton_add = new QPushButton(tab_data);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));

        horizontalLayout_2->addWidget(pushButton_add);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);

        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lcdNumber_CPM = new QLCDNumber(tab_data);
        lcdNumber_CPM->setObjectName(QStringLiteral("lcdNumber_CPM"));
        lcdNumber_CPM->setSmallDecimalPoint(false);
        lcdNumber_CPM->setDigitCount(4);
        lcdNumber_CPM->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_CPM->setProperty("value", QVariant(0));

        verticalLayout_2->addWidget(lcdNumber_CPM);

        label_CPM = new QLabel(tab_data);
        label_CPM->setObjectName(QStringLiteral("label_CPM"));
        label_CPM->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_CPM);

        position_matrix = new PositionMatrix(tab_data);
        position_matrix->setObjectName(QStringLiteral("position_matrix"));

        verticalLayout_2->addWidget(position_matrix);

        label_Position = new QLabel(tab_data);
        label_Position->setObjectName(QStringLiteral("label_Position"));
        label_Position->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_Position);

        lcdNumber_EtCO2 = new QLCDNumber(tab_data);
        lcdNumber_EtCO2->setObjectName(QStringLiteral("lcdNumber_EtCO2"));
        lcdNumber_EtCO2->setDigitCount(4);
        lcdNumber_EtCO2->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_EtCO2->setProperty("value", QVariant(0));

        verticalLayout_2->addWidget(lcdNumber_EtCO2);

        label_ETCO2 = new QLabel(tab_data);
        label_ETCO2->setObjectName(QStringLiteral("label_ETCO2"));
        label_ETCO2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_ETCO2);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(2, 1);
        verticalLayout_2->setStretch(4, 1);

        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(0, 70);
        horizontalLayout->setStretch(1, 13);
        tabWidget->addTab(tab_data, QString());
        tab_settings = new QWidget();
        tab_settings->setObjectName(QStringLiteral("tab_settings"));
        tabWidget->addTab(tab_settings, QString());
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Position", nullptr));
        label->setText(QApplication::translate("MainWindow", "Depth", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "ETCO2", nullptr));
        pushButton_add->setText(QApplication::translate("MainWindow", "add", nullptr));
        label_CPM->setText(QApplication::translate("MainWindow", "Ratio (CPM)", nullptr));
        label_Position->setText(QApplication::translate("MainWindow", "Position", nullptr));
        label_ETCO2->setText(QApplication::translate("MainWindow", "EtCO2 (mmHg)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_data), QApplication::translate("MainWindow", "DATA", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_settings), QApplication::translate("MainWindow", "SETTINGS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
