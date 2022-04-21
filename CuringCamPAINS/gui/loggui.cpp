#include "loggui.h"
#include "ui_loggui.h"

LogForm logForm("../../../../../database.sqlite");

LogGui::LogGui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogGui)
{
    ui->setupUi(this);
    ui->stackedWidget_log->setCurrentIndex(0);
}

LogGui::~LogGui()
{
    delete ui;
}

void LogGui::on_pushButton_enter_clicked()
{
    logForm.name = ui->lineEdit_name->text().toStdString();
    logForm.age = ui->lineEdit_age->text().toStdString();
    logForm.phoneNumber = ui->lineEdit_phoneNumber->text().toStdString();
    logForm.numOfAttempts = ui->lineEdit_numOfAttempts->text().toStdString();
    logForm.methodOfContact = ui->lineEdit_methodOfContact->text().toStdString();
    logForm.reaction = ui->lineEdit_reaction->text().toStdString();
    logForm.date = ui->lineEdit_date->text().toStdString();
    logForm.committed = ui->lineEdit_committed->text().toStdString();

    /*logForm.logInput[0] = ui->lineEdit_name->text().toStdString();
    logForm.logInput[1] = ui->lineEdit_age->text().toStdString();
    logForm.logInput[2] = ui->lineEdit_phoneNumber->text().toStdString();
    logForm.logInput[3] = ui->lineEdit_numOfAttempts->text().toStdString();
    logForm.logInput[4] = ui->lineEdit_methodOfContact->text().toStdString();
    logForm.logInput[5] = ui->lineEdit_reaction->text().toStdString();
    logForm.logInput[6] = ui->lineEdit_date->text().toStdString();
    logForm.logInput[7] = ui->lineEdit_committed->text().toStdString();*/

    //logForm.saveLogForm(logForm.logInput[0],logForm.logInput[1],logForm.logInput[2],
            //logForm.logInput[3],logForm.logInput[4],logForm.logInput[5],
            //logForm.logInput[6],logForm.logInput[7]);
    logForm.saveLogForm(logForm.name, logForm.age, logForm.phoneNumber, logForm.numOfAttempts,
                       logForm.methodOfContact, logForm.reaction, logForm.date, logForm.committed);
    //logForm.saveLogForm("John Cena", "19", "1111112", "3", "text", "unsure", "April 7th, 2022", "false");
    //logForm.deleteLog("111");
}

