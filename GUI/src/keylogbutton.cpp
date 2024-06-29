#include "keylogbutton.h"
#include "ui_keylogbutton.h"

KeyLogButton::KeyLogButton(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::KeyLogButton)
{
    ui->setupUi(this);
}

KeyLogButton::~KeyLogButton()
{
    delete ui;
}

void KeyLogButton::on_keylogButton_clicked()
{
    isKeylogOn = !isKeylogOn;
    ui->keylogButton->setText(
        isKeylogOn == true ?
        "Keylog ON" : "Keylog OFF"
    );
    ui->keylogButton->setStyleSheet(
        isKeylogOn == true ?
        "color: lime" : "color: red"
    );
}

