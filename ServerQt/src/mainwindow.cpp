#include "../headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    homeScreen(new HomeScreen(this))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
