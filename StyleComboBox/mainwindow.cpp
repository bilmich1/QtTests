#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QComboBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setStyleSheet(R"(QComboBox { font: 14pt "Arial"; })");

    addComboBox();

    connect(ui->AddComboBox, &QPushButton::clicked, this, &MainWindow::addComboBox);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addComboBox()
{
    auto* combobox = new QComboBox();
    combobox->addItem("text 1");
    combobox->addItem("text 2");
    combobox->addItem("text 3");
    combobox->addItem("text 4");
    combobox->addItem("text 5");
    ui->frame->layout()->addWidget(combobox);
}
