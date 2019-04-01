#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "myeventfilter.h"

#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::MainWindow),
    event_filter_(*this)
{
    ui_->setupUi(this);

    MyEventFilter event_filter(*this);

    connect(ui_->exit_button_, &QPushButton::clicked, []()
    {
        QCoreApplication::instance()->exit();
    });
}

MainWindow::~MainWindow()
{
    delete ui_;
}

void MainWindow::printPosition(int x, int y)
{
    ui_->position_label_->setText(QString("Position X: %1, Y: %2").arg(x).arg(y));
}
