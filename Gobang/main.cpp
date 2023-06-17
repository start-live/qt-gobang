#include "imainwidgetwidget.h"

#include "iboardwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IBoardWidget w;
    w.show();
    return a.exec();
}
