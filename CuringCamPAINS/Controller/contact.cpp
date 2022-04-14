#include "contact.h"

int Contact::counter = 0;

Contact::Contact()
{

}

Contact::Contact(int id, int listId, string fn, string ln, string num, string email, string hAdd, int a) {
    this->id = id;
    contactListId = listId;
    firstName = fn;
    lastName = ln;
    cellNum = num;
    age = a;
    emailAddress = email;
    homeAddress = hAdd;
    counter = id;
}

Contact::Contact(string fn, string ln, string num, int a) {
    id = ++counter;
    firstName = fn;
    lastName = ln;
    cellNum = num;
    age = a;
    emailAddress = "";
    homeAddress = "";
    contactListId = id % 3;
}

Contact::Contact(string fn, string ln, string num, string email, int a) {
    id = ++counter;
    firstName = fn;
    lastName = ln;
    cellNum = num;
    age = a;
    emailAddress = email;
    homeAddress = "";
    contactListId = id % 3;
}

Contact::Contact(string fn, string ln, string num, string email, string hAdd, int a) {
    id = ++counter;
    firstName = fn;
    lastName = ln;
    cellNum = num;
    age = a;
    emailAddress = email;
    homeAddress = hAdd;
//    contactListId = listId;
    contactListId = id % 3;
}

void Contact::setCellNum(string num) {
    cellNum = num;
}

void Contact::setAge(int a) {
    age = a;
}

void Contact::setEmail(string email) {
    emailAddress = email;
}

void Contact::setHomeAdd(string hAdd) {
    homeAddress = hAdd;
}

void Contact::update(string fn, string ln, string num, string email, string hAdd, int a) {
    firstName = fn;
    lastName = ln;
    cellNum = num;
    age = a;
    emailAddress = email;
    homeAddress = hAdd;
}

















