#include "contactlist.h"
#include <QDir>

const int TREATMENT = 1;
const int CONTROL = 0;
const int NOCONTACT = 2;

/**
 * @brief ContactList::ContactList reads and stores all contacts
 * @param name of the database path.
 */
ContactList::ContactList(string name):Database(name)
{
    masterList = new vector<Contact*>();
    treatmentGroup = new vector<Contact*>();
    controlGroup = new vector<Contact*>();
    noContactGroup = new vector<Contact*>();

    readFromDB();
}

/**
 * @brief ContactList::ContactList
 * @param cur_id - current user ID
 * @param name - database file name
 */
ContactList::ContactList(int cur_id, string name):Database(name)
{
    usr_id=cur_id;
    masterList = new vector<Contact*>();
    treatmentGroup = new vector<Contact*>();
    controlGroup = new vector<Contact*>();
    noContactGroup = new vector<Contact*>();

    readFromDB();
}

/**
 * @brief ContactList::getUserInput
 * Gets the user input when run in TUI
 * M for getting contact information from manual entry
 * F for reading a file to create contact objects.
 */
void ContactList::getUserInput() {
    char ch;
    string filename;

    while(true) {
        cout << "Enter F for uploading file, M for manual entry or X for exit." << endl;
        cin >> ch;

        if (ch == 'F') {
//            cout << "Enter the file name." << endl;
//            cin >> filename;
            filename = "contacts.csv";
            readFile(filename);
        } else if (ch == 'M') {
            getManualEntry();
        } else if (ch == 'X') {
            break;
        } else {
            cout << "Invalid entry!" << endl;
        }
    }
}

/**
 * @brief ContactList::readFile
 * @param name - filename to read
 * Reads the file with the given name; creates a contact object with necessary info;
 * Saves the information in the database and assigns it to one of the 3 groups.
 */
void ContactList::readFile(string name) {
    ifstream file;
    string line;

    string firstName;
    string lastName;
    string cellStr;
    string email;
    string hAdd;
    string ageStr;

    cerr << name << endl;
    cerr << QDir::currentPath().toStdString() << endl;

    file.open(name, fstream::in);

    if (!file.is_open()) {
        cerr << "Error reading file.\n";
        exit(1);
    } else {
        getline(file, line);  //first row

        cerr << "Reading the file." << endl;

        while(getline(file, line)) {
            stringstream strStream(line);
            getline(strStream, firstName, ',');
            getline(strStream, lastName, ',');
            getline(strStream, cellStr, ',');
            getline(strStream, email, ',');
            getline(strStream, hAdd, ',');
            getline(strStream, ageStr, ',');

            if (containsContact(cellStr)) {
                cout << "Contact is already saved!" << endl;
                continue;
            }

            int maxId = getMaxId("contact", "contactId") + 1;
            Contact* c = new Contact(usr_id, maxId, firstName, lastName, cellStr, email, hAdd, stoi(ageStr));
            masterList->push_back(c);

            string id = to_string(c->id);
            string listIdStr = to_string(c->contactListId);
            string inputs[] = {id, listIdStr, to_string(usr_id), firstName, lastName, cellStr, email, hAdd, ageStr};
            write("contact", inputs);

            divideIntoGroups(c);
        }
    }

    file.close();
}
/**
 * @brief ContactList::getManualEntry
 * When run in TUI, reads the information manually entered and
 * adds the contact to the system and database.
 */
void ContactList::getManualEntry() {
    string firstName;
    string lastName;
    string cellStr;
    string email;
    string hAdd;
    string ageStr;

    cout << "First name: ";
    cin >> firstName;
    cout << "Last name: ";
    cin >> lastName;
    cout << "Cell number: ";
    cin >> cellStr;
    cout << "Email address: ";
    cin >> email;
    cout << "Home address: ";
    cin >> hAdd;
    cout << "Age: ";
    cin >> ageStr;

    addContact(firstName, lastName, cellStr, email, hAdd, ageStr);
}

/**
 * @brief ContactList::divideIntoGroups
 * @param c - Contact object to be assigned a group
 * Adds the contact to its corresponding group. If the contactListId is:
 * 0 - Control group
 * 1 - Treatment group
 * 2 - No contact group
 */
void ContactList::divideIntoGroups(Contact* c) {
    if (c->contactListId == TREATMENT) {
        treatmentGroup->push_back(c);
    } else if (c->contactListId == CONTROL) {
        controlGroup->push_back(c);
    } else {
        noContactGroup->push_back(c);
    }
}


/**
 * @brief ContactList::addContact
 * @param fn - first name
 * @param ln - last name
 * @param cellNum - phone number
 * @param email - email address
 * @param hAdd - home address
 * @param age
 * Checks if the same contact is already saved. If not, creates the contact, assigns to a group,
 * and saves to the database.
 */
void ContactList::addContact(string fn, string ln, string cellNum, string email, string hAdd, string age){
    if (containsContact(cellNum)) {
        cout << "Contact is already saved!" << endl;
        return;
    }

    int maxId = getMaxId("contact", "contactId") + 1;
    Contact* c = new Contact(usr_id, maxId, fn, ln, cellNum, email, hAdd, stoi(age));
    masterList->push_back(c);

    string id = to_string(c->id);
    string listIdStr = to_string(c->contactListId);
    string inputs[] = {id, listIdStr, std::to_string(usr_id),fn, ln, cellNum, email, hAdd, age};
    write("contact", inputs);

    divideIntoGroups(c);
}

/**
 * @brief ContactList::addContact
 * @param c - Contact object to be added
 * Checks if the same contact is already saved. If not, creates the contact, assigns to a group,
 * and saves to the database.
 */
void ContactList::addContact(Contact *c) {
    if (containsContact(c->cellNum)){
        cout << "Contact is already saved." << endl;
        return;
    }
    masterList->push_back(c);

    string id = to_string(c->id);
    string listIdStr = to_string(c->contactListId);
    string inputs[] = {id, listIdStr, c->firstName, c->lastName, c->cellNum, c->emailAddress,
                       c->homeAddress, to_string(c->age)};
    write("contact", inputs);

    divideIntoGroups(c);
}

/**
 * @brief ContactList::containsContact
 * @param str - phone number of a contact
 * @return true if the contact is already saved in the database
 * Phone number should be unique to each contact. This method checks i
 * f a contact is already saved in the database using its phone number.
 */
bool ContactList::containsContact(string str) {

    for (unsigned i = 0; i < masterList->size(); i++) {
        if (str.compare(masterList->at(i)->cellNum) == 0) return true;
    }
    return false;
}


/**
 * @brief ContactList::deleteContact
 * @param cellStr - phone number
 * Deletes a contact from the system and database using its phone number
 */
void ContactList::deleteContact(string cellStr) {
    for (unsigned i = 0; i < masterList->size(); i++) {
        if (cellStr.compare(masterList->at(i)->cellNum) == 0) {
            masterList->erase(masterList->begin() + i);
        }
    }

    remove("contact", "phoneNumber", cellStr);
}


/**
 * @brief ContactList::print
 * Prints the contacts in the three groups - used for debugging purposes.
 */
void ContactList::print() {
    cout << "Treatment group: " << endl;
    for (unsigned i = 0; i < treatmentGroup->size(); i++) {
        cout << treatmentGroup->at(i)->firstName << endl;
    }

    cout << "Control group: " << endl;
    for (unsigned i = 0; i < controlGroup->size(); i++) {
        cout << controlGroup->at(i)->firstName << endl;
    }

    cout << "No contact group: " << endl;
    for (unsigned i = 0; i < noContactGroup->size(); i++) {
        cout << noContactGroup->at(i)->firstName << endl;
    }
}


/**
 * @brief ContactList::readFromDB
 * Reads the database and creates the contacts that are associated with the current user.
 * That way, the system is the same as how the user left when they log in again.
 */
void ContactList::readFromDB() {
    QSqlQuery query;
    int id;
    int listId;
    int currUserId;
    string firstName;
    string lastName;
    string cellStr;
    string email;
    string homeAdd;
    int age;
    QString  temp = QString::fromStdString(std::to_string(usr_id));
    QString str = "select * from contact where userId = " + temp + ";";

    if (!query.exec(str)){
        qDebug()<<"error running query\n";
    } else {
        while (query.next()) {
            id = stoi(query.value("contactId").toString().toStdString());
            listId = stoi(query.value("treatmentId").toString().toStdString());
            currUserId = stoi(query.value("userId").toString().toStdString());
            firstName = query.value("firstName").toString().toStdString();
            lastName = query.value("lastName").toString().toStdString();
            cellStr = query.value("phoneNumber").toString().toStdString();
            email = query.value("emailAddress").toString().toStdString();
            homeAdd = query.value("homeAddress").toString().toStdString();
            age = stoi(query.value("age").toString().toStdString());

            if (!containsContact(cellStr)) {
                Contact* c = new Contact(usr_id, id, listId, firstName, lastName, cellStr, email, homeAdd, age);
                masterList->push_back(c);
                divideIntoGroups(c);
            }
        }
    }
}

/**
 * @brief ContactList::findContact
 * @param name - phone number
 * @return contact found
 * Finds a specific contact from the system using its phone number
 */
Contact* ContactList::findContact(string name) {
    for (unsigned i = 0; i < treatmentGroup->size(); i++) {
        if (name.compare(treatmentGroup->at(i)->cellNum) == 0) {
            return treatmentGroup->at(i);
        }
    }
}


















