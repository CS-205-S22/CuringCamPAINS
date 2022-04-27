#include "dashboardgui.h"
#include "ui_dashboardgui.h"

DashboardGui::DashboardGui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DashboardGui)
{
    ui->setupUi(this);

    ui->stackedWidget_main->addWidget(contactsGui);
    ui->stackedWidget_main->addWidget(resourcesGui);
    ui->stackedWidget_main->addWidget(logGui);
}

DashboardGui::~DashboardGui()
{
    delete ui;
}

void DashboardGui::on_pushButton_dashboard_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(0);
    this->displayButtons();
}

void DashboardGui::displayButtons() {
    //add buttons here
    vector<string> contacts;
    for (int i = 0; i < (int)contactsGui->contactList->treatmentGroup->size(); i++) {
        contacts.push_back(contactsGui->contactList->treatmentGroup->at(i)->firstName);
    }
    DynamicButton *button;
    for (int i = 0; i < (int)contacts.size(); i++) {
        button = new DynamicButton(this);  // Create a dynamic button object
        /* Set the text with name of contact
           * */
        button->setText(QString::fromStdString(contacts.at(i)));
        /* Adding a button to the bed with a vertical layout
           * */
        ui->verticalLayout->addWidget(button);
        /* Connect the signal to the slot pressing buttons produce numbers
           * */
        connect(button, SIGNAL(clicked()), this, SLOT(openLogForm()));
    }
}

/* SLOT for getting number of buttons.
 * */
void DashboardGui::openLogForm()
{
    /* To determine the object that caused the signal
     * */
    DynamicButton *button = (DynamicButton*) sender();

    //open log form

    int pos = button->ResID - 1;
    Contact* save = contactsGui->contactList->treatmentGroup->at(pos);
    contactsGui->contactList->treatmentGroup->erase(contactsGui->contactList->treatmentGroup->begin() + pos);
    contactsGui->contactList->treatmentGroup->push_back(save);
}

void DashboardGui::on_pushButton_contacts_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(1);
}

void DashboardGui::on_pushButton_resources_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(2);
}

void DashboardGui::on_pushButton_data_clicked()
{
    Csv *c=new Csv();
    c->download("../../../../../database.sqlite","logForm","../../../../../data_downloaded.csv");
    QMessageBox::warning(this,"Download", "The csv file is downloaded in main file");
    ui->stackedWidget_main->setCurrentIndex(0);
}

void DashboardGui::on_pushButton_logout_clicked()
{
    this->close();
}

void DashboardGui::on_pushButton_log_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(3);
    logGui->autofill();
}

