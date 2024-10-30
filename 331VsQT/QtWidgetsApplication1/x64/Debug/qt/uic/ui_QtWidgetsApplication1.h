/********************************************************************************
** Form generated from reading UI file 'QtWidgetsApplication1.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWIDGETSAPPLICATION1_H
#define UI_QTWIDGETSAPPLICATION1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qchartview.h>
#include <QtCharts>
using namespace QtCharts;
QT_BEGIN_NAMESPACE


class Ui_QtWidgetsApplication1Class
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_13;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QLabel *label_17;
    QLineEdit *lineEdit_8;
    QLabel *label_14;
    QLabel *label_16;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLineEdit *lineEdit;
    QLabel *label_7;
    QLineEdit *lineEdit_2;
    QLabel *label_8;
    QLineEdit *lineEdit_3;
    QLabel *label_9;
    QLineEdit *lineEdit_4;
    QLabel *label_10;
    QLineEdit *lineEdit_5;
    QLabel *label_11;
    QLineEdit *lineEdit_6;
    QLabel *label_12;
    QLineEdit *lineEdit_7;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QChartView *chartView;
    QSpacerItem *horizontalSpacer;
    QChartView *chartView_2;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_3;
    QLabel *label_15;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_5;
    QPushButton *openBt;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *QtWidgetsApplication1Class)
    {
        if (QtWidgetsApplication1Class->objectName().isEmpty())
            QtWidgetsApplication1Class->setObjectName(QString::fromUtf8("QtWidgetsApplication1Class"));
        QtWidgetsApplication1Class->resize(1280, 800);
        QtWidgetsApplication1Class->setMinimumSize(QSize(1280, 800));
        QtWidgetsApplication1Class->setMaximumSize(QSize(1280, 800));
        gridLayout_4 = new QGridLayout(QtWidgetsApplication1Class);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox_4 = new QGroupBox(QtWidgetsApplication1Class);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy);
        groupBox_4->setMinimumSize(QSize(500, 260));
        groupBox_4->setMaximumSize(QSize(12000, 800));
        verticalLayout = new QVBoxLayout(groupBox_4);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(groupBox_4);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setMinimumSize(QSize(480, 170));
        scrollArea->setMaximumSize(QSize(800, 800));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 478, 168));
        horizontalLayout_7 = new QHBoxLayout(scrollAreaWidgetContents_2);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_13 = new QLabel(scrollAreaWidgetContents_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(460, 0));
        label_13->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_7->addWidget(label_13);

        scrollArea->setWidget(scrollAreaWidgetContents_2);

        verticalLayout->addWidget(scrollArea);

        groupBox_5 = new QGroupBox(groupBox_4);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_2 = new QGridLayout(groupBox_5);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lineEdit_9 = new QLineEdit(groupBox_5);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_9->sizePolicy().hasHeightForWidth());
        lineEdit_9->setSizePolicy(sizePolicy1);
        lineEdit_9->setMinimumSize(QSize(0, 29));
        lineEdit_9->setMaximumSize(QSize(120, 30));

        gridLayout_2->addWidget(lineEdit_9, 0, 1, 1, 1);

        lineEdit_10 = new QLineEdit(groupBox_5);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        sizePolicy1.setHeightForWidth(lineEdit_10->sizePolicy().hasHeightForWidth());
        lineEdit_10->setSizePolicy(sizePolicy1);
        lineEdit_10->setMinimumSize(QSize(0, 29));
        lineEdit_10->setMaximumSize(QSize(120, 30));

        gridLayout_2->addWidget(lineEdit_10, 0, 2, 1, 1);

        label_17 = new QLabel(groupBox_5);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(14);
        label_17->setFont(font);
        label_17->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_17, 1, 2, 1, 1);

        lineEdit_8 = new QLineEdit(groupBox_5);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        sizePolicy1.setHeightForWidth(lineEdit_8->sizePolicy().hasHeightForWidth());
        lineEdit_8->setSizePolicy(sizePolicy1);
        lineEdit_8->setMinimumSize(QSize(0, 29));
        lineEdit_8->setMaximumSize(QSize(120, 30));

        gridLayout_2->addWidget(lineEdit_8, 0, 0, 1, 1);

        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font);
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_14, 1, 0, 1, 1);

        label_16 = new QLabel(groupBox_5);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font);
        label_16->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_16, 1, 1, 1, 1);


        verticalLayout->addWidget(groupBox_5);


        gridLayout_4->addWidget(groupBox_4, 3, 1, 1, 1);

        groupBox_3 = new QGroupBox(QtWidgetsApplication1Class);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(330, 260));
        groupBox_3->setMaximumSize(QSize(335, 265));
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        lineEdit = new QLineEdit(groupBox_3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(groupBox_3);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        lineEdit_3 = new QLineEdit(groupBox_3);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(lineEdit_3, 2, 1, 1, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        gridLayout->addWidget(label_9, 3, 0, 1, 1);

        lineEdit_4 = new QLineEdit(groupBox_3);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(lineEdit_4, 3, 1, 1, 1);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);

        gridLayout->addWidget(label_10, 4, 0, 1, 1);

        lineEdit_5 = new QLineEdit(groupBox_3);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(lineEdit_5, 4, 1, 1, 1);

        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);

        gridLayout->addWidget(label_11, 5, 0, 1, 1);

        lineEdit_6 = new QLineEdit(groupBox_3);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(lineEdit_6, 5, 1, 1, 1);

        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);

        gridLayout->addWidget(label_12, 6, 0, 1, 1);

        lineEdit_7 = new QLineEdit(groupBox_3);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(lineEdit_7, 6, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 3, 0, 1, 1);

        groupBox_2 = new QGroupBox(QtWidgetsApplication1Class);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(1260, 370));
        groupBox_2->setMaximumSize(QSize(1265, 375));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        chartView = new QChartView(groupBox_2);
        chartView->setObjectName(QString::fromUtf8("chartView"));
        sizePolicy.setHeightForWidth(chartView->sizePolicy().hasHeightForWidth());
        chartView->setSizePolicy(sizePolicy);
        chartView->setMinimumSize(QSize(600, 340));
        chartView->setMaximumSize(QSize(600, 345));

        horizontalLayout_2->addWidget(chartView);

        horizontalSpacer = new QSpacerItem(10, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        chartView_2 = new QChartView(groupBox_2);
        chartView_2->setObjectName(QString::fromUtf8("chartView_2"));
        sizePolicy.setHeightForWidth(chartView_2->sizePolicy().hasHeightForWidth());
        chartView_2->setSizePolicy(sizePolicy);
        chartView_2->setMinimumSize(QSize(600, 340));
        chartView_2->setMaximumSize(QSize(600, 345));

        horizontalLayout_2->addWidget(chartView_2);


        gridLayout_4->addWidget(groupBox_2, 1, 0, 1, 4);

        groupBox_6 = new QGroupBox(QtWidgetsApplication1Class);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setMaximumSize(QSize(16777215, 200));
        gridLayout_3 = new QGridLayout(groupBox_6);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_15 = new QLabel(groupBox_6);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        sizePolicy.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy);
        label_15->setMinimumSize(QSize(60, 60));
        label_15->setMaximumSize(QSize(60, 60));

        gridLayout_3->addWidget(label_15, 0, 0, 1, 1);

        label_18 = new QLabel(groupBox_6);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setMinimumSize(QSize(60, 60));
        label_18->setMaximumSize(QSize(60, 60));

        gridLayout_3->addWidget(label_18, 0, 1, 1, 1);

        label_19 = new QLabel(groupBox_6);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setMaximumSize(QSize(16777215, 50));
        label_19->setFont(font);

        gridLayout_3->addWidget(label_19, 1, 0, 1, 1);

        label_20 = new QLabel(groupBox_6);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setFont(font);

        gridLayout_3->addWidget(label_20, 1, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_6, 3, 2, 1, 1);

        label = new QLabel(QtWidgetsApplication1Class);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(347, 71));
        label->setMaximumSize(QSize(347, 71));

        gridLayout_4->addWidget(label, 0, 2, 1, 2);

        groupBox_7 = new QGroupBox(QtWidgetsApplication1Class);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setMaximumSize(QSize(160, 16777215));
        gridLayout_5 = new QGridLayout(groupBox_7);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        openBt = new QPushButton(groupBox_7);
        openBt->setObjectName(QString::fromUtf8("openBt"));
        openBt->setMinimumSize(QSize(110, 50));
        openBt->setMaximumSize(QSize(120, 55));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(16);
        openBt->setFont(font1);

        gridLayout_5->addWidget(openBt, 0, 0, 1, 1);

        pushButton_6 = new QPushButton(groupBox_7);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(110, 50));
        pushButton_6->setMaximumSize(QSize(120, 55));
        pushButton_6->setFont(font1);

        gridLayout_5->addWidget(pushButton_6, 1, 0, 1, 1);

        pushButton_7 = new QPushButton(groupBox_7);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(110, 50));
        pushButton_7->setMaximumSize(QSize(120, 55));
        pushButton_7->setFont(font1);

        gridLayout_5->addWidget(pushButton_7, 2, 0, 1, 1);

        pushButton_8 = new QPushButton(groupBox_7);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(110, 50));
        pushButton_8->setMaximumSize(QSize(120, 55));
        pushButton_8->setFont(font1);

        gridLayout_5->addWidget(pushButton_8, 3, 0, 1, 1);

        pushButton_9 = new QPushButton(groupBox_7);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(110, 50));
        pushButton_9->setMaximumSize(QSize(120, 55));
        pushButton_9->setFont(font1);

        gridLayout_5->addWidget(pushButton_9, 4, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_7, 3, 3, 1, 1);

        groupBox = new QGroupBox(QtWidgetsApplication1Class);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(100, 50));
        pushButton->setMaximumSize(QSize(110, 55));
        pushButton->setFont(font1);

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(100, 50));
        pushButton_2->setMaximumSize(QSize(110, 55));
        pushButton_2->setFont(font1);

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(100, 50));
        pushButton_3->setMaximumSize(QSize(110, 55));
        pushButton_3->setFont(font1);

        horizontalLayout->addWidget(pushButton_3);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(QtWidgetsApplication1Class);

        QMetaObject::connectSlotsByName(QtWidgetsApplication1Class);
    } // setupUi

    void retranslateUi(QWidget *QtWidgetsApplication1Class)
    {
        QtWidgetsApplication1Class->setWindowTitle(QCoreApplication::translate("QtWidgetsApplication1Class", "QtWidgetsApplication1", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("QtWidgetsApplication1Class", "\344\277\241\346\201\257\346\240\217", nullptr));
        label_13->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "TextLabel", nullptr));
        groupBox_5->setTitle(QString());
        label_17->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\345\256\236\351\231\205\344\277\235\345\216\213\346\227\266\351\227\264", nullptr));
        label_14->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\345\256\236\351\231\205\350\276\223\345\207\272\345\212\233(N)", nullptr));
        label_16->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\345\256\236\351\231\205\344\275\215\347\247\273(mm)", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("QtWidgetsApplication1Class", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_6->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\345\216\213\350\243\205\345\212\233\344\270\213\351\231\220(N)\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\345\216\213\350\243\205\345\212\233\344\270\212\351\231\220(N)\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\345\216\213\350\243\205\351\200\237\345\272\246(mm/s)\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\345\216\213\350\243\205\344\275\215\347\247\273\344\270\213\351\231\220(mm)\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\345\216\213\350\243\205\344\275\215\347\247\273\344\270\212\351\231\220(mm)\357\274\232", nullptr));
        label_11->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\347\233\256\346\240\207\344\277\235\345\216\213\346\227\266\351\227\264\357\274\232", nullptr));
        label_12->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\344\277\235\345\216\213\345\216\213\345\212\233(N)\357\274\232", nullptr));
        groupBox_2->setTitle(QString());
        groupBox_6->setTitle(QCoreApplication::translate("QtWidgetsApplication1Class", "\347\212\266\346\200\201\346\240\217", nullptr));
        label_15->setText(QString());
        label_18->setText(QString());
        label_19->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\351\200\232\344\277\241\347\212\266\346\200\201", nullptr));
        label_20->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\347\263\273\347\273\237\347\212\266\346\200\201", nullptr));
        label->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "TextLabel", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("QtWidgetsApplication1Class", "\346\223\215\344\275\234\346\240\217", nullptr));
        openBt->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\350\277\236\346\216\245", nullptr));
        pushButton_6->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\350\256\276\345\256\232", nullptr));
        pushButton_7->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\345\257\274\345\207\272\346\212\245\345\221\212", nullptr));
        pushButton_8->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\346\270\205\347\251\272\347\252\227\345\217\243", nullptr));
        pushButton_9->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\344\277\235\345\255\230\345\261\236\346\200\247", nullptr));
        groupBox->setTitle(QString());
        pushButton->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\351\205\215 \347\275\256", nullptr));
        pushButton_2->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\345\270\256 \345\212\251", nullptr));
        pushButton_3->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\351\200\200 \345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtWidgetsApplication1Class: public Ui_QtWidgetsApplication1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWIDGETSAPPLICATION1_H
