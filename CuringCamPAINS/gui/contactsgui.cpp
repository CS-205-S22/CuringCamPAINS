#include "contactsgui.h"
#include "ui_contactsgui.h"



ContactsGui::ContactsGui(int usr, QWidget *parent) :
        QWidget(parent),
        ui(new Ui::ContactsGui) {
    cur_usr=usr;
    ui->setupUi(this);
    ui->stackedWidget_contacts->setCurrentIndex(0);
    contactList = new ContactList(cur_usr, "../../../../../database.sqlite");
}

ContactsGui::~ContactsGui() {
    delete ui;
}

void ContactsGui::on_pushButton_uploadFile_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Upload Contacts"), "/Desktop", tr("Contacts Files (*.csv)"));
    string fname = fileName.toStdString();

    cerr << "FILE NAME: " << fname << endl;
    contactList->readFile(fname);
//    contactList->readFile("../../../contacts.csv");

//    QString path = QFileDialog::getExistingDirectory (this, tr("Directory"), directory.path());
//    if ( path.isNull() == false )
//    {
//        directory.setPath(path);
//    }

    QMessageBox::information(this, tr("Successful upload!"), tr("Your file is successfully uploaded"));
}

void ContactsGui::on_pushButton_save_clicked() {
    string firstName = (ui->lineEdit_firstName->text()).toStdString();
    string lastName = (ui->lineEdit_lastName->text()).toStdString();
    string phoneNum = (ui->lineEdit_phone->text()).toStdString();
    string email = (ui->lineEdit_email->text()).toStdString();
    string address = (ui->lineEdit_address->text()).toStdString();
    string age = (ui->lineEdit_age->text()).toStdString();

    if (phoneNum.length() != 10) {
//        ui->label_phoneErrorMessage->setStyleSheet("{color: #FF0000}");
        ui->label_phoneErrorMessage->setText("Invalid phone number!");
    }

    if (stoi(age) < 18) {
        ui->label_ageErrorMessage->setText("The contact has to be above 18!");
        return;
    } else {

        contactList->addContact(firstName, lastName, phoneNum, email, address, age);
        QMessageBox::information(this, tr("Successful entry!"), tr("The contact is saved!"));

        ui->lineEdit_firstName->clear();
        ui->lineEdit_lastName->clear();
        ui->lineEdit_phone->clear();
        ui->lineEdit_email->clear();
        ui->lineEdit_address->clear();
        ui->lineEdit_age->clear();
        ui->label_ageErrorMessage->clear();
        ui->label_phoneErrorMessage->clear();
    }
}

