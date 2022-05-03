#include "contactsgui.h"
#include "ui_contactsgui.h"
#include "dashboardgui.h"

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

/**
 * @brief ContactsGui::on_pushButton_uploadFile_clicked
 * When "Upload File" is clicked, FileDialog shows up and
 * the user chooses the .csv file to upload. The system uploads the chosen file.
 */
void ContactsGui::on_pushButton_uploadFile_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Upload Contacts"),
                                                    "/Desktop", tr("Contacts Files (*.csv)"));
    string fname = fileName.toStdString();

    cerr << "FILE NAME: " << fname << endl;

    if (fname.compare("") != 0) {
        contactList->readFile(fname);
        QMessageBox::information(this, tr("Successful upload!"), tr("Your file is successfully uploaded"));
    }
}


/**
 * @brief ContactsGui::on_pushButton_save_clicked
 * When the user enters contact info manually and clicks on "Save" button,
 * the system checks if the inputs are valid:
 * 1. All sections are required so should be filled out
 * 2. Phone number should be a 10-digit number
 * 3. The contact has to be 18 or older.
 * If the information provided is valid, it creates the contact object and saves it.
 */
void ContactsGui::on_pushButton_save_clicked() {

    string firstName = (ui->lineEdit_firstName->text()).toStdString();
    string lastName = (ui->lineEdit_lastName->text()).toStdString();
    string phoneNum = (ui->lineEdit_phone->text()).toStdString();
    string email = (ui->lineEdit_email->text()).toStdString();
    string address = (ui->lineEdit_address->text()).toStdString();
    string age = (ui->lineEdit_age->text()).toStdString();
    long phoneDigits;

    if  (firstName == "" || lastName == "" || phoneNum == "" || email == "" || address == "" || age == "") {
        QMessageBox::information(this,tr("EMPTY PROMPT(S)"), tr("Please fill in every prompt!"));
        return;
    }

    //Checks the phone number validity
    try {
        phoneDigits = stol(phoneNum);

        if (phoneDigits < 999999999) {
            ui->label_phoneErrorMessage->setText("Invalid phone number!");
            QMessageBox::information(this, tr("INVALID PHONE-NUMBER"), tr("The format for the phone-number is \n XXXXXXXXXX"));
            ui->lineEdit_phone->clear();
        }

    } catch (const std::invalid_argument& ia) {
        ui->label_phoneErrorMessage->setText("Invalid phone number!");
        QMessageBox::information(this, tr("INVALID PHONE-NUMBER"), tr("Please enter 10-digit valid phone number! \n"));
        ui->lineEdit_phone->clear();
    }

    if (stoi(age) < 18) {
        ui->label_ageErrorMessage->setText("The contact has to be above 18!");
        QMessageBox::information(this,tr("INVALID AGE"), tr("This person has to be 18 or older!"));
        ui->lineEdit_age->clear();
        return;
    } else {

        //Successful entry - clears the text boxes
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

