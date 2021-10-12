#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    freopen("testing.log", "w", stdout);
    QApplication a(argc, argv);
    QTest::qExec(new test_acl_base, argc, argv);
    MainWindow w;
    w.show();
    //QTest::qExec(new test_acl_gui(&w), argc, argv);
    return a.exec();
}
