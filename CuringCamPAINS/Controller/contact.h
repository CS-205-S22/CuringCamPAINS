#ifndef CONTACT_H
#define CONTACT_H

#include <string>

using namespace std;

class Contact
{
public:
    Contact();
    Contact(string fn, string ln, string num, int age); //required sections
    Contact(string fn, string ln, string num, string email, int age);
    Contact(string fn, string ln, string num, string email, string hAdd, int age);
    void setCellNum(string num);
    void setEmail(string email);
    void setHomeAdd(string hAdd);
    void setAge(int age); //?????????

    void update(string fn, string ln, string num, string email, string hAdd, int age);

    string firstName;
    string lastName;
    string cellNum;
    string emailAddress;
    string homeAddress; //??? do we need it?
    int age;  //age or birthday
};

#endif // CONTACT_H
