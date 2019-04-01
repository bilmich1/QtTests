#include "eventfilter.h"

#include <QApplication>
#include <QMessageBox>

#include <winuser.h>
#include <windowsx.h>

eventFilter::eventFilter()
{
    QApplication::instance()->installNativeEventFilter(this);
}

eventFilter::~eventFilter()
{
    QApplication::instance()->removeNativeEventFilter(this);
}

bool eventFilter::nativeEventFilter(const QByteArray& eventType, void* message, long*)
{
    if (eventType == "windows_generic_MSG")
    {
        LPMSG msg = static_cast<LPMSG>(message);

        if (WM_LBUTTONDOWN == msg->message || WM_LBUTTONUP == msg->message)
        {
            int x = GET_X_LPARAM(msg->lParam);
            int y = GET_Y_LPARAM(msg->lParam);
            QMessageBox message(QMessageBox::NoIcon, "Title", QString("X: %1, Y: %2").arg(x, y), QMessageBox::Ok);
        }
    }

    return false;
}
