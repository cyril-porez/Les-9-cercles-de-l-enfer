#include "../headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    homeScreen(new HomeScreen(this))
{
    setWindowTitle("Les 9 cercles");
    ui->setupUi(this);
    setCentralWidget(homeScreen);
}

MainWindow::~MainWindow()
{
    delete ui;
}
