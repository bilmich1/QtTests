#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dialog.h"

#include <QTreeWidgetItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
    setTreeData();
    ui->treeWidget->resizeColumnToContents(0);

    connect(ui->treeWidget, &QTreeWidget::itemDoubleClicked, this, &MainWindow::showDialog);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::showDialog);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setTreeData()
{
    auto* tree_widget_item = new QTreeWidgetItem(ui->treeWidget);
    tree_widget_item->setText(0, "abcdefghijklmnopqrstuvwxy1zabcdefghijklmnopqrstuvwxyz2");
}

void MainWindow::showDialog()
{
   auto* dialog = new Dialog(this);
   dialog->open();
}
