#include "clientlistitem.h"
#include "ui_clientlistitem.h"

ClientListItem::ClientListItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClientListItem)
{
    ui->setupUi(this);
}

ClientListItem::~ClientListItem()
{
    delete ui;
}
