#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTimer>
#include <QLineEdit>
#include <QLabel>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QBoxLayout>
#include <QString>
#include <QStringList>
#include <QComboBox>
#include <QSizePolicy>
#include "acl_base.h"
#include "acl_base_complex.h"
#include <QDebug>
#include <QList>
#include <QtTest>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_singIn_pushButton_clicked();
    void login_timeout();
    void add_user_toDataBase();
    void edit_type_clicked();
    void edit_dataBase_entry();
    void show_access_level();

private:

    Ui::MainWindow          *ui;
    //************************************ For Sign in process ************************************/

    QTimer                  *timer_login;

    //************************************ Objects for MainWindow interface ************************************/

    QGroupBox               *acl_groupBox;                    //Main GroupBox
    QGroupBox               *add_pos_groupBox;                //Add user GroupBox
    QGroupBox               *change_pos_groupBox;             //Edit user GroupBox
    QGroupBox               *read_pos_groupBox;               //Show user GroupBox

    QPushButton             *add_user_pushButton;
    QPushButton             *edit_user_pushButton;
    QPushButton             *show_user_pushButton;

    QLabel                  *add_user_name_label;
    QLabel                  *add_process_name_label;
    QLabel                  *add_access_level_label;
    QLabel                  *edit_user_combo_label;
    QLabel                  *edit_type_combo_label;
    QLabel                  *edit_process_combo_label;
    QLabel                  *edit_access_level_combo_label;
    QLabel                  *show_user_combo_label;
    QLabel                  *show_process_combo_label;
    QLabel                  *show_access_level_combo_label;

    QLineEdit               *add_user_name_lineEdit;
    QLineEdit               *add_process_name_lineEdit;
    QLineEdit               *add_access_level_lineEdit;
    QComboBox               *edit_user_comboBox;
    QComboBox               *edit_type_comboBox;
    QComboBox               *edit_process_comboBox;
    QComboBox               *edit_access_level_comboBox;
    QComboBox               *show_user_combo_comboBox;
    QComboBox               *show_process_combo_comboBox;

    QStringList             *access_level_list;
    QStringList             *edit_type_list;
    QStringList             *registered_users_list;
    QStringList             *deleted_users_list;
    QStringList             *registered_process_list;

    acl_base                *data_base;
    std::vector<acl_base>   data_vector;
    uint16_t                counter;

    typedef enum{
        READ = 0,
        WRITE,
        READ_WRITE,
        BLANK
    }access_level;

    QThread                 thread;
    acl_base_complex        *complex_base;


};
#endif // MAINWINDOW_H
