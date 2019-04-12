#include "subwidget.h"
#include "ui_subwidget.h"

subWidget::subWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::subWidget)
{
    ui->setupUi(this);
}

subWidget::~subWidget()
{
    delete ui;
}

void subWidget::setPosition(int x, int y)
{
    ui->position_label_->setText(QString("X: %1, Y%2").arg(x).arg(y));
}
