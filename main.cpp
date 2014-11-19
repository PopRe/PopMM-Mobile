#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("Populous Reincarnated");
    QCoreApplication::setOrganizationDomain("http://www.popre.net/");
    QCoreApplication::setApplicationName(QString("PopMMMobile"));

    Dialog w;
    w.showMaximized();

    return a.exec();
}
