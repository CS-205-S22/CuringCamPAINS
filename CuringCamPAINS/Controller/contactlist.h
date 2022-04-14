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
    ContactList();
    ContactList(string name);
//    ContactList(Database d);

    void getUserInput();
    void readFile(string name);
    void getManualEntry();
    void divideIntoGroups();
    bool containsContact(string cellNum);
    void addContact(Contact* c);
    void addContact(string fn, string ln, string cellNum, string email, string hAdd, string age);
    void deleteContact(Contact* c);
    void updateContact(); //update all information??
    void print();
    void writeToDB();
    void readFromDB();

//    Database* db;
    int count;
    vector<Contact*>* masterList;
    vector<Contact*>* treatmentGroup;
    vector<Contact*>* controlGroup;
    vector<Contact*>* noContactGroup;
};

#endif // CONTACTLIST_H
