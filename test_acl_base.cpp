#include "test_acl_base.h"


test_acl_base::test_acl_base(QObject *parent) : QObject(parent)
{

}

void test_acl_base::initTestCase()
{
    qDebug("Called before everything else.");
}

void test_acl_base::init()
{
    qDebug("Called before every test");
}

void test_acl_base::setUserName()
{
    acl_base *temp = new acl_base("Piotr");

    QCOMPARE(temp->getUserName(), "Piotr");
}

void test_acl_base::getAccessLevel_data()
{
    QTest::addColumn<QString>("user1");
    QTest::addColumn<QString>("result");

    QTest::newRow("First") << "First"<< "Forbidden";
    QTest::newRow("Second") << "Second"<< "Forbidden";
    QTest::newRow("Third") << "Third"<< "Forbidden";
}

void test_acl_base::getAccessLevel()
{
    acl_base temp;
    temp.setUserName("Piotr");
    temp.addProcessList({"First", "Second", "Third"});

    QFETCH(QString, user1);
    QFETCH(QString, result);

    QCOMPARE(temp.getAccessLevel(user1), result);
}

void test_acl_base::cleanup()
{
    qDebug("Called after any test");
}

void test_acl_base::cleanupTestCase()
{
    qDebug("Called after myFirstTest and mySecondTest.");
}
