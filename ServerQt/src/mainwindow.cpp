#include "../headers/mainwindow.h"
#include "../ui/ui_mainwindow.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Créer un widget central
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Créer un layout vertical principal
    QVBoxLayout *mainLayout = new QVBoxLayout;

    // Créer les labels pour les informations
    QLabel *labelHostName = new QLabel("Nom de l’ordinateur Hôte et OS: PC, Windows", this);
    QLabel *labelLoggedUser = new QLabel("Logged User: Gozylla", this);

    // Ajouter les labels au layout principal
    mainLayout->addWidget(labelHostName);
    mainLayout->addWidget(labelLoggedUser);

    // Ajouter un espacement vertical pour séparer les informations du titre
    mainLayout->addSpacing(20); // espace de 20 pixels

    // Créer un layout horizontal pour centrer le titre
    QHBoxLayout *titleLayout = new QHBoxLayout;
    QLabel *titleLabel = new QLabel("Liste des clients connectés", this);

    // Ajouter des espacement à gauche et à droite pour centrer le titre
    titleLayout->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    titleLayout->addWidget(titleLabel);
    titleLayout->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));

    // Ajouter le layout du titre au layout principal
    mainLayout->addLayout(titleLayout);

    // Ajouter un espacement vertical pour pousser tout en haut
    mainLayout->addStretch();

    // Appliquer le layout principal au widget central
    centralWidget->setLayout(mainLayout);

    this->setStyleSheet("background-color: #FCE6BF");
    labelHostName->setStyleSheet("color: black; font-size: 14px");
    titleLabel->setStyleSheet("color: black; font-size: 14px; font-weight: bold");
    labelLoggedUser->setStyleSheet("color: black; font-size: 14px");
   // labelHostName->setStyleSheet("color: black");
}

MainWindow::~MainWindow()
{
    delete ui;
}
