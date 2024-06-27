#include "../headers/homescreen.h"
#include "ui_homescreen.h"

HomeScreen::HomeScreen(QWidget *parent)
    : QWidget{parent},
    ui(new Ui::HomeScreen)
{
    ui->setupUi(this);
}

HomeScreen::~HomeScreen() {
    delete ui;
}

void HomeScreen::on_tabWidget_tabBarClicked(int index)
{

}

