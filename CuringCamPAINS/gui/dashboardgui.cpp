#include "dashboardgui.h"
#include "ui_dashboardgui.h"
#include <QPixmap>
#include "logingui.h"

DashboardGui::DashboardGui(int cur_usrId, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DashboardGui)
{
    ui->setupUi(this);
    contactsGui = new ContactsGui(cur_usrId);
    logGui = new LogGui(cur_usrId);

    QPixmap pix("../../../../../user.png");
    int w=ui->label_image->width();
    int h=ui->label_image->height();
    ui->label_image->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    //    ui->label_image->setText("Tafita");
    resourcesGui = new ResourcesGui(cur_usrId);
    ui->stackedWidget_main->addWidget(contactsGui);
    ui->stackedWidget_main->addWidget(resourcesGui);
    ui->stackedWidget_main->addWidget(logGui);

    connect(resourcesGui, SIGNAL(changeColorSignal()), this, SLOT(changeColor()));
}

DashboardGui::~DashboardGui()
{
    delete ui;
}

void DashboardGui::on_pushButton_dashboard_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(0);
    if (numContacts != (int)contactsGui->contactList->treatmentGroup->size()) {
        this->displayButtons();
        numContacts = (int)contactsGui->contactList->treatmentGroup->size();
    }
}

void DashboardGui::displayButtons() {
    if (ui->verticalLayout->count() != 0) {
        deleteButtons();
    }
    vector<string> contacts;
    for (int i = 0; i < (int)contactsGui->contactList->treatmentGroup->size(); i++) {
        contacts.push_back(contactsGui->contactList->treatmentGroup->at(i)->firstName);
    }

    DynamicButton *button;
    DynamicButton::setID();
    for (int i = 0; i < (int)contacts.size(); i++) {
        button = new DynamicButton(this);  // Create a dynamic button object
        /* Set the text with name of contact
           * */

        //if (std::find(buttonList.begin(), buttonList.end(), contacts.at(i)) != buttonList.end()) {
        //continue;
        //} else {

        button->setText(QString::fromStdString(contacts.at(i)));
        /* Adding a button to the bed with a vertical layout
           * */
        ui->verticalLayout->addWidget(button);
        /* Connect the signal to the slot pressing buttons produce numbers
           * */
        cerr << "BEFORE" << endl;
        con = contactsGui->contactList->treatmentGroup->at(i);
        cerr << con->firstName << endl;
        button->name = con->firstName;
        buttonList.push_back(button->name);
        dynButtonList.push_back(button);
        connect(button, SIGNAL(clicked()), this, SLOT(openLogForm()));


        count++;
    }
    contacts.clear();
}

/* SLOT for buttons.
 * */
void DashboardGui::openLogForm()
{
    /* To determine the object that caused the signal
     * */

    DynamicButton *button = (DynamicButton*) sender();
    cerr << "AFTER CLICKED: " << con->firstName << endl;
    Contact* treatmentContact = contactsGui->contactList->findByFirstName(button->name);
    //open log form
    cerr << "BEFORE CHANGE SCREEN" << endl;
    ui->stackedWidget_main->setCurrentIndex(3);
    cerr << "AFTER CHANGE SCREEN" << endl;
    logGui->autofill(button->text().toStdString(), to_string(treatmentContact->age), treatmentContact->cellNum);

    cerr << "AFTER AUTOFILL" << endl;
    int pos = button->resID - 1;
    Contact* save = contactsGui->contactList->treatmentGroup->at(pos);
    contactsGui->contactList->treatmentGroup->erase(contactsGui->contactList->treatmentGroup->begin() + pos);
    contactsGui->contactList->treatmentGroup->push_back(save);


    //now shuffle buttons
    this->deleteButtons();
    this->displayButtons();
}


void DashboardGui::deleteButtons() {
    for(int i = 0; i < ui->verticalLayout->count(); i++){
        ui->verticalLayout->itemAt(i)->widget()->hide();
        delete ui->verticalLayout->itemAt(i)->widget();
        /*DynamicButton *button = qobject_cast<DynamicButton*>(ui->verticalLayout->itemAt(i)->widget());
        button->hide();
        delete button;*/
    }
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
    LoginGUI *l= new LoginGUI();
    hide();
    l->show();
    //    this->close();
}


void DashboardGui::on_pushButton_update_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(3);
    //logGui->autofill();
}

void DashboardGui::changeColor()
{
    setStyleSheet(resourcesGui->getSyle());
}

