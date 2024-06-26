/********************************************************************************
** Form generated from reading UI file 'clientlistitem.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTLISTITEM_H
#define UI_CLIENTLISTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientListItem
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *ClientListItem)
    {
        if (ClientListItem->objectName().isEmpty())
            ClientListItem->setObjectName("ClientListItem");
        ClientListItem->resize(620, 77);
        ClientListItem->setStyleSheet(QString::fromUtf8("border: 1px solid #ccc"));
        horizontalLayoutWidget = new QWidget(ClientListItem);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(20, 0, 151, 71));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label, 0, Qt::AlignLeft);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("background-color: red;\n"
"border-radius: 5px;"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2, 0, Qt::AlignVCenter);


        retranslateUi(ClientListItem);

        QMetaObject::connectSlotsByName(ClientListItem);
    } // setupUi

    void retranslateUi(QWidget *ClientListItem)
    {
        ClientListItem->setWindowTitle(QCoreApplication::translate("ClientListItem", "Form", nullptr));
        label->setText(QCoreApplication::translate("ClientListItem", "10.10.0.1", nullptr));
        label_2->setText(QCoreApplication::translate("ClientListItem", "Offline", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientListItem: public Ui_ClientListItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTLISTITEM_H
