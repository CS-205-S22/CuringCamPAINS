#include "contactlist.h"

ContactList::ContactList()
{
    count = 0;
    masterList = new vector<Contact*>();
    treatmentGroup = new vector<Contact*>();
    controlGroup = new vector<Contact*>();
    noContactGroup = new vector<Contact*>();
}

void ContactList::getUserInput() {
    char ch;
    string filename;

    while(true) {
        cout << "Enter F for uploading file, M for manual entry or X for exit." << endl;
        cin >> ch;

        if (ch == 'F') {
            cout << "Enter the file name." << endl;
            cin >> filename;

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

    file.open(name, fstream::in);

    if (!file.is_open()) {
        cout << "Error reading file.\n";
        exit(1);
    } else {
        getline(file, line);  //first row

        while(getline(file, line)) {
            stringstream strStream(line);
            getline(strStream, firstName, ',');
            getline(strStream, lastName, ',');
            getline(strStream, cellStr, ',');
            getline(strStream, email, ',');
            getline(strStream, hAdd, ',');
            getline(strStream, ageStr, ',');

            Contact* c = new Contact(firstName, lastName, cellStr, email, hAdd, stoi(ageStr));
            masterList->push_back(c);
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

    addContact(firstName, lastName, cellStr, email, hAdd, stoi(ageStr));
}

void ContactList::divideIntoGroups() {
    for (unsigned i = 0; i < masterList->size(); i++) {    //print all splitted strings
          if (i % 3 == 0) {
              treatmentGroup->push_back(masterList->at(i));
          } else if (i % 3 == 1) {
              controlGroup->push_back(masterList->at(i));
          } else {
              noContactGroup->push_back(masterList->at(i));
          }
    }

    print();
}

void ContactList::addContact(string fn, string ln, string cellNum, string email, string hAdd, int age){
    int size = masterList->size();
    Contact* c = new Contact(fn, ln, cellNum, email, hAdd, age);
    masterList->push_back(c);

    if (size % 3 == 0) {
        treatmentGroup->push_back(c);
    } else if (size % 3 == 1) {
        controlGroup->push_back(c);
    } else {
        noContactGroup->push_back(c);
    }

    print();
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





















