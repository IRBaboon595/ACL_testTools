#include "acl_base_complex.h"

acl_base_complex::acl_base_complex(QObject *parent) : acl_base(parent)
{

}

acl_base_complex::acl_base_complex(uint32_t len)
{
    this->database_size = len;
    data_base = new acl_base[65535];
}

acl_base_complex::acl_base_complex(acl_base_complex *complex)
{
    database_size = complex->database_size;
    for(uint32_t i = 0; i < database_size; i++)
    {
        data_base[i].setUserName(complex->data_base[i].getUserName());
        data_base[i].addProcessList(complex->data_base[i].getProcessesList());
        for(int l = 0; l < (data_base[i].getProcessesList().size()); l++)
        {
            data_base[i].manage_process(data_base[i].getProcessesList().value(l), complex->data_base[i].getAccessLevel(data_base[i].getProcessesList().value(l)));
        }
    }
}


acl_base_complex::acl_base_complex(acl_base_complex &complex)
{
    database_size = complex.database_size;
    for(uint32_t i = 0; i < database_size; i++)
    {
        data_base[i].setUserName(complex.data_base[i].getUserName());
        data_base[i].addProcessList(complex.data_base[i].getProcessesList());
        for(int l = 0; l < (data_base[i].getProcessesList().size()); l++)
        {
            data_base[i].manage_process(data_base[i].getProcessesList().value(l), complex.data_base[i].getAccessLevel(data_base[i].getProcessesList().value(l)));
        }
    }
}



void acl_base_complex::run(){
    qDebug() << "NewThread";

}

acl_base_complex::~acl_base_complex(){

}
