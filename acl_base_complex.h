#ifndef ACL_BASE_COMPLEX_H
#define ACL_BASE_COMPLEX_H

#include <QObject>
#include <acl_base.h>
#include <QDebug>

class acl_base_complex : public acl_base
{
    Q_OBJECT
public:
    explicit acl_base_complex(QObject *parent = nullptr);
    explicit acl_base_complex(uint32_t len);
    explicit acl_base_complex(acl_base_complex *complex);
    explicit acl_base_complex(acl_base_complex &complex);
    ~acl_base_complex();

    acl_base *data_base;

signals:

public slots:
    void run();

private:
    uint32_t database_size;


};

#endif // ACL_BASE_COMPLEX_H
