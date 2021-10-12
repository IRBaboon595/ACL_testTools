#ifndef TEST_ACL_BASE_H
#define TEST_ACL_BASE_H

#include <QObject>
#include <QTest>
#include "acl_base.h"
#include <QString>
#include "mainwindow.h"

class test_acl_base : public QObject
{
    Q_OBJECT
public:
    explicit test_acl_base(QObject *parent = nullptr);

signals:

private slots:
    void initTestCase(); //will be called before the first test function is executed.
    //void initTestCase_data(); //will be called to create a global test data table.
    void cleanupTestCase(); //will be called after the last test function was executed.
    void init(); //will be called before each test function is executed.
    void cleanup(); //will be called after every test function.
    void setUserName();
    void getAccessLevel_data();
    void getAccessLevel();
};

#endif // TEST_ACL_BASE_H
