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
    ContactList(int cur_id);
    ContactList(int cur_id,string name);
//    ContactList(Database d);

    void getUserInput();
    void readFile(string name);
    void getManualEntry();
    void divideIntoGroups(Contact* c);
    bool containsContact(string cellNum);
    void addContact(Contact* c);
    void addContact(string fn, string ln, string cellNum, string email, string hAdd, string age);
    void deleteContact(string cellNum);
    void updateContact(); //update all information??
    void print();
    void writeToDB();
    void readFromDB();
    Contact* findByFirstName(string name);

   int usr_id;
    vector<Contact*>* masterList;
    vector<Contact*>* treatmentGroup;
    vector<Contact*>* controlGroup;
    vector<Contact*>* noContactGroup;
};

#endif // CONTACTLIST_H
