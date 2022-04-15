#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>

using namespace std;

class Contact
{
public:
    Contact();
    Contact(int id, int listId, string fn, string ln, string num, string email, string hAdd, int age);
    Contact(string fn, string ln, string num, int age); //required sections
    Contact(string fn, string ln, string num, string email, int age);
    Contact(string fn, string ln, string num, string email, string hAdd, int age);
    void setCellNum(string num);
    void setEmail(string email);
    void setHomeAdd(string hAdd);
    void setAge(int age); //?????????

    void update(string fn, string ln, string num, string email, string hAdd, int age);

    int id;
    string firstName;
    string lastName;
    string cellNum;
    string emailAddress;
    string homeAddress; //??? do we need it?
    int age;  //age or birthday
    int contactListId;
    //LogForm object

private:
    static int counter;
};

#endif // CONTACT_H
