#include "../headers/homescreen.h"
#include "ui_homescreen.h"

HomeScreen::HomeScreen(QWidget *parent)
    : QWidget{parent},
    ui(new Ui::HomeScreen),
    model(new QStringListModel(this))
{
    ui->setupUi(this);

    // Définir les données pour QListView
    QStringList userList;
    userList << "User1" << "User2" << "User3";
    model->setStringList(userList);

    ui->listView->setModel(model);

    // Connecter le signal de clic à un slot
    connect(ui->listView, &QListView::clicked, this, &HomeScreen::on_listView_clicked);
}

HomeScreen::~HomeScreen() {
    delete ui;
}

void HomeScreen::on_listView_clicked(const QModelIndex &index)
{
    QString userName = model->data(index, Qt::DisplayRole).toString();

    // Créer un nouvel onglet
    QWidget *newTab = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(newTab);

    QLabel *label = new QLabel(userName);
    layout->addWidget(label);

    QPushButton *actionButton = new QPushButton("Effectuer une action sur " + userName);
    layout->addWidget(actionButton);

    newTab->setLayout(layout);

    int tabIndex = ui->tabWidget->addTab(newTab, userName);
    ui->tabWidget->setCurrentIndex(tabIndex);
}

