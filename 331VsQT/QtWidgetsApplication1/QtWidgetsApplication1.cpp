#include "QtWidgetsApplication1.h"
#include"header.h"
#include<QTextCodec>
#if defined(_MSC_VER) && (_MSC_VER >= 1600)
# pragma execution_character_set("utf-8")
#endif
QHostAddress address(QString("172.16.10.12"));
int port = 2002;
QLineSeries* curSeries; // 当前序列
QLineSeries* curSeries_2; // 当前序列
QValueAxis* curAxis;    // 当前坐标轴
QValueAxis* curAxis_2;    // 当前坐标轴
double t = 0;            // 横坐标
double timed = 0.2;

QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    createChart();
    createChart_2();
    //prepareData();
    
    std::random_device rd;  // 获取随机数种子
    std::mt19937 gen(rd());  // 使用 Mersenne Twister 算法生成随机数
    std::uniform_int_distribution<> dis(0, 15);  // 定义分布范围

    /*1. logo*/
    QPixmap pixmap("./logo.png");
    ui.label->setPixmap(pixmap.scaled(ui.label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    /*TCP*/
    tcpSocket = new QTcpSocket(this);
    
    
    QTimer* m_timer = new QTimer();
    m_timer->start(200);
    connect(m_timer, &QTimer::timeout, this, [=]() {
        cout << "读取TCP" << endl;
        readyRead_Slot();
    });
    /*3. 点击设定按钮，触发getParamters*/
    connect(ui.pushButton_6, &QPushButton::clicked, this, &QtWidgetsApplication1::getParamters);
    connect(ui.pushButton_8, &QPushButton::clicked, this, &QtWidgetsApplication1::clearInfo);
    connect(ui.pushButton_9, &QPushButton::clicked, this, &QtWidgetsApplication1::saveFile);
    connect(ui.pushButton, &QPushButton::clicked, this, &QtWidgetsApplication1::readFile);
    connect(ui.pushButton_3, &QPushButton::clicked, this, &QtWidgetsApplication1::closeQT);


    /*样式设置*/
    this->setStyleSheet("background-color: rgb(255, 239, 204); color: white;");
    ui.groupBox->setStyleSheet("QGroupBox { border: none; }");
    ui.groupBox_5->setStyleSheet("QGroupBox { border: none; }");
    ui.label_15->setStyleSheet("QLabel { background-color: red; border-radius: 20px; }");
    QString buttonStyle = R"(
    QPushButton {
        background-color: rgb(255, 182, 88);  /* 基础背景颜色 */
        color: rgb(85, 65, 44);
        border: 2px solid rgb(255, 182, 88);  /* 边框颜色 */
        border-radius: 8px;  /* 圆角 */
        padding: 10px 15px;  /* 内边距 */
        /*font-size: 16px;*/  /* 字体大小 */
        font-weight: bold;
    }
    QPushButton:hover {
        background-color: rgb(255, 160, 70);  /* 悬停时颜色 */
        border: 2px solid rgb(255, 160, 70);  /* 悬停时边框颜色 */
    }
    QPushButton:pressed {
        background-color: rgb(230, 140, 50);  /* 按下时颜色 */
        border: 2px solid rgb(230, 140, 50);  /* 按下时边框颜色 */
        padding-left: 8px;  /* 模拟按下效果 */
        padding-top: 8px;
    }
    )";

    QString labelStyle = R"(
    QLabel {
        color: rgb(51, 37, 24);
        font-weight: bold;
    }
    )";

    QString gropuStyle = R"(
    QGroupBox {
        color: rgb(51, 37, 24);
        font-weight: bold;
    }
    )";

    QString lineEditStyle = R"(
    QLineEdit  {
        color: rgb(51, 37, 24);
        font-weight: bold;
        text-align: center;
    }
    )";

    ui.openBt->setStyleSheet(buttonStyle);
    ui.pushButton_6->setStyleSheet(buttonStyle);
    ui.pushButton_7->setStyleSheet(buttonStyle);
    ui.pushButton_8->setStyleSheet(buttonStyle);
    ui.pushButton->setStyleSheet(buttonStyle);
    ui.pushButton_2->setStyleSheet(buttonStyle);
    ui.pushButton_3->setStyleSheet(buttonStyle);
    ui.pushButton_9->setStyleSheet(buttonStyle);
    ui.label_6->setStyleSheet(labelStyle);
    ui.label_7->setStyleSheet(labelStyle);
    ui.label_8->setStyleSheet(labelStyle);
    ui.label_9->setStyleSheet(labelStyle);
    ui.label_10->setStyleSheet(labelStyle);
    ui.label_11->setStyleSheet(labelStyle);
    ui.label_12->setStyleSheet(labelStyle);
    ui.label_14->setStyleSheet(labelStyle);
    ui.label_16->setStyleSheet(labelStyle);
    ui.label_17->setStyleSheet(labelStyle);
    ui.label_13->setStyleSheet(labelStyle);
    ui.label_19->setStyleSheet(labelStyle);
    //ui.label_4->setStyleSheet(labelStyle);
    //ui.label_5->setStyleSheet(labelStyle);
    ui.label_20->setStyleSheet(labelStyle);
    ui.label_20->setStyleSheet(labelStyle);
    ui.groupBox_3->setStyleSheet(gropuStyle);
    ui.groupBox_6->setStyleSheet(gropuStyle);
    ui.groupBox_7->setStyleSheet(gropuStyle);
    ui.groupBox_4->setStyleSheet("QGroupBox { color: rgb(51, 37, 24); font-weight: bold;}");
    ui.lineEdit->setStyleSheet(lineEditStyle);
    ui.lineEdit_10->setStyleSheet(lineEditStyle);
    ui.lineEdit_8->setStyleSheet(lineEditStyle);
    ui.lineEdit_9->setStyleSheet(lineEditStyle);
    ui.lineEdit_2->setStyleSheet(lineEditStyle);
    ui.lineEdit_3->setStyleSheet(lineEditStyle);
    ui.lineEdit_4->setStyleSheet(lineEditStyle);
    ui.lineEdit_5->setStyleSheet(lineEditStyle);
    ui.lineEdit_6->setStyleSheet(lineEditStyle);
    ui.lineEdit_7->setStyleSheet(lineEditStyle);
    ui.label_18->setStyleSheet("QLabel { background-color: green; border-radius: 20px; }");

    
}

QtWidgetsApplication1::~QtWidgetsApplication1()
{}


/*2. 读取设定参数*/
void QtWidgetsApplication1::getParamters() {
    QDateTime currentTime = QDateTime::currentDateTime();
    QString timeString = currentTime.toString("yyyy-MM-dd hh:mm:ss");
    QString message = "";

    QString yzlxx = ui.lineEdit->text(), yzlsx = ui.lineEdit_2->text(), yzsd = ui.lineEdit_3->text(), yzwyxx = ui.lineEdit_4->text(), yzwysx = ui.lineEdit_5->text(), mbbysj = ui.lineEdit_6->text(), byyl = ui.lineEdit_7->text();
    bool b_yzlxx, b_yzlsx, b_yzsd, b_yzwyxx, b_yzwysx, b_mbbysj, b_byyl;
    float f_yzlxx = yzlxx.toFloat(&b_yzlxx), f_yzlsx = yzlxx.toFloat(&b_yzlsx), f_yzsd = yzsd.toFloat(&b_yzsd), f_yzwyxx = yzwyxx.toFloat(&b_yzwyxx), f_yzwysx = yzwysx.toFloat(&b_yzwysx), f_mbbysj = mbbysj.toFloat(&b_mbbysj), f_byyl = byyl.toFloat(&b_byyl);
    cout << f_yzlxx << endl;
    cout << f_yzlsx << endl;
    cout << f_yzsd << endl;
    cout << f_yzwyxx << endl;
    cout << f_yzwysx << endl;
    cout << f_mbbysj << endl;
    cout << f_byyl << endl;
    QByteArray f_yzlxxData, f_yzlsxData, f_yzsdData, f_yzwyxxData, f_yzwysxData, f_mbbysjData, f_byylData;
    if (serverState != 1) {
        message = timeString + "服务器未连接！" + '\n';
        QString currentText = ui.label_13->text(); // 获取当前文本
        QString newText = message + "\n" + currentText;
        ui.label_13->setText(newText);
        return;
    } 
    if (int(f_yzlxx) != 0) {
        union {
            float f;
            unsigned char data[4];
        } data;
        data.f = f_yzlxx;
        // 事务标识符
        f_yzlxxData.append('\x00');
        f_yzlxxData.append('\x00');
        // 协议标识符
        f_yzlxxData.append('\x00');
        f_yzlxxData.append('\x00');
        // 长度
        f_yzlxxData.append('\x00');
        f_yzlxxData.append('\x0B');
        // 单元标志
        f_yzlxxData.append('\x00');
        // 功能码
        f_yzlxxData.append('\x10');
        // 起始寄存器地址  52/2=16
        f_yzlxxData.append('\x00');
        f_yzlxxData.append('\x02');
        // 写寄存器的个数
        f_yzlxxData.append('\x00');
        f_yzlxxData.append('\x02');
        // 数据长度
        f_yzlxxData.append('\x04');
        f_yzlxxData.append(data.data[3]);
        f_yzlxxData.append(data.data[2]);
        f_yzlxxData.append(data.data[1]);
        f_yzlxxData.append(data.data[0]);
        tcpSocket->write(f_yzlxxData);
        tcpSocket->flush();
        message += timeString + "  压装力下限：" + QString::number(f_yzlxx) + '\n';
    }
    if (int(f_yzlsx) != 0) {
        union {
            float f;
            unsigned char data[4];
        } data;
        data.f = f_yzlsx;
        // 事务标识符
        f_yzlsxData.append('\x00');
        f_yzlsxData.append('\x00');
        // 协议标识符
        f_yzlsxData.append('\x00');
        f_yzlsxData.append('\x00');
        // 长度
        f_yzlsxData.append('\x00');
        f_yzlsxData.append('\x0B');
        // 单元标志
        f_yzlsxData.append('\x00');
        // 功能码
        f_yzlsxData.append('\x10');
        // 起始寄存器地址  52/2=16
        f_yzlsxData.append('\x00');
        f_yzlsxData.append('\x02');
        // 写寄存器的个数
        f_yzlsxData.append('\x00');
        f_yzlsxData.append('\x02');
        // 数据长度
        f_yzlsxData.append('\x04');
        f_yzlsxData.append(data.data[3]);
        f_yzlsxData.append(data.data[2]);
        f_yzlsxData.append(data.data[1]);
        f_yzlsxData.append(data.data[0]);
        tcpSocket->write(f_yzlsxData);
        tcpSocket->flush();
        message += timeString + "  压装力上限：" + QString::number(f_yzlsx) + '\n';
    }
    if (int(f_yzsd) != 0) {
        union {
            float f;
            unsigned char data[4];
        } data;
        data.f = f_yzsd;
        // 事务标识符
        f_yzsdData.append('\x00');
        f_yzsdData.append('\x00');
        // 协议标识符
        f_yzsdData.append('\x00');
        f_yzsdData.append('\x00');
        // 长度
        f_yzsdData.append('\x00');
        f_yzsdData.append('\x0B');
        // 单元标志
        f_yzsdData.append('\x00');
        // 功能码
        f_yzsdData.append('\x10');
        // 起始寄存器地址  52/2=16
        f_yzsdData.append('\x00');
        f_yzsdData.append('\x02');
        // 写寄存器的个数
        f_yzsdData.append('\x00');
        f_yzsdData.append('\x02');
        // 数据长度
        f_yzsdData.append('\x04');
        f_yzsdData.append(data.data[3]);
        f_yzsdData.append(data.data[2]);
        f_yzsdData.append(data.data[1]);
        f_yzsdData.append(data.data[0]);
        tcpSocket->write(f_yzsdData);
        tcpSocket->flush();
        message += timeString + "  压装速度：" + QString::number(f_yzsd) + '\n';
    }
    if (int(f_yzwyxx) != 0) {
        union {
            float f;
            unsigned char data[4];
        } data;
        data.f = f_yzwyxx;
        // 事务标识符
        f_yzwyxxData.append('\x00');
        f_yzwyxxData.append('\x00');
        // 协议标识符
        f_yzwyxxData.append('\x00');
        f_yzwyxxData.append('\x00');
        // 长度
        f_yzwyxxData.append('\x00');
        f_yzwyxxData.append('\x0B');
        // 单元标志
        f_yzwyxxData.append('\x00');
        // 功能码
        f_yzwyxxData.append('\x10');
        // 起始寄存器地址  52/2=16
        f_yzwyxxData.append('\x00');
        f_yzwyxxData.append('\x02');
        // 写寄存器的个数
        f_yzwyxxData.append('\x00');
        f_yzwyxxData.append('\x02');
        // 数据长度
        f_yzwyxxData.append('\x04');
        f_yzwyxxData.append(data.data[3]);
        f_yzwyxxData.append(data.data[2]);
        f_yzwyxxData.append(data.data[1]);
        f_yzwyxxData.append(data.data[0]);
        tcpSocket->write(f_yzwyxxData);
        tcpSocket->flush();
        message += timeString + "  压装位移下限：" + QString::number(f_yzwyxx) + '\n';
    }
    if (int(f_yzwysx) != 0) {
        union {
            float f;
            unsigned char data[4];
        } data;
        data.f = f_yzwysx;
        // 事务标识符
        f_yzwysxData.append('\x00');
        f_yzwysxData.append('\x00');
        // 协议标识符
        f_yzwysxData.append('\x00');
        f_yzwysxData.append('\x00');
        // 长度
        f_yzwysxData.append('\x00');
        f_yzwysxData.append('\x0B');
        // 单元标志
        f_yzwysxData.append('\x00');
        // 功能码
        f_yzwysxData.append('\x10');
        // 起始寄存器地址  52/2=16
        f_yzwysxData.append('\x00');
        f_yzwysxData.append('\x02');
        // 写寄存器的个数
        f_yzwysxData.append('\x00');
        f_yzwysxData.append('\x02');
        // 数据长度
        f_yzwysxData.append('\x04');
        f_yzwysxData.append(data.data[3]);
        f_yzwysxData.append(data.data[2]);
        f_yzwysxData.append(data.data[1]);
        f_yzwysxData.append(data.data[0]);
        tcpSocket->write(f_yzwysxData);
        tcpSocket->flush();
        message += timeString + "  压装位移上限：" + QString::number(f_yzwysx) + '\n';
    }
    if (int(f_mbbysj) != 0) {
        union {
            float f;
            unsigned char data[4];
        } data;
        data.f = f_mbbysj;
        // 事务标识符
        f_mbbysjData.append('\x00');
        f_mbbysjData.append('\x00');
        // 协议标识符
        f_mbbysjData.append('\x00');
        f_mbbysjData.append('\x00');
        // 长度
        f_mbbysjData.append('\x00');
        f_mbbysjData.append('\x0B');
        // 单元标志
        f_mbbysjData.append('\x00');
        // 功能码
        f_mbbysjData.append('\x10');
        // 起始寄存器地址  52/2=16
        f_mbbysjData.append('\x00');
        f_mbbysjData.append('\x02');
        // 写寄存器的个数
        f_mbbysjData.append('\x00');
        f_mbbysjData.append('\x02');
        // 数据长度
        f_mbbysjData.append('\x04');
        f_mbbysjData.append(data.data[3]);
        f_mbbysjData.append(data.data[2]);
        f_mbbysjData.append(data.data[1]);
        f_mbbysjData.append(data.data[0]);
        tcpSocket->write(f_mbbysjData);
        tcpSocket->flush();
        message += timeString + "  目标保压时间：" + QString::number(f_mbbysj) + '\n';
    }
    if (int(f_byyl) != 0) {
        union {
            float f;
            unsigned char data[4];
        } data;
        data.f = f_byyl;
        // 事务标识符
        f_byylData.append('\x00');
        f_byylData.append('\x00');
        // 协议标识符
        f_byylData.append('\x00');
        f_byylData.append('\x00');
        // 长度
        f_byylData.append('\x00');
        f_byylData.append('\x0B');
        // 单元标志
        f_byylData.append('\x00');
        // 功能码
        f_byylData.append('\x10');
        // 起始寄存器地址  52/2=16
        f_byylData.append('\x00');
        f_byylData.append('\x02');
        // 写寄存器的个数
        f_byylData.append('\x00');
        f_byylData.append('\x02');
        // 数据长度
        f_byylData.append('\x04');
        f_byylData.append(data.data[3]);
        f_byylData.append(data.data[2]);
        f_byylData.append(data.data[1]);
        f_byylData.append(data.data[0]);
        tcpSocket->write(f_byylData);
        tcpSocket->flush();
        message += timeString + "  保压压力：" + QString::number(f_byyl) + '\n';
    }


  
    QString currentText = ui.label_13->text(); // 获取当前文本
    QString newText = message + "\n" + currentText;
    ui.label_13->setText(newText);
}

/*接收TCP窗口*/
void QtWidgetsApplication1::readyRead_Slot()
{
    static QLineSeries* series0 = (QLineSeries*)ui.chartView->chart()->series().at(0);
    static QLineSeries* series1 = (QLineSeries*)ui.chartView_2->chart()->series().at(0);

    cout << "readyRead_Slot" << endl;
    QByteArray buf = tcpSocket->readAll();
    QString hexString = buf.toHex();
    int dataSize = hexString.toStdString().size();
    if (dataSize != 0) {
        string dataString = hexString.toStdString();
        cout << "Read data: " << dataString << endl;
        double Y1 = hexStringToFloat(dataString.substr(0, 8));
        double Y2 = hexStringToFloat(dataString.substr(8, 8));

        cout << "(X1, Y1): (" << t << ", " << Y1 << ")" << endl;
        cout << "(X2, Y2): (" << t << ", " << Y2 << ")" << endl;
        series0->append(t, Y1);
        series1->append(t, Y2);
        if (series0->count() < 100) t += timed;
        cout << "t: " << t << endl;
        // 保留后20个点
        if (series0->count() > 100) {
            
            // 删除第一个点
            series0->remove(0); // 删除第一个点
            series1->remove(0); // 删除第一个点

            // 向前移动后面的点的横坐标
            for (int i = 0; i < series0->count(); ++i) {
                QPointF point = series0->at(i);
                QPointF point_2 = series1->at(i);
                // 更新横坐标
                series0->replace(i, QPointF(point.x() - timed, point.y()));
                series1->replace(i, QPointF(point_2.x() - timed, point_2.y()));
                cout << "(t, Y): (" << t << ", " << Y1 << ")" << endl;
            }
        }
    }
}

void QtWidgetsApplication1::connected_Slot()
{
    cout << "成功连接到服务器!" << endl;
    
    //connect(tcpSocket, &QTcpSocket::readyRead, this, &QtWidgetsApplication1::readyRead_Slot);
}

/*打开服务器*/
void QtWidgetsApplication1::on_openBt_clicked()
{
    if (serverState == 0) {
        cout << "连接服务器..." << endl;
        connect(tcpSocket, &QTcpSocket::connected, this, &QtWidgetsApplication1::connected_Slot);
        tcpSocket->connectToHost(address, port);
        ui.openBt->setText(QString::fromUtf8("断开连接"));
        serverState = 1;
        ui.label_15->setStyleSheet("QLabel { background-color: green; border-radius: 20px; }");
        QDateTime currentTime = QDateTime::currentDateTime();
        QString timeString = currentTime.toString("yyyy-MM-dd hh:mm:ss");
        QString message = timeString + "  服务器已连接";
        QString currentText = ui.label_13->text(); // 获取当前文本
        QString newText = message + "\n" + currentText;
        ui.label_13->setText(newText);
    }
    else {
        cout << "关闭服务器..." << endl;
        //connect(tcpSocket, &QTcpSocket::connected, this, &QtWidgetsApplication1::connected_Slot);
        tcpSocket->close();        
        ui.openBt->setText(QString::fromUtf8("连接"));
        serverState = 0;
        ui.label_15->setStyleSheet("QLabel { background-color: red; border-radius: 20px; }");
        QDateTime currentTime = QDateTime::currentDateTime();
        QString timeString = currentTime.toString("yyyy-MM-dd hh:mm:ss");
        QString message = timeString + "  服务器已断开";
        QString currentText = ui.label_13->text(); // 获取当前文本
        QString newText = message + "\n" + currentText;
        ui.label_13->setText(newText);
    }
}

/*清空窗口*/
void QtWidgetsApplication1::clearInfo() {
    ui.label_13->setText("");
}

void QtWidgetsApplication1::saveFile() {
    QString yzlxx = ui.lineEdit->text();
    QString yzlsx = ui.lineEdit_2->text();
    QString yzsd = ui.lineEdit_3->text();
    QString yzwyxx = ui.lineEdit_4->text();
    QString yzwysx = ui.lineEdit_5->text();
    QString mbbysj = ui.lineEdit_6->text();
    QString byyl = ui.lineEdit_7->text();

    // 用于检查转换是否成功的布尔值
    bool b_yzlxx, b_yzlsx, b_yzsd, b_yzwyxx, b_yzwysx, b_mbbysj, b_byyl;

    // 转换为浮点数
    float f_yzlxx = yzlxx.toFloat(&b_yzlxx);
    float f_yzlsx = yzlsx.toFloat(&b_yzlsx);
    float f_yzsd = yzsd.toFloat(&b_yzsd);
    float f_yzwyxx = yzwyxx.toFloat(&b_yzwyxx);
    float f_yzwysx = yzwysx.toFloat(&b_yzwysx);
    float f_mbbysj = mbbysj.toFloat(&b_mbbysj);
    float f_byyl = byyl.toFloat(&b_byyl);

    // 弹出文件对话框，选择保存路径和文件名
    QString filePath = QFileDialog::getSaveFileName(this, "保存文件", "", "Text Files (*.jc);;All Files (*)");
    if (filePath.isEmpty()) {
        // 用户取消了文件对话框
        return;
    }

    // 打开文件
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "错误", "无法打开文件以写入");
        return;
    }

    QTextStream out(&file);

    // 将浮点数写入文件，每个数字用换行分隔
    out << f_yzlxx << "\n"
        << f_yzlsx << "\n"
        << f_yzsd << "\n"
        << f_yzwyxx << "\n"
        << f_yzwysx << "\n"
        << f_mbbysj << "\n"
        << f_byyl << "\n";

    file.close(); // 关闭文件

    QMessageBox msgBox(this);
    msgBox.setWindowTitle("成功");
    msgBox.setText("数据已成功保存到文件");
    msgBox.setStyleSheet("QMessageBox { background-color: rgb(255, 255, 255); }"  // 背景颜色
        "QLabel { color: rgb(0, 0, 0); }"                        // 字体颜色
        "QPushButton { background-color: rgb(255, 182, 88); }"  // 按钮背景颜色
        "QPushButton:hover { background-color: rgb(255, 160, 70); }" // 悬停时颜色
        "QPushButton:pressed { background-color: rgb(230, 140, 50); }"); // 按下时颜色);
    msgBox.exec();
}

void QtWidgetsApplication1::readFile() {
    // 弹出文件对话框，让用户选择要打开的文件
    QString filePath = QFileDialog::getOpenFileName(this, "打开文件", "", "Text Files (*.jc);;All Files (*)");
    if (filePath.isEmpty()) {
        // 用户取消了文件对话框
        return;
    }

    // 打开文件
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "错误", "无法打开文件以读取");
        return;
    }

    QTextStream in(&file);

    // 读取文件中的每一行，并将其转换为相应的参数
    QString yzlxx, yzlsx, yzsd, yzwyxx, yzwysx, mbbysj, byyl;

    if (!in.atEnd()) {
        yzlxx = in.readLine();
    }
    if (!in.atEnd()) {
        yzlsx = in.readLine();
    }
    if (!in.atEnd()) {
        yzsd = in.readLine();
    }
    if (!in.atEnd()) {
        yzwyxx = in.readLine();
    }
    if (!in.atEnd()) {
        yzwysx = in.readLine();
    }
    if (!in.atEnd()) {
        mbbysj = in.readLine();
    }
    if (!in.atEnd()) {
        byyl = in.readLine();
    }

    file.close(); // 关闭文件

    // 将读取到的字符串设置到相应的 QLineEdit 控件中
    ui.lineEdit->setText(yzlxx);
    ui.lineEdit_2->setText(yzlsx);
    ui.lineEdit_3->setText(yzsd);
    ui.lineEdit_4->setText(yzwyxx);
    ui.lineEdit_5->setText(yzwysx);
    ui.lineEdit_6->setText(mbbysj);
    ui.lineEdit_7->setText(byyl);

    QMessageBox msgBox(this);
    msgBox.setWindowTitle("成功");
    msgBox.setText("数据已成功从文件读取");
    msgBox.setStyleSheet("QMessageBox { background-color: rgb(255, 255, 255); }"  // 背景颜色
        "QLabel { color: rgb(0, 0, 0); }"                        // 字体颜色
        "QPushButton { background-color: rgb(255, 182, 88); }"  // 按钮背景颜色
        "QPushButton:hover { background-color: rgb(255, 160, 70); }" // 悬停时颜色
        "QPushButton:pressed { background-color: rgb(230, 140, 50); }"); // 按下时颜色);
    msgBox.exec();
}

void QtWidgetsApplication1::createChart() {
    QChart* chart = new QChart();
    ui.chartView->setChart(chart);
    ui.chartView->setRenderHint(QPainter::Antialiasing);
    
    QLineSeries* series0 = new QLineSeries();
    QLineSeries* series1 = new QLineSeries();
    series0->setName("位移曲线");
    curSeries = series0;

    QPen pen;
    pen.setStyle(Qt::DotLine);
    pen.setWidth(2);
    pen.setColor(Qt::red);
    series0->setPen(pen);
    chart->addSeries(series0);

    QValueAxis* axisX = new QValueAxis;
    curAxis = axisX;    // 当前坐标轴
    axisX->setRange(0, 20); // 设置坐标轴范围
    axisX->setLabelFormat("%.1f");  // 标签格式
    axisX->setTickCount(11);
    axisX->setMinorTickCount(4);
    axisX->setTitleText("Time(secs)");  // 标题
    QValueAxis* axisY = new QValueAxis;
    axisY->setRange(-80, 80);
    axisY->setTitleText("实际位移(mm)");  // 标题
    axisY->setTickCount(5);
    axisY->setLabelFormat("%.2f");  // 标签格式
    axisY->setMinorTickCount(4);


    //chart->setAxisX(axisX, series0);
    //chart->setAxisY(axisY, series0);
    chart->addAxis(axisX, Qt::AlignBottom); // 添加 X 轴到图表
    series0->attachAxis(axisX); // 将系列附加到 X 轴
    chart->addAxis(axisY, Qt::AlignLeft); // 添加 Y 轴到图表
    series0->attachAxis(axisY); // 将系列附加到 Y 轴
}

void QtWidgetsApplication1::createChart_2() {
    QChart* chart = new QChart();
    ui.chartView_2->setChart(chart);
    ui.chartView_2->setRenderHint(QPainter::Antialiasing);

    QLineSeries* series1 = new QLineSeries();
    series1->setName("输出力曲线");
    curSeries_2 = series1;

    QPen pen;
    pen.setStyle(Qt::DotLine);
    pen.setWidth(2);
    pen.setColor(Qt::red);
    series1->setPen(pen);
    chart->addSeries(series1);

    QValueAxis* axisX = new QValueAxis;
    curAxis_2 = axisX;    // 当前坐标轴
    axisX->setRange(0, 20); // 设置坐标轴范围
    axisX->setLabelFormat("%.1f");  // 标签格式
    axisX->setTickCount(11);
    axisX->setMinorTickCount(4);
    axisX->setTitleText("Time(secs)");  // 标题
    QValueAxis* axisY = new QValueAxis;
    axisY->setRange(-80, 80);
    axisY->setTitleText("实际输出力(N)");  // 标题
    axisY->setTickCount(5);
    axisY->setLabelFormat("%.2f");  // 标签格式
    axisY->setMinorTickCount(4);

    chart->addAxis(axisX, Qt::AlignBottom); // 添加 X 轴到图表
    series1->attachAxis(axisX); // 将系列附加到 X 轴
    chart->addAxis(axisY, Qt::AlignLeft); // 添加 Y 轴到图表
    series1->attachAxis(axisY); // 将系列附加到 Y 轴
}

void QtWidgetsApplication1::prepareData() {
    // 为序列生成数据
    QLineSeries* series0 = (QLineSeries*)ui.chartView->chart()->series().at(0);
    series0->clear();
    qsrand(QTime::currentTime().second());  // 数据随机初始化
    qreal t = 0, y1, y2, intv = 0.1;
    qreal rd;
    int cnt = 100;
    for (int i = 0; i < cnt; i++) {
        rd = (qrand() % 10) - 5;
        y1 = qSin(t) + rd / 50;
        series0->append(t, y1);
        t += intv;
    }
}

float QtWidgetsApplication1::hexStringToFloat(const std::string& hexString) {
    // 将十六进制字符串转换为无符号整型
    uint32_t hexValue = static_cast<uint32_t>(std::stoul(hexString, nullptr, 16));

    // 将 uint32_t 转换为 float
    float floatValue;
    std::memcpy(&floatValue, &hexValue, sizeof(floatValue)); // 安全的内存复制

    return floatValue;
}

void QtWidgetsApplication1::closeQT() {
    tcpSocket->close();
    QApplication::quit();
}