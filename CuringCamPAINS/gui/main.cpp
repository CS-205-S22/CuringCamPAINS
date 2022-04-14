#include "dashboard.h"
#include "logingui.h"
#include "contacts.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Dashboard w;
//    w.show();

    Contacts c;
    c.show();

//    LoginGUI l ;
//    l.show();
    return a.exec();
}
