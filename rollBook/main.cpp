#include "rollbookwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    rollBookWidget w;
    w.show();

    return a.exec();
}
