#include "connect-server-dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString ip = "127.0.0.1";
    ConnectServerLogin w(ip);
    w.show();

    ConnectServerDialog b;
    b.show();

    return a.exec();
}
