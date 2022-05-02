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
    resourcesGui = new ResourcesGui(cur_usrId);


    Database *dbb=new Database("../../../../../database.sqlite");
    string name=dbb->getter("user","name","userId",std::to_string(cur_usrId));
     ui->label_name->setText(QString::fromStdString(name));
     string outFile="../../../../../"+name+".jpeg";
     cout<<outFile<<endl;
     QPixmap pix(QString::fromStdString(outFile));
     int w=ui->label_image->width();
     int h=ui->label_image->height();
     ui->label_image->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


    ui->stackedWidget_main->addWidget(contactsGui);
    ui->stackedWidget_main->addWidget(resourcesGui);
    ui->stackedWidget_main->addWidget(logGui);

    connect(resourcesGui, SIGNAL(changeColorSignal()), this, SLOT(changeColor()));
}

DashboardGui::~DashboardGui()
{
    delete ui;
}

/**
 * @brief On the dashboard button being clicked, the main stacked widget will be displayed. Additionally, the function checks
 * to see if there were changes made to the contact list (from manual entering), if there was, the function makes sure to display the
 * new buttons and corrects the number of contacts variable.
 */
void DashboardGui::on_pushButton_dashboard_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(0);
    if (numContacts != (int)contactsGui->contactList->treatmentGroup->size()) {
        this->displayButtons();
        numContacts = (int)contactsGui->contactList->treatmentGroup->size();
    }
}

/**
 * @brief The display buttons function first checks if there are already buttons on the screen. If there are, all are deleted. This
 * is to ensure repeat buttons are not displayed. Afterwards, the contacts vector is built from the name of each of the contacts in
 * the treatment group. A dynamic button object is then created, and the button Ids are reset to 0. The loop goes through the entire
 * vector of names and at each iteration creates a button, sets the name as the text of the button, adds the button to the layout
 * and .... The slot is created for each button and after the loop finishes the contact vector is cleared for the next use.
 */
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

        button->setText(QString::fromStdString(contacts.at(i)));
        /* Adding a button to the bed with a vertical layout
           * */
        ui->verticalLayout->addWidget(button);
        /* Connect the signal to the slot pressing buttons produce numbers
           * */
        //cerr << "BEFORE" << endl;
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

/**
 * @brief This function is the slot for each of the dynamic buttons. The function's main purpose is to open the log form for the user
 * but it also shuffles the contacts so that the user knows who is a priority to reach out to. The function first gets the button
 * that sends the signal. Then, the function opens the log form and autofills the places it can. The treatment group vector
 * is then altered to remove this contact from the list, and add it to the back. This will make sure the shuffling effect is in
 * correct order. Then to shuffle the display, the function deletes all buttons and re-calls the display function with the newly
 * ordered treatment group vector.
 */
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

/**
 * @brief Function deletes all buttons from the dashboard display. Loops through the vertical layout while it is not null. At each
 * iteration it deletes each of the items on the layout at the 0th index.
 */
void DashboardGui::deleteButtons() {
    if ( ui->verticalLayout != NULL )
    {
        QLayoutItem* item;
        while ( ( item = ui->verticalLayout->itemAt(0) ) != NULL )
        {
            delete item->widget();
        }
    }
}

/**
 * @brief Function brings user to the contacts page.
 */
void DashboardGui::on_pushButton_contacts_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(1);
}

/**
 * @brief Function brings user to the resources page
 */
void DashboardGui::on_pushButton_resources_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(2);
}

/**
 * @brief Function downloads the data for the user to export. Function uses the CSV object download function.
 */
void DashboardGui::on_pushButton_data_clicked()
{
    Csv *c=new Csv();
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Download Data"), "/Desktop", tr("Data File (*.csv)"));
    string fname = fileName.toStdString();
    if(fname!=""){
    cerr << "CSV FILE NAME: " << fname << endl;

    c->download("../../../../../database.sqlite", "logForm", fname);
    QMessageBox::warning(this,"Download", "The csv file is downloaded in main file");}
    ui->stackedWidget_main->setCurrentIndex(0);
}

/**
 * @brief Function brings the user back to the log in page once they decide to logout. This allows an easy change of user log in, if
 * desired.
 */
void DashboardGui::on_pushButton_logout_clicked()
{
    LoginGUI *l= new LoginGUI();
    hide();
    l->show();
}

/**
 * @brief Function calls the change color function from the resources gui.
 */
void DashboardGui::changeColor()
{
    setStyleSheet(resourcesGui->getSyle());
}

