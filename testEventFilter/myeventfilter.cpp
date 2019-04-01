#include "myeventfilter.h"

#include "mainwindow.h"

#include <QApplication>
#include <QAbstractEventDispatcher>

#include <Windows.h>
#include <windowsx.h>

MyEventFilter::MyEventFilter(MainWindow& main_window)
    : main_window_(main_window)
{
    QApplication::instance()->eventDispatcher()->installNativeEventFilter(this);
}

MyEventFilter::~MyEventFilter()
{
    QApplication::instance()->eventDispatcher()->removeNativeEventFilter(this);
}

bool MyEventFilter::nativeEventFilter(const QByteArray &event_type, void *message, long *)
{
    if (event_type == "windows_generic_MSG")
    {
        LPMSG msg = static_cast<LPMSG>(message);

        if (WM_LBUTTONDOWN == msg->message || WM_LBUTTONUP == msg->message)
        {
            int x = GET_X_LPARAM(msg->lParam);
            int y = GET_Y_LPARAM(msg->lParam);
            main_window_.printPosition(x, y);
        }
    }

    //the message should still be delivered to the widgets
    const bool filter_message_out(false);
    return filter_message_out;
}
