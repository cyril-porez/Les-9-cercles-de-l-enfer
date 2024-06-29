#ifndef HOMESCREEN_H
#define HOMESCREEN_H

#include <QWidget>
#include <QStringListModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class HomeScreen;
}
QT_END_NAMESPACE
class HomeScreen : public QWidget
{
    Q_OBJECT
public:
    explicit HomeScreen(QWidget *parent = nullptr);
    ~HomeScreen();

private:
    Ui::HomeScreen *ui;
    QStringListModel *model;

signals:
private slots:
    void on_listView_clicked(const QModelIndex &index);
    void on_tabWidget_tabCloseRequested(int index);
};

#endif // HOMESCREEN_H
