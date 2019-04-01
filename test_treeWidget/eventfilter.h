#ifndef EVENTFILTER_H
#define EVENTFILTER_H

#include <QAbstractNativeEventFilter>

class eventFilter : public QAbstractNativeEventFilter
{
public:
    eventFilter();
    ~eventFilter() override;

    bool nativeEventFilter(const QByteArray &eventType, void* message, long*) override;
};

#endif // EVENTFILTER_H
