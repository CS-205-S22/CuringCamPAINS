#include "contactlist.h"
#include <QDir>

const int TREATMENT = 0;
const int CONTROL = 1;
const int NOCONTACT = 2;

ContactList::ContactList() {

}

ContactList::ContactList(string name):Database(name)
{
    masterList = new vector<Contact*>();
    treatmentGroup = new vector<Contact*>();
    controlGroup = new vector<Contact*>();
    noContactGroup = new vector<Contact*>();

    readFromDB();
}

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

void ContactList::readFile(string name) {
    ifstream file;
    string line;

    string firstName;
    string lastName;
    string cellStr;
    string email;
    string hAdd;
    string ageStr;
    string cols[] = {"contactId", "contactListId", "firstName", "lastName", "phoneNumber", "emailAddress", "homeAddress", "dateOfBirth"};

    cerr << name << endl;
    cout << QDir::currentPath().toStdString() << endl;

    file.open(name, fstream::in);

    if (!file.is_open()) {
        cout << "Error reading file.\n";
        exit(1);
    } else {
        getline(file, line);  //first row

        cout << "REading the file." << endl;

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

            Contact* c = new Contact(firstName, lastName, cellStr, email, hAdd, stoi(ageStr));
            masterList->push_back(c);

            string id = to_string(c->id);
            string listIdStr = to_string(c->contactListId);
            string inputs[] = {id, listIdStr, firstName, lastName, cellStr, email, hAdd, ageStr};
            write("contact", cols, 8, inputs);
        }
    }

    file.close();

    divideIntoGroups();
}

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

void ContactList::divideIntoGroups() {
    for (unsigned i = 0; i < masterList->size(); i++) {    //print all splitted strings
          if (i % 3 == 0) {
              treatmentGroup->push_back(masterList->at(i));
              masterList->at(i)->contactListId = TREATMENT;
          } else if (i % 3 == 1) {
              controlGroup->push_back(masterList->at(i));
              masterList->at(i)->contactListId = CONTROL;
          } else {
              noContactGroup->push_back(masterList->at(i));
              masterList->at(i)->contactListId = NOCONTACT;
          }
    }

//    print();
}

bool ContactList::containsContact(string str) {

    for (unsigned i = 0; i < masterList->size(); i++) {
        if (str.compare(masterList->at(i)->cellNum) == 0)
            return true;
    }

    return false;
}

void ContactList::addContact(string fn, string ln, string cellNum, string email, string hAdd, string age){
    int size = masterList->size();

    if (containsContact(cellNum)) {
        cout << "Contact is already saved!" << endl;
        return;
    }

    Contact* c = new Contact(fn, ln, cellNum, email, hAdd, stoi(age));
    masterList->push_back(c);

    string cols[] = {"contactId", "contactListId", "firstName", "lastName", "phoneNumber", "emailAddress", "homeAddress", "dateOfBirth"};
    string id = to_string(c->id);
    string listIdStr = to_string(c->contactListId);
    string inputs[] = {id, listIdStr, fn, ln, cellNum, email, hAdd, age};
    write("contact", cols, 8, inputs);

    if (size % 3 == 0) {
        treatmentGroup->push_back(c);
    } else if (size % 3 == 1) {
        controlGroup->push_back(c);
    } else {
        noContactGroup->push_back(c);
    }

//    print();
}

void ContactList::addContact(Contact *c) {
    int size = masterList->size();
    masterList->push_back(c);

    if (size % 3 == 0) {
        treatmentGroup->push_back(c);
    } else if (size % 3 == 1) {
        controlGroup->push_back(c);
    } else {
        noContactGroup->push_back(c);
    }
}

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

void ContactList::readFromDB() {
    QSqlQuery query;
    QString str = "select * from contact;";
    int id;
    int listId;
    string firstName;
    string lastName;
    string cellStr;
    string email;
    string homeAdd;
    int age;

    if (!query.exec(str)){
        qDebug()<<"error running query for Players\n";
    } else {
        while (query.next()) {
            id = stoi(query.value("contactId").toString().toStdString());
            listId = stoi(query.value("contactListId").toString().toStdString());
            firstName = query.value("firstName").toString().toStdString();
            lastName = query.value("lastName").toString().toStdString();
            cellStr = query.value("phoneNumber").toString().toStdString();
            email = query.value("emailAddress").toString().toStdString();
            homeAdd = query.value("homeAddress").toString().toStdString();
            age = stoi(query.value("dateOfBirth").toString().toStdString());

            Contact* c = new Contact(id, listId, firstName, lastName, cellStr, email, homeAdd, age);

            masterList->push_back(c);
        }
    }
}




















