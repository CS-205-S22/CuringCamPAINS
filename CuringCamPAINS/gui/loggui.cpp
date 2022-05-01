#include "loggui.h"
#include "ui_loggui.h"




LogGui::LogGui(int usr,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogGui)
{
    cur_usr=usr;
    ui->setupUi(this);
    ui->stackedWidget_log->setCurrentIndex(0);
    logForm=new LogForm(usr,"../../../../../database.sqlite");
}

LogGui::~LogGui()
{
    delete ui;
}

void LogGui::autofill(string buttonName, string contactAge, string contactPN) {
    QString name = QString::fromStdString(buttonName);
    QString age = QString::fromStdString(contactAge);
    QString phoneNumber = QString::fromStdString(contactPN);
    QString committed = QString("false");
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int mon = 1 + ltm->tm_mon;
    int day = ltm->tm_mday;
    int year = 1900 + ltm->tm_year;

    string day_string = to_string(day);
    string mon_string = to_string(mon);
    string year_string = to_string(year);

    if(day < 10){
        day_string = "0" + day_string;
    }
    if(mon < 10){
        mon_string = "0" + mon_string;
    }


    string date = mon_string + "/" + day_string + "/" + year_string;
    ui->lineEdit_name->setText(name);
    ui->lineEdit_age->setText(age);
    ui->lineEdit_committed->setText(committed);
    ui->lineEdit_phoneNumber->setText(phoneNumber);
    ui->lineEdit_date->setText(QString::fromStdString (date));
}

void LogGui::on_pushButton_enter_clicked()
{
    //logForm.deleteLog("qwertyuiop");

    //CHECKS THAT EVERY BOX WAS FILLED OUT
    if(ui->lineEdit_name->text().toStdString() == "" ||
            ui->lineEdit_age->text().toStdString() == "" ||
            ui->lineEdit_phoneNumber->text().toStdString() == "" ||
            ui->lineEdit_numOfAttempts->text().toStdString() == "" ||
            ui->lineEdit_methodOfContact->text().toStdString() == "" ||
            ui->lineEdit_reaction->text().toStdString() == "" ||
            ui->lineEdit_date->text().toStdString() == "" ||
            ui->lineEdit_committed->text().toStdString() == ""){
        QMessageBox::information(this,tr("EMPTY PROMPT(S)"), tr("Please fill in every prompt!"));
    //CHECKS IF THE PERSON IS AT LEAST 18
    }else if (stoi(ui->lineEdit_age->text().toStdString()) < 18){
        QMessageBox::information(this,tr("INVALID AGE"), tr("This person has to be 18 or older!"));
        //what else can I do because if I type 'a' then that will still be accepted as a name

    //CHECK IF THE PHONE-NUMBER IS VALID :)
    }else if (ui->lineEdit_phoneNumber->text().toStdString().size() != 10){
        QMessageBox::information(this,tr("INVALID PHONE-NUMBER"), tr("The format for the phone-number is \n XXXXXXXXXX"));


    //CHECK IF THE DATE IS CORRECT
    }else if (ui->lineEdit_date->text().toStdString().size() != 10){
        QMessageBox::information(this,tr("INVALID DATE"), tr("The format for the date is \n mm/dd/yyyy"));

    //CHECK IF VALID isCommitted RESPONSE
    }else if(ui->lineEdit_committed->text().toStdString() != "False" &&
             ui->lineEdit_committed->text().toStdString() != "false" &&
             ui->lineEdit_committed->text().toStdString() != "True" &&
             ui->lineEdit_committed->text().toStdString() != "true"){
    QMessageBox::information(this,tr("INVALID INPUT"), tr("Valid Responses for 'committed?': \n 'False' \n 'false' \n 'True' \n 'true'"));

    }else{


    logForm->name = ui->lineEdit_name->text().toStdString();
    logForm->age = ui->lineEdit_age->text().toStdString();
    logForm->phoneNumber = ui->lineEdit_phoneNumber->text().toStdString();
    logForm->numOfAttempts = ui->lineEdit_numOfAttempts->text().toStdString();
    logForm->methodOfContact = ui->lineEdit_methodOfContact->text().toStdString();
    logForm->reaction = ui->lineEdit_reaction->text().toStdString();
    logForm->date = ui->lineEdit_date->text().toStdString();
    logForm->committed = ui->lineEdit_committed->text().toStdString();


    logForm->saveLogForm(logForm->name, logForm->age, logForm->phoneNumber, logForm->numOfAttempts,
                       logForm->methodOfContact, logForm->reaction, logForm->date, logForm->committed);

    /*logForm.logInput[0] = ui->nameLineEdit->text().toStdString();
    logForm.logInput[1] = ui->ageLineEdit->text().toStdString();
    logForm.logInput[2] = ui->pnLineEdit->text().toStdString();
    logForm.logInput[3] = ui->numAttemptsLineEdit->text().toStdString();
    logForm.logInput[4] = ui->methodOfContactLineEdit->text().toStdString();
    logForm.logInput[5] = ui->reactionLineEdit->text().toStdString();
    logForm.logInput[6] = ui->dateContactedLineEdit->text().toStdString();
    logForm.logInput[7] = ui->isCommittedLineEdit->text().toStdString();

    logForm.saveLogForm(logForm.logInput[0],logForm.logInput[1],logForm.logInput[2],
            logForm.logInput[3],logForm.logInput[4],logForm.logInput[5],
            logForm.logInput[6],logForm.logInput[7]);*/

    logForm->saveLogForm(logForm->name, logForm->age, logForm->phoneNumber, logForm->numOfAttempts,
                       logForm->methodOfContact, logForm->reaction, logForm->date, logForm->committed);
    //logForm.saveLogForm("John Cena", "19", "1111112", "3", "text", "unsure", "April 7th, 2022", "false");

    //logForm.deleteLog("111");
    }

    //ui->stackedWidget_main->setCurrentIndex(0);
}
