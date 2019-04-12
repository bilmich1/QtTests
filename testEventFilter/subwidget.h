#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>

namespace Ui {
class subWidget;
}

class subWidget : public QWidget
{
    Q_OBJECT

public:
    explicit subWidget(QWidget *parent = nullptr);
    ~subWidget();

    void setPosition(int x, int y);

private:
    Ui::subWidget *ui;
};

#endif // SUBWIDGET_H
