#ifndef MYEVENTFILTER_H
#define MYEVENTFILTER_H

#include <QAbstractNativeEventFilter>

class MainWindow;

class MyEventFilter : public QAbstractNativeEventFilter
{
public:
    MyEventFilter(MainWindow& main_window);
    ~MyEventFilter() override;

    bool nativeEventFilter(const QByteArray& event_type, void* message, long*) override;

private:
    MainWindow& main_window_;
};

#endif // MYEVENTFILTER_H
