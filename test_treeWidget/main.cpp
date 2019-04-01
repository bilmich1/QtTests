#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qApp->setStyleSheet("QTreeWidget"
                        "{"
                            "font-family: \"Arial\";"
                            "font-style: normal;"
                            "font-size: 16pt;"
                            "font-weight: bold;"
                        "}");

    MainWindow w;
    w.show();

    return a.exec();
}
