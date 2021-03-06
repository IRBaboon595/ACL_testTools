QT       += core gui
QT       += testlib


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    acl_base.cpp \
    acl_base_complex.cpp \
    main.cpp \
    mainwindow.cpp \
    test_acl_base.cpp \
    test_acl_gui.cpp

HEADERS += \
    acl_base.h \
    acl_base_complex.h \
    mainwindow.h \
    test_acl_base.h \
    test_acl_gui.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
