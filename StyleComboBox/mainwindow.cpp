#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QComboBox>
#include <QListView>
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setStyleSheet(R"(QComboBox, QListView { font: 14pt "Arial"; })");

    addComboBox();
    addListView();

    connect(ui->AddComboBox, &QPushButton::clicked, [this](){addComboBox(); addListView();});
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

void MainWindow::addListView()
{
    QStandardItemModel* model = new QStandardItemModel();

    for (int i = 1; i < 6; i++)
    {
        model->appendRow(new QStandardItem(QString::number(i)));
    }

    auto* listview = new QListView();
    listview->setModel(model);

    ui->frame->layout()->addWidget(listview);
}
