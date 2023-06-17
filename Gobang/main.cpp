#include "imainwidgetwidget.h"

#include "iboardwidget.h"

#include "iscenewidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ISceneWidget w;
    w.show();
    return a.exec();
}
