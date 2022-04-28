#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>

using namespace std;

class Contact
{
public:
    Contact(int usr_cur);
    Contact(int usr_cur,int id, int listId, string fn, string ln, string num, string email, string hAdd, int age);
    Contact(int usr_cur,string fn, string ln, string num, int age); //required sections
    Contact(int usr_cur,string fn, string ln, string num, string email, int age);
    Contact(int usr_cur,string fn, string ln, string num, string email, string hAdd, int age);
    void setCellNum(string num);
    void setEmail(string email);
    void setHomeAdd(string hAdd);
    void setAge(int age); //?????????

    void update(string fn, string ln, string num, string email, string hAdd, int age);

    int usr_id;
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
