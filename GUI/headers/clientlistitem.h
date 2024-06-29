#ifndef CLIENTLISTITEM_H
#define CLIENTLISTITEM_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class ClientListItem;
}
QT_END_NAMESPACE
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
