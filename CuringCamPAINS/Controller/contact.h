#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>

using namespace std;

class Contact
{
public:
    //Constructors for the class
    Contact(int usr_cur, int id, int listId, string fn, string ln, string num, string email, string hAdd, int age);
    Contact(int usr_cur, string fn, string ln, string num, string email, string hAdd, int age);
    Contact(int usr_cur, int id, string fn, string ln, string num, string email, string hAdd, int age);

    //Updates the contact information
    void update(string fn, string ln, string num, string email, string hAdd, int age);

    int usr_id;
    int id;
    string firstName;
    string lastName;
    string cellNum;
    string emailAddress;
    string homeAddress;
    int age;
    int contactListId;

private:
    static int counter;
};

#endif // CONTACT_H
