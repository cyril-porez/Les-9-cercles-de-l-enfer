/********************************************************************************
** Form generated from reading UI file 'homescreen.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMESCREEN_H
#define UI_HOMESCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomeScreen
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *hostInfo;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *hostnameLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QListView *listView;
    QWidget *tab_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *hostInfo_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLabel *hostnameLabel_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLabel *label_7;
    QFrame *frame;
    QLabel *label_11;
    QPushButton *pushButton;
    QCheckBox *checkBox;
    QFrame *frame_2;
    QLabel *label_12;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_13;
    QWidget *tab_3;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *hostInfo_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QLabel *hostnameLabel_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_14;
    QFrame *frame_3;
    QLabel *label_20;
    QPlainTextEdit *plainTextEdit_3;
    QFrame *frame_4;
    QLabel *label_21;
    QPushButton *pushButton_3;
    QCheckBox *checkBox_3;

    void setupUi(QWidget *HomeScreen)
    {
        if (HomeScreen->objectName().isEmpty())
            HomeScreen->setObjectName("HomeScreen");
        HomeScreen->resize(800, 600);
        verticalLayoutWidget = new QWidget(HomeScreen);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(20, 20, 301, 80));
        hostInfo = new QVBoxLayout(verticalLayoutWidget);
        hostInfo->setObjectName("hostInfo");
        hostInfo->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setBold(true);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        hostnameLabel = new QLabel(verticalLayoutWidget);
        hostnameLabel->setObjectName("hostnameLabel");

        horizontalLayout->addWidget(hostnameLabel);


        hostInfo->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);


        hostInfo->addLayout(horizontalLayout_2);

        label_4 = new QLabel(HomeScreen);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(270, 200, 251, 16));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setKerning(true);
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);
        tabWidget = new QTabWidget(HomeScreen);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(90, 250, 621, 331));
        tab = new QWidget();
        tab->setObjectName("tab");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy);
        listView = new QListView(tab);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(0, 0, 620, 301));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy1);
        listView->setItemAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        verticalLayoutWidget_2 = new QWidget(tab_2);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 301, 80));
        hostInfo_2 = new QVBoxLayout(verticalLayoutWidget_2);
        hostInfo_2->setObjectName("hostInfo_2");
        hostInfo_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName("label_5");
        label_5->setFont(font);

        horizontalLayout_3->addWidget(label_5);

        hostnameLabel_2 = new QLabel(verticalLayoutWidget_2);
        hostnameLabel_2->setObjectName("hostnameLabel_2");

        horizontalLayout_3->addWidget(hostnameLabel_2);


        hostInfo_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_6 = new QLabel(verticalLayoutWidget_2);
        label_6->setObjectName("label_6");
        label_6->setFont(font);

        horizontalLayout_4->addWidget(label_6);

        label_7 = new QLabel(verticalLayoutWidget_2);
        label_7->setObjectName("label_7");

        horizontalLayout_4->addWidget(label_7);


        hostInfo_2->addLayout(horizontalLayout_4);

        frame = new QFrame(tab_2);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 110, 151, 181));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(1);
        label_11 = new QLabel(frame);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(0, 0, 151, 21));
        label_11->setStyleSheet(QString::fromUtf8("background-color: #ccc; color: black"));
        label_11->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 40, 111, 24));
        checkBox = new QCheckBox(frame);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(20, 80, 111, 22));
        checkBox->setChecked(true);
        frame_2 = new QFrame(tab_2);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(180, 110, 421, 181));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_2->setLineWidth(1);
        label_12 = new QLabel(frame_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(0, 0, 421, 21));
        label_12->setStyleSheet(QString::fromUtf8("background-color: #ccc; color: black"));
        label_12->setAlignment(Qt::AlignCenter);
        plainTextEdit = new QPlainTextEdit(frame_2);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(0, 20, 421, 161));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Courier")});
        font2.setPointSize(11);
        font2.setBold(true);
        plainTextEdit->setFont(font2);
        plainTextEdit->setStyleSheet(QString::fromUtf8("background-color: black; \n"
"color: green; \n"
"font-family: Courier, monospace;\n"
"font-weight: bold;"));
        label_13 = new QLabel(tab_2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(380, 20, 181, 51));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        label_13->setFont(font3);
        label_13->setLineWidth(1);
        label_13->setScaledContents(false);
        label_13->setAlignment(Qt::AlignCenter);
        label_13->setWordWrap(true);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        verticalLayoutWidget_3 = new QWidget(tab_3);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(10, 10, 291, 81));
        hostInfo_3 = new QVBoxLayout(verticalLayoutWidget_3);
        hostInfo_3->setObjectName("hostInfo_3");
        hostInfo_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_8 = new QLabel(verticalLayoutWidget_3);
        label_8->setObjectName("label_8");
        label_8->setFont(font);

        horizontalLayout_5->addWidget(label_8);

        hostnameLabel_3 = new QLabel(verticalLayoutWidget_3);
        hostnameLabel_3->setObjectName("hostnameLabel_3");

        horizontalLayout_5->addWidget(hostnameLabel_3);


        hostInfo_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_9 = new QLabel(verticalLayoutWidget_3);
        label_9->setObjectName("label_9");
        label_9->setFont(font);

        horizontalLayout_6->addWidget(label_9);

        label_10 = new QLabel(verticalLayoutWidget_3);
        label_10->setObjectName("label_10");

        horizontalLayout_6->addWidget(label_10);


        hostInfo_3->addLayout(horizontalLayout_6);

        label_14 = new QLabel(tab_3);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(390, 20, 181, 51));
        label_14->setFont(font3);
        label_14->setLineWidth(1);
        label_14->setScaledContents(false);
        label_14->setAlignment(Qt::AlignCenter);
        label_14->setWordWrap(true);
        frame_3 = new QFrame(tab_3);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(180, 110, 421, 181));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_3->setLineWidth(1);
        label_20 = new QLabel(frame_3);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(0, 0, 421, 21));
        label_20->setStyleSheet(QString::fromUtf8("background-color: #ccc; color: black"));
        label_20->setAlignment(Qt::AlignCenter);
        plainTextEdit_3 = new QPlainTextEdit(frame_3);
        plainTextEdit_3->setObjectName("plainTextEdit_3");
        plainTextEdit_3->setGeometry(QRect(0, 20, 421, 161));
        plainTextEdit_3->setFont(font2);
        plainTextEdit_3->setStyleSheet(QString::fromUtf8("background-color: black; \n"
"color: green; \n"
"font-family: Courier, monospace;\n"
"font-weight: bold;"));
        frame_4 = new QFrame(tab_3);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(10, 110, 151, 181));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        frame_4->setLineWidth(1);
        label_21 = new QLabel(frame_4);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(0, 0, 151, 21));
        label_21->setStyleSheet(QString::fromUtf8("background-color: #ccc; color: black"));
        label_21->setAlignment(Qt::AlignCenter);
        pushButton_3 = new QPushButton(frame_4);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(20, 40, 111, 24));
        checkBox_3 = new QCheckBox(frame_4);
        checkBox_3->setObjectName("checkBox_3");
        checkBox_3->setGeometry(QRect(20, 80, 111, 22));
        checkBox_3->setChecked(true);
        tabWidget->addTab(tab_3, QString());

        retranslateUi(HomeScreen);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(HomeScreen);
    } // setupUi

    void retranslateUi(QWidget *HomeScreen)
    {
        HomeScreen->setWindowTitle(QCoreApplication::translate("HomeScreen", "Form", nullptr));
        label->setText(QCoreApplication::translate("HomeScreen", "Nom de l'ordinateur h\303\264te:", nullptr));
        hostnameLabel->setText(QCoreApplication::translate("HomeScreen", "hostnameLabel", nullptr));
        label_2->setText(QCoreApplication::translate("HomeScreen", "Utilisateur connect\303\251:", nullptr));
        label_3->setText(QCoreApplication::translate("HomeScreen", "loggedUserLabel", nullptr));
        label_4->setText(QCoreApplication::translate("HomeScreen", "Liste des clients connect\303\251s", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("HomeScreen", "Tous", nullptr));
        label_5->setText(QCoreApplication::translate("HomeScreen", "Nom de l'utilisateur:", nullptr));
        hostnameLabel_2->setText(QCoreApplication::translate("HomeScreen", "clientName1", nullptr));
        label_6->setText(QCoreApplication::translate("HomeScreen", "Syst\303\250me d'exploitation:", nullptr));
        label_7->setText(QCoreApplication::translate("HomeScreen", "Windows 11", nullptr));
        label_11->setText(QCoreApplication::translate("HomeScreen", "Actions", nullptr));
        pushButton->setText(QCoreApplication::translate("HomeScreen", "List des process", nullptr));
        checkBox->setText(QCoreApplication::translate("HomeScreen", "Keylogger", nullptr));
        label_12->setText(QCoreApplication::translate("HomeScreen", "Lancer des commandes syst\303\250mes", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("HomeScreen", "C:\\users\\clientName1> ls", nullptr));
        label_13->setText(QCoreApplication::translate("HomeScreen", "<html><head/><body><p align=\"center\">clientName1</p><p align=\"center\">10.10.0.1</p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("HomeScreen", "clientName1 [10.10.0.1]", nullptr));
        label_8->setText(QCoreApplication::translate("HomeScreen", "Nom de l'utilisateur:", nullptr));
        hostnameLabel_3->setText(QCoreApplication::translate("HomeScreen", "clientName2", nullptr));
        label_9->setText(QCoreApplication::translate("HomeScreen", "Syst\303\250me d'exploitation:", nullptr));
        label_10->setText(QCoreApplication::translate("HomeScreen", "Ubuntu 24.04", nullptr));
        label_14->setText(QCoreApplication::translate("HomeScreen", "<html><head/><body><p align=\"center\">clientName2</p><p align=\"center\">10.10.0.2</p></body></html>", nullptr));
        label_20->setText(QCoreApplication::translate("HomeScreen", "Lancer des commandes syst\303\250mes", nullptr));
        plainTextEdit_3->setPlainText(QCoreApplication::translate("HomeScreen", "clientName2@ubuntu:~$ ls", nullptr));
        label_21->setText(QCoreApplication::translate("HomeScreen", "Actions", nullptr));
        pushButton_3->setText(QCoreApplication::translate("HomeScreen", "List des process", nullptr));
        checkBox_3->setText(QCoreApplication::translate("HomeScreen", "Keylogger", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("HomeScreen", "clientName2 [10.10.0.2]", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomeScreen: public Ui_HomeScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMESCREEN_H
