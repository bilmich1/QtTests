#ifndef MYEVENTFILTER_H
#define MYEVENTFILTER_H

#include <QAbstractNativeEventFilter>

class containerWidget;

class MyEventFilter : public QAbstractNativeEventFilter
{
public:
    MyEventFilter(containerWidget& container_widget);
    ~MyEventFilter() override;

    bool nativeEventFilter(const QByteArray& event_type, void* message, long*) override;

private:
    containerWidget& container_widget_;
};

#endif // MYEVENTFILTER_H
