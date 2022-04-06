#ifndef CONTACTLIST_H
#define CONTACTLIST_H
#include "contact.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

class ContactList
{
public:
    ContactList();

    void getUserInput();
    void readFile(string name);
    void getManualEntry();
    void divideIntoGroups();
    void addContact(Contact* c);
    void addContact(string fn, string ln, string cellNum, string email, string hAdd, int age);
    void deleteContact(Contact* c);
    void updateContact(); //update all information??
    void print();

    int count;
    vector<Contact*>* masterList;
    vector<Contact*>* treatmentGroup;
    vector<Contact*>* controlGroup;
    vector<Contact*>* noContactGroup;
};

#endif // CONTACTLIST_H
