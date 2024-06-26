#ifndef CLIENTLISTITEM_H
#define CLIENTLISTITEM_H

#include <QWidget>

namespace Ui {
class ClientListItem;
}

class ClientListItem : public QWidget
{
    Q_OBJECT

public:
    explicit ClientListItem(QWidget *parent = nullptr);
    ~ClientListItem();

private:
    Ui::ClientListItem *ui;
};

#endif // CLIENTLISTITEM_H
