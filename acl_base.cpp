#include "acl_base.h"

acl_base::acl_base(QObject *parent) : QObject(parent)
{

}

acl_base::acl_base(acl_base &base_temp)
{
    username = base_temp.getUserName();
    processes = base_temp.getProcessesList();
    process_access = base_temp.getProcessesAccess();
}

acl_base::acl_base(acl_base *base_temp)
{
    username = base_temp->getUserName();
    processes = base_temp->getProcessesList();
    process_access = base_temp->getProcessesAccess();
}

acl_base::acl_base(QString name)
{
    username = name;
}

acl_base::acl_base(QString name, QString process_name, QString access_level)
{
    username = name;
    processes.append(process_name);
    process_access.append(access_level);
}

void acl_base::setUserName(QString name)
{
    username = name;
}

QString acl_base::getUserName()
{
    return username;
}

void acl_base::addProcessList(QStringList process_list)
{
    processes = process_list;
}

void acl_base::manage_process(QString process_name, QString access_level)
{
    int index = 0;
    index = processes.indexOf(process_name);
    process_access.insert(index, access_level);
}

QString acl_base::getAccessLevel(QString process_name)
{
    int index = 0;
    index = processes.indexOf(process_name);
    return process_access.at(index);
}

QStringList acl_base::getProcessesList()
{
    return processes;
}

QStringList acl_base::getProcessesAccess()
{
    return process_access;
}

void acl_base::operator=(acl_base *other)
{
    this->username = other->getUserName();
    this->processes = other->getProcessesList();
    this->process_access = other->getProcessesAccess();
}

void acl_base::operator=(acl_base other)
{
    this->username = other.getUserName();
    this->processes = other.getProcessesList();
    this->process_access = other.getProcessesAccess();
}

acl_base::~acl_base()
{
    this->username = "";
}
