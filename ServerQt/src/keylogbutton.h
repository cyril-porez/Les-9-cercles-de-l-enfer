#ifndef KEYLOGBUTTON_H
#define KEYLOGBUTTON_H

#include <QFrame>

namespace Ui {
class KeyLogButton;
}

class KeyLogButton : public QFrame
{
    Q_OBJECT

public:
    explicit KeyLogButton(QWidget *parent = nullptr);
    ~KeyLogButton();

private slots:
    void on_keylogButton_clicked();

private:
    Ui::KeyLogButton *ui;
    bool isKeylogOn;
};

#endif // KEYLOGBUTTON_H
