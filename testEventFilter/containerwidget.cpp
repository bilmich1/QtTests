#include "containerwidget.h"
#include "ui_containerwidget.h"

#include "subwidget.h"

#include <QGridLayout>

containerWidget::containerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::containerWidget),
    sub_widgets(),
    event_filter_(*this)
{
    ui->setupUi(this);
    ui->frame->setLayout(new QGridLayout());

    for (int i = 0; i < 4; ++i)
    {
        sub_widgets.emplace_back(std::make_unique<subWidget>(this));
    }

    int current_row = 0;
    int current_column = 0;
    auto* frame_layout = static_cast<QGridLayout*>(ui->frame->layout());
    for (auto& sub : sub_widgets)
    {
        frame_layout->addWidget(sub.get(), current_row, current_column);
        if (current_column < 1)
        {
            current_column++;
        }
        else
        {
            current_column = 0;
            current_row++;
        }
    }
}

containerWidget::~containerWidget()
{
    delete ui;
}

void containerWidget::printPosition(int x, int y)
{
    for (auto& sub : sub_widgets)
    {
        if (sub->geometry().contains(x, y))
        {
            sub->setPosition(x, y);
            break;
        }
    }
}
