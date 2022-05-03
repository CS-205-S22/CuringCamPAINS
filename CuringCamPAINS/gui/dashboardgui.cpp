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

    vLayout = new QVBoxLayout();
    ui->scrollAreaWidgetContents_dashboard->setLayout(vLayout);
    ui->scrollArea_dashboard->setWidgetResizable(true);


    QPixmap pix1(QString::fromStdString("../../../../../letter_logo.png"));
    int w1=ui->label_title->width();
    int h1=ui->label_title->height();
    ui->label_title->setPixmap(pix1.scaled(w1,h1,Qt::KeepAspectRatio));

    //    QPixmap pix("../../../../../user.png");
    //    int w = ui->label_image->width();
    //    int h = ui->label_image->height();
    //    ui->label_image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

    layout = new QVBoxLayout(this);
    //    ui->scrollArea_dashboard->setLayout(layout);

    Database *dbb = new Database("../../../../../database.sqlite");
    string name = dbb->getter("user", "name", "userId", std::to_string(cur_usrId));
    ui->label_name->setText(QString::fromStdString(name));
    string outFile="../../../../../"+name+".jpeg";

    QPixmap pix(QString::fromStdString(outFile));
    int w=ui->label_image->width();
    int h=ui->label_image->height();
    ui->label_image->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


    ui->stackedWidget_main->addWidget(contactsGui);
    ui->stackedWidget_main->addWidget(resourcesGui);
    ui->stackedWidget_main->addWidget(logGui);
    cerr << "BEFORE DISPLAY" << endl;
    this->displayButtons();

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
    //cerr << "NUM CONTACTS BEFORE: " << numContacts << endl;
    if (numContacts != (int)contactsGui->contactList->treatmentGroup->size()) {
        this->displayButtons();
        numContacts = (int)contactsGui->contactList->treatmentGroup->size();
        //cerr << "NUM CONTACTS IN IF STATMENT: " << numContacts << endl;
    }
    //cerr << "NUM CONTACTS OUTSIDE IF STATMENT: " << numContacts << endl;
    //cerr << "SIZE OF TREATMENT GROUP: " << (int)contactsGui->contactList->treatmentGroup->size() << endl;
}

/**
 * @brief The display buttons function first checks if there are already buttons on the screen. If there are, all are deleted. This
 * is to ensure repeat buttons are not displayed. Afterwards, the contacts vector is built from the name of each of the contacts in
 * the treatment group. A dynamic button object is then created, and the button Ids are reset to 0. The loop goes through the entire
 * vector of names and at each iteration creates a button, sets the name as the text of the button, adds the button to the layout
 * and .... The slot is created for each button and after the loop finishes the contact vector is cleared for the next use.
 */
void DashboardGui::displayButtons() {
    if (vLayout->count() != 0) {
        deleteButtons();
    }

    vector<Contact*> *contacts = new vector<Contact*>;
    for (int i = 0; i < (int) contactsGui->contactList->treatmentGroup->size(); i++) {
        contacts->push_back(contactsGui->contactList->treatmentGroup->at(i));
    }

    DynamicButton *button;
    DynamicButton::setID();

    for (int i = 0; i < (int)contacts->size(); i++) {
        QLabel *name;
        QLabel *email;
        QLabel *phone;

        name = new QLabel();
        email = new QLabel();
        phone   = new QLabel();
        hLayout  = new QHBoxLayout();

        button = new DynamicButton(this);  // Create a dynamic button object

        name->setText(QString::fromStdString(contacts->at(i)->firstName + " " + contacts->at(i)->lastName));
        email->setText(QString::fromStdString(contacts->at(i)->emailAddress));
        phone->setText(QString::fromStdString(contacts->at(i)->cellNum));
        button->setText(QString::fromStdString("Log"));

        hLayout->addWidget(name);
        hLayout->setAlignment(name, Qt::AlignLeft);
        hLayout->addWidget(email);
        hLayout->setAlignment(email, Qt::AlignLeft);
        hLayout->addWidget(phone);
        hLayout->setAlignment(phone, Qt::AlignRight);
        hLayout->addWidget(button);
        hLayout->setAlignment(button, Qt::AlignRight);

        vLayout->setAlignment(Qt::AlignTop);
        vLayout->addLayout(hLayout);

        con = contactsGui->contactList->treatmentGroup->at(i);
        cerr << con->firstName << endl;
        button->name = con->cellNum;
        buttonList.push_back(button->name);
        dynButtonList.push_back(button);
        connect(button, SIGNAL(clicked()), this, SLOT(openLogForm()));

        count++;
    }

    contacts->clear();
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
    //To determine the object that caused the signal

    DynamicButton *button = (DynamicButton*) sender();
    Contact* treatmentContact = contactsGui->contactList->findContact(button->name);

    //open log form
    ui->stackedWidget_main->setCurrentIndex(3);
    string fullName = treatmentContact->firstName + " " + treatmentContact->lastName;
    logGui->autofill(fullName, to_string(treatmentContact->age), treatmentContact->cellNum);
    int pos = button->resID - 1;
    Contact* save = contactsGui->contactList->treatmentGroup->at(pos);
    contactsGui->contactList->treatmentGroup->erase(contactsGui->contactList->treatmentGroup->begin() + pos);
    contactsGui->contactList->treatmentGroup->push_back(save);


    //now shuffle buttons
    this->deleteButtons();
    this->displayButtons();
}

/**
 * @brief Function deletes items in the vLayout, sublayouts at these items, items in the sublayouts, and widgets in these items.
 */
void DashboardGui::deleteButtons() {
    if ( vLayout != NULL )
    {
        QLayoutItem* item;
        QLayout *sublayout;
        QWidget *widget;
        while (item = vLayout->takeAt(0))
        {
            if ((sublayout = item->layout()) != 0) {
                QLayoutItem *subItem;
                while (subItem = sublayout->takeAt(0))
                {
                    if ((widget = subItem->widget()) != 0) {
                        widget->hide();
                        delete widget;
                    } else {
                        delete subItem;
                    }
                }
            } else {
                delete item;
            }
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
 * @brief Function brings the user back to the log in page once they decide to logout. This allows an easy change of user log in, if
 * desired.
 */
void DashboardGui::on_pushButton_logout_clicked()
{
    LoginGUI *t= new LoginGUI();
    hide();
    t->show();
}

/**
 * @brief Function calls the change color function from the resources gui.
 */
void DashboardGui::changeColor()
{
    setStyleSheet(resourcesGui->getSyle());
}

/**
 * @brief Function increments the number of contacts by one.
 */
void DashboardGui::increaseNumContacts()
{
    numContacts++;
}

