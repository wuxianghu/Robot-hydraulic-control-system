#pragma once
#include <qchart.h>


#include <QtWidgets/QWidget>
#include "ui_QtWidgetsApplication1.h"
#include <QModbusRtuSerialMaster>
#include <QTcpServer>    
#include <QTcpSocket>
class QtWidgetsApplication1 : public QWidget
{
    Q_OBJECT

public:
    QtWidgetsApplication1(QWidget *parent = nullptr);
    ~QtWidgetsApplication1();

    /*读取设定参数*/
    void getParamters();
    /*读取TCP*/
    //void readTCP();
    //QList<QPointF> points;
    
    void createChart();     // 创建图表
    void createChart_2();     // 创建图表2
    void prepareData();     // 更新数据
    float hexStringToFloat(const std::string& hexString);
private:
    // 网络通信
    QTcpServer* tcpServer;
    QTcpSocket* tcpSocket;
    QModbusRtuSerialMaster* m_modbusrtumaster;
    int serverState = 0;        // 服务器是否连接？1代表连接、0代表未连接
    QVector<QPointF> points; // 存储动态曲线的数据点

    
    


private:
    Ui::QtWidgetsApplication1Class ui;
    

private slots:
    void readyRead_Slot();
    void connected_Slot();
    void on_openBt_clicked();
    void saveFile();
    void readFile();
    void clearInfo();
    void closeQT();

protected:


};
