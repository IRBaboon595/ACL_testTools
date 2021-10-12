#include "test_acl_gui.h"

test_acl_gui::test_acl_gui(QObject *parent) : QObject(parent)
{

}

/*test_acl_gui::test_acl_gui(MainWindow *a)
{
    m = new MainWindow(a);
}*/

void test_acl_gui::loginButton_test()
{
    MainWindow m;
    //m.ui.singIn_pushButton
}

void test_acl_gui::initTestCase()
{
    qDebug("Called before everything else.");
}

void test_acl_gui::init()
{
    qDebug("Called before every test");
}

void test_acl_gui::cleanup()
{
    qDebug("Called after any test");
}

void test_acl_gui::cleanupTestCase()
{
    qDebug("Called after myFirstTest and mySecondTest.");
}
