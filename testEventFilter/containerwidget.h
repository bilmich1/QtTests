#ifndef CONTAINERWIDGET_H
#define CONTAINERWIDGET_H

#include "myeventfilter.h"
#include "subwidget.h"

#include <QWidget>

#include <vector>
#include <memory>

namespace Ui {
class containerWidget;
}

class containerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit containerWidget(QWidget *parent = nullptr);
    ~containerWidget() override;

    void printPosition(int x, int y);

private:
    Ui::containerWidget *ui;
    std::vector<std::unique_ptr<subWidget>> sub_widgets;
    MyEventFilter event_filter_;
};

#endif // CONTAINERWIDGET_H
