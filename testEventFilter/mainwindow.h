#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "myeventfilter.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void printPosition(int x, int y);

private:
    Ui::MainWindow *ui_;
    MyEventFilter event_filter_;
};

#endif // MAINWINDOW_H
