#include "dashboard.h"
#include "ui_dashboard.h"
#include "../Controller/savedmessages.h"
#include "../Controller/log.h"
//#include "contacts.h"

using namespace std;

ContactList cList("../../database.sqlite");

SavedMessages sm("../../../../../database.sqlite");
LogForm logForm("../../../../../database.sqlite");



Dashboard::Dashboard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Dashboard)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

Dashboard::~Dashboard()
{
    delete ui;
}



//This goes to the log form for the test contact
void Dashboard::on_pushButton_5_clicked()
{
 ui->stackedWidget->setCurrentIndex(5);
}



void Dashboard::on_resourcesButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Dashboard::on_contactsButton_clicked()
{
    cList.readFile("../../../contacts.csv");

    //    Contacts contacts;
    //    contacts.setModal(true);
    //    contacts.exec();
}


void Dashboard::on_changeColor_clicked()
{
    QColorDialog dialog;
    QColor color = dialog.getColor();
    QString colName = color.name();


    int r, g, b;
    char const *hexColor = colName.toUtf8().data();
    std::sscanf(hexColor, "#%02x%02x%02x", &r, &g, &b);
    string feed = "background-color: rgb(";
    feed += to_string(r) += ", ";
    feed += to_string(g) += ", ";
    feed += to_string(b) += ", ";
    feed += to_string(25) += ")";
    QString style = QString::fromUtf8(feed.c_str());
    setStyleSheet(style);

}


void Dashboard::on_createMessage_clicked()
{
    //will now prompt user to enter title and text of desired message
    ui->stackedWidget->setCurrentIndex(2);
}

/**
 * @brief The saveMessage button is on the create message page. After clicking save message, the input title and text is saved to the
 * global strings.
 */
void Dashboard::on_saveMessage_clicked()
{
    this->title = ui->inputTitle->text().toStdString();
    this->text = ui->inputText->text().toStdString();
    //call saved messages create message
    sm.createMessage(this->title, this->text);
    ui->inputTitle->clear();
    ui->inputText->clear();
    ui->stackedWidget->setCurrentIndex(1);
}

/**
 * @brief Upon pressing the dashboard button, the user is brought back to the main dashboard page.
 */
void Dashboard::on_dashboardButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

/**
 * @brief One viewMessage button on the resources page, the user is brought to the view message page which asks for an input title.
 */
void Dashboard::on_viewMessage_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

/**
 * @brief The viewButton is on the view message page. Once the view button is pressed, the title is updated to be the input string
 * on the label. The function creates a vector that is set equal to the SavedMessages viewMessage function that takes the
 * updated title. If the vector is empty, the function outputs an error message informing the user of the mistake. Otherwise,
 * the function creates a QString and loops through the vector. At each iteration, the QString gets the index messsage appended
 * to the string. After the loop breaks, the QString is displayed on a label on the page. Lastly, the input is cleared.
 */
void Dashboard::on_viewButton_clicked()
{
    this->title = ui->inputTitle_2->text().toStdString();
    vector<string> toView = sm.viewMessage(this->title);
    if (toView.empty()) {
        ui->displayText->setText("No messages with input title.");
    } else {
        QString insert;
        for (int i = 0; i < (int)toView.size(); i++) {
            insert += QString::fromUtf8(toView.at(i).c_str()) + " ";
        }
        ui->displayText->setText(insert);
    }
    ui->inputTitle_2->clear();
}

/**
 * @brief The deleteButton is on the delete message page. Once the title is inserted by the user, the title variable is updated
 * to be the input string on the label. The SavedMessages deleteMessage function is called on the new title. The function then
 * clears the label and returns the user back to the resources page.
 */
void Dashboard::on_deleteButton_clicked()
{
    this->title = ui->inputTitle_3->text().toStdString();
    sm.deleteMessage(this->title);
    ui->inputTitle_3->clear();
    ui->stackedWidget->setCurrentIndex(1);
}

/**
 * @brief Upon pressing the delete message button on the resources page, the page will be set to the fourth page which is where
 * the user inputs the title of the message wanting to be deleted.
 */
void Dashboard::on_deleteMessage_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}



void Dashboard::on_nameButton_clicked()
{
    logForm.name = ui->nameLineEdit->text().toStdString();
    logForm.age = ui->ageLineEdit->text().toStdString();
    logForm.phoneNumber = ui->pnLineEdit->text().toStdString();
    logForm.numOfAttempts = ui->numAttemptsLineEdit->text().toStdString();
    logForm.methodOfContact = ui->methodOfContactLineEdit->text().toStdString();
    logForm.reaction = ui->reactionLineEdit->text().toStdString();
    logForm.date = ui->dateContactedLineEdit->text().toStdString();
    logForm.committed = ui->isCommittedLineEdit->text().toStdString();

    /*logForm.logInput[0] = ui->nameLineEdit->text().toStdString();
    logForm.logInput[1] = ui->ageLineEdit->text().toStdString();
    logForm.logInput[2] = ui->pnLineEdit->text().toStdString();
    logForm.logInput[3] = ui->numAttemptsLineEdit->text().toStdString();
    logForm.logInput[4] = ui->methodOfContactLineEdit->text().toStdString();
    logForm.logInput[5] = ui->reactionLineEdit->text().toStdString();
    logForm.logInput[6] = ui->dateContactedLineEdit->text().toStdString();
    logForm.logInput[7] = ui->isCommittedLineEdit->text().toStdString();*/

    //logForm.saveLogForm(logForm.logInput[0],logForm.logInput[1],logForm.logInput[2],
            //logForm.logInput[3],logForm.logInput[4],logForm.logInput[5],
            //logForm.logInput[6],logForm.logInput[7]);
    logForm.saveLogForm(logForm.name, logForm.age, logForm.phoneNumber, logForm.numOfAttempts,
                        logForm.methodOfContact, logForm.reaction, logForm.date, logForm.committed);
    //logForm.saveLogForm("John Cena", "19", "1111112", "3", "text", "unsure", "April 7th, 2022", "false");
    //logForm.deleteLog("3333333");
    //logForm.deleteLog("4444444");
    //logForm.deleteLog("111");
}

/**
 * @brief On pressing the back button on page 3, the view message page, the program clears the label and resets the view to the
 * resources page.
 */
void Dashboard::on_backButton_clicked()
{
    ui->displayText->clear();
    ui->stackedWidget->setCurrentIndex(1);
}

