#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "containerwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);

    auto* container_widget = new containerWidget(nullptr);
    container_widget->show();
}

MainWindow::~MainWindow()
{
    delete ui_;
}
