#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QObject>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    data_base = new acl_base[65535];                                        //array of acl class objects
    counter = 0;

    /*********************************** User Interface Constructing ***************************************/

    timer_login = new QTimer();
    acl_groupBox = new QGroupBox("ACL interface");
    add_pos_groupBox = new QGroupBox("Add user");
    change_pos_groupBox = new QGroupBox("Edit entry");
    read_pos_groupBox = new QGroupBox("User information");

    add_user_pushButton = new QPushButton("Add");
    edit_user_pushButton = new QPushButton("Edit");;
    show_user_pushButton = new QPushButton("Show");

    add_user_name_label = new QLabel("Write username");

    edit_user_combo_label = new QLabel("Choose user");
    edit_process_combo_label = new QLabel("Choose process");
    edit_type_combo_label = new QLabel("Choose operation");
    edit_access_level_combo_label = new QLabel("Choose access level");

    show_user_combo_label = new QLabel("Choose user");
    show_process_combo_label = new QLabel("Choose process");
    show_access_level_combo_label = new QLabel("_______________");

    add_user_name_lineEdit = new QLineEdit();
    add_process_name_lineEdit = new QLineEdit();
    add_access_level_lineEdit = new QLineEdit();
    edit_user_comboBox = new QComboBox();
    edit_type_comboBox = new QComboBox();
    edit_process_comboBox = new QComboBox();
    edit_access_level_comboBox = new QComboBox();
    show_user_combo_comboBox = new QComboBox();
    show_process_combo_comboBox = new QComboBox();

    /*********************************** Lists init ***************************************/

    registered_users_list = new QStringList();
    deleted_users_list = new QStringList();
    registered_process_list = new QStringList();

    registered_users_list->append("Andrey");                    // Creating entries "by-default" for example purposes
    registered_users_list->append("Vasily");
    registered_users_list->append("Maxim");
    counter = 3;

    registered_process_list->append("Antivirus software");
    registered_process_list->append("Version control system");
    registered_process_list->append("Office software");
    registered_process_list->append("Developer software");
    registered_process_list->append("System utilities");

    access_level_list = new QStringList({"Read", "Write", "Read/Write", "Forbidden"});
    edit_access_level_comboBox->addItems(*access_level_list);
    edit_type_list = new QStringList({"Edit", "Delete"});
    edit_type_comboBox->addItems(*edit_type_list);
    edit_user_comboBox->addItems(*registered_users_list);
    edit_process_comboBox->addItems(*registered_process_list);
    show_user_combo_comboBox->addItems(*registered_users_list);
    show_process_combo_comboBox->addItems(*registered_process_list);

    for (int i = 0; i < counter; i++) {
        data_base[i].setUserName(registered_users_list->at(i));                                         //Default Users registering
        data_base[i].addProcessList(*registered_process_list);                                          //Default available processes registering
        for (int l = 0; l < registered_process_list->size(); l++) {                                     //Access level registering for each process
            data_base[i].manage_process(registered_process_list->at(l), access_level_list->at(i));
        }
    }

    connect(timer_login, SIGNAL(timeout()), this, SLOT(login_timeout()));                               //For wrong sign in pushbutton label timeout
    connect(add_user_pushButton, SIGNAL(clicked()), this, SLOT(add_user_toDataBase()));                 //Add user push button
    connect(edit_type_comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(edit_type_clicked()));     //Edit or delete slot
    connect(edit_user_pushButton, SIGNAL(clicked()), this, SLOT(edit_dataBase_entry()));
    connect(show_user_pushButton, SIGNAL(clicked()), this, SLOT(show_access_level()));                  //Show access level
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_singIn_pushButton_clicked()
{
    QString login(ui->login_lineEdit->text());
    QString password(ui->pass_lineEdit->text());

    if((login == "admin") && (password == "admin"))                                     //If login/password pair is correct - proceed with constructing user interface
    {

        QVBoxLayout *add_layout = new QVBoxLayout;
        add_layout->addWidget(add_user_name_label);
        add_layout->addWidget(add_user_name_lineEdit);
        add_layout->addWidget(add_user_pushButton);
        add_pos_groupBox->setLayout(add_layout);
        add_pos_groupBox->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

        QVBoxLayout *edit_layout = new QVBoxLayout;
        edit_layout->addWidget(edit_user_combo_label);
        edit_layout->addWidget(edit_user_comboBox);
        edit_layout->addWidget(edit_type_combo_label);
        edit_layout->addWidget(edit_type_comboBox);
        edit_layout->addWidget(edit_process_combo_label);
        edit_layout->addWidget(edit_process_comboBox);
        edit_layout->addWidget(edit_access_level_combo_label);
        edit_layout->addWidget(edit_access_level_comboBox);
        edit_layout->addWidget(edit_user_pushButton);
        change_pos_groupBox->setLayout(edit_layout);
        change_pos_groupBox->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

        QVBoxLayout *read_layout = new QVBoxLayout;
        read_layout->addWidget(show_user_combo_label);
        read_layout->addWidget(show_user_combo_comboBox);
        read_layout->addWidget(show_process_combo_label);
        read_layout->addWidget(show_process_combo_comboBox);
        read_layout->addWidget(show_access_level_combo_label);
        read_layout->addWidget(show_user_pushButton);
        read_pos_groupBox->setLayout(read_layout);
        read_pos_groupBox->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

        QHBoxLayout *local_main_layout = new QHBoxLayout;
        local_main_layout->addWidget(add_pos_groupBox);
        local_main_layout->addWidget(change_pos_groupBox);
        local_main_layout->addWidget(read_pos_groupBox);

        acl_groupBox->setLayout(local_main_layout);

        QHBoxLayout *main_layout = new QHBoxLayout;
        main_layout->addWidget(acl_groupBox);

        ui->login_label->~QLabel();
        ui->login_lineEdit->~QLineEdit();
        ui->pass_label->~QLabel();
        ui->pass_lineEdit->~QLineEdit();
        ui->singIn_pushButton->~QPushButton();

        ui->centralwidget->setLayout(main_layout);

    }
    else
    {
        ui->singIn_pushButton->setText("Wrong pair");                   //service message if pair is incorrect
        timer_login->start(1000);
    }
}

void MainWindow::add_user_toDataBase()
{
    acl_base *temp_base = new acl_base();

    temp_base->setUserName(add_user_name_lineEdit->text());                                 //add new user name to a new array element
    temp_base->addProcessList(*registered_process_list);                                    //register avalaible process list for a new user
    registered_users_list->append(add_user_name_lineEdit->text());
    for (int l = 0; l < registered_process_list->size(); l++) {                                     //Access level registering for each process
        temp_base->manage_process(registered_process_list->at(l), access_level_list->at(3));
    }
    edit_user_comboBox->addItem(add_user_name_lineEdit->text());                                    //Add new entries to comboboxes to make them accessible
    show_user_combo_comboBox->addItem(add_user_name_lineEdit->text());

    data_base[counter] = temp_base;

    //qDebug() << counter;

    counter++;
}

void MainWindow::edit_type_clicked()
{
    if(edit_type_comboBox->currentText() == "Delete")                                   //if delete operation is chosen - other options bceome hidden
    {
        edit_access_level_comboBox->setDisabled(true);
        edit_process_comboBox->setDisabled(true);
    }
    else if(edit_type_comboBox->currentText() == "Edit")
    {
        edit_access_level_comboBox->setEnabled(true);
        edit_process_comboBox->setEnabled(true);
    }
}

void MainWindow::edit_dataBase_entry()
{
    if(edit_type_comboBox->currentText() == "Edit")                                     //access levels of chosen user and process is edited
    {
        data_base[registered_users_list->indexOf(edit_user_comboBox->currentText())].manage_process(edit_process_comboBox->currentText(), edit_access_level_comboBox->currentText());
    }
    else if(edit_type_comboBox->currentText() == "Delete")                              //chosen user is deleted from lists, arrays and comboboxes, the name is logged in a delete list
    {
        int index = 0;
        acl_base *temp = new acl_base();
        index = registered_users_list->indexOf(edit_user_comboBox->currentText());
        registered_users_list->removeAt(index);
        deleted_users_list->append(edit_user_comboBox->currentText());
        edit_user_comboBox->removeItem(index);
        show_user_combo_comboBox->removeItem(index);

        for (int i = index; i < (counter); i++) {
            temp = &(data_base[i + 1]);
            data_base[i] = temp;
        }
        counter--;
    }
}

void MainWindow::show_access_level()
{
    //show_access_level_combo_label->setText(data_base[show_user_combo_comboBox->currentIndex()].getAccessLevel(show_process_combo_comboBox->currentText()));

    show_access_level_combo_label->setText(data_base[registered_users_list->indexOf(show_user_combo_comboBox->currentText())].getAccessLevel(show_process_combo_comboBox->currentText()));
}

void MainWindow::login_timeout()
{
    ui->singIn_pushButton->setText("Sing in");      //For wrong sing in pushbutton label timeout
}
