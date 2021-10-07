#ifndef ACL_BASE_H
#define ACL_BASE_H

#include <QObject>
#include <stdlib.h>
#include <QDebug>

class acl_base : public QObject
{
    Q_OBJECT
    /*Q_PROPERTY(QString username READ getUserName WRITE setUserName NOTIFY userNameChanged)
    Q_PROPERTY(QStringList processes READ getProcessesList WRITE addProcessList NOTIFY processListChanged)
    Q_PROPERTY(QStringList process_access READ getProcessesAccess WRITE setUserName NOTIFY processAccessChanged)*/

public:
    explicit acl_base(QObject *parent = nullptr);
    explicit acl_base(acl_base &base_temp);
    explicit acl_base(acl_base *base_temp);
    explicit acl_base(QString name);
    explicit acl_base(QString name, QString process_name, QString access_level);
    ~acl_base();

    void setUserName(QString name);
    void addProcessList(QStringList process_list);
    void manage_process(QString process_name, QString access_level);

    QString getUserName();
    QString getAccessLevel(QString process_name);

    QStringList getProcessesList();
    QStringList getProcessesAccess();

    void operator=(acl_base *other);
    void operator=(acl_base other);

private:
    QString username;
    QStringList processes;
    QStringList process_access;

signals:
    void userNameChanged();
    void processListChanged();
    void processAccessChanged();
    void finished();

public slots:

};

#endif // ACL_BASE_H
