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

    /*��ȡ�趨����*/
    void getParamters();
    /*��ȡTCP*/
    //void readTCP();
    //QList<QPointF> points;
    
    void createChart();     // ����ͼ��
    void createChart_2();     // ����ͼ��2
    void prepareData();     // ��������
    float hexStringToFloat(const std::string& hexString);
private:
    // ����ͨ��
    QTcpServer* tcpServer;
    QTcpSocket* tcpSocket;
    QModbusRtuSerialMaster* m_modbusrtumaster;
    int serverState = 0;        // �������Ƿ����ӣ�1�������ӡ�0����δ����
    QVector<QPointF> points; // �洢��̬���ߵ����ݵ�

    
    


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
