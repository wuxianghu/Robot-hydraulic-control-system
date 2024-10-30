#pragma once
// MyWidget.h
#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QtMath>
QT_CHARTS_USE_NAMESPACE

class myWidget1 : public QWidget {
    Q_OBJECT

public:
    explicit myWidget1(QWidget* parent = nullptr)
        : QWidget(parent) {
        // 创建布局
        QVBoxLayout* layout = new QVBoxLayout(this);

        // 创建 QLineSeries
        QLineSeries* series = new QLineSeries();
        for (int x = 0; x <= 100; ++x) {
            double y = qSin(x * 0.1); // 示例：正弦曲线
            series->append(x, y);
        }

        // 创建 QChart
        QChart* chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Sine Wave Example");

        // 创建默认坐标轴
        chart->createDefaultAxes();

        // 设置坐标轴范围
        QValueAxis* axisX = qobject_cast<QValueAxis*>(chart->axes(Qt::Horizontal).at(0));
        axisX->setRange(0, 100);
        QValueAxis* axisY = qobject_cast<QValueAxis*>(chart->axes(Qt::Vertical).at(0));
        axisY->setRange(-1, 1);

        // 创建 QChartView
        QChartView* chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing); // 抗锯齿

        // 将 QChartView 添加到布局
        layout->addWidget(chartView);
        setLayout(layout);
    }
};

#endif // MYWIDGET_H
