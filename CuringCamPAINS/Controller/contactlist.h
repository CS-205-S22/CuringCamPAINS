#ifndef CONTACTLIST_H
#define CONTACTLIST_H
#include "database.h"
#include "contact.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

class ContactList:public Database
{
public:
    ContactList(string name);
    ContactList(int cur_id,string name);

    void getUserInput();  //gets user input when run in TUI
    void readFile(string name);  //reads the file with given name
    void getManualEntry();  //gets manual entry information when run in TUI
    void divideIntoGroups(Contact* c);  //assigns a contact into one of the three
    bool containsContact(string cellNum);  //checks if a contact is already saved before
    void addContact(Contact* c);  //adds a contact into the system and database
    void addContact(string fn, string ln, string cellNum, string email, string hAdd, string age);
    void deleteContact(string cellNum);  //deletes a contact from the system and database
    void print();  //print contacts in each group
    void readFromDB();  //makes the contact as the same as how it was before the last logout
    Contact* findContact(string name);  //returns a specific contact in the database

   int usr_id;
    vector<Contact*>* masterList;  //stores all contacts in the database
    vector<Contact*>* treatmentGroup;  //stores the contacts that need to be reached out to
    vector<Contact*>* controlGroup;  //stores the contacts that the researcher would reach out to
    vector<Contact*>* noContactGroup;  //contacts that would not be reached out to at all
};

#endif // CONTACTLIST_H
