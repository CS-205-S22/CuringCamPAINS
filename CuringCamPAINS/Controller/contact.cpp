#include "contact.h"

Contact::Contact()
{

}

Contact::Contact(string fn, string ln, string num, int a) {
    firstName = fn;
    lastName = ln;
    cellNum = num;
    age = a;
    emailAddress = "";
    homeAddress = "";
}

Contact::Contact(string fn, string ln, string num, string email, int a) {
    firstName = fn;
    lastName = ln;
    cellNum = num;
    age = a;
    emailAddress = email;
    homeAddress = "";
}

Contact::Contact(string fn, string ln, string num, string email, string hAdd, int a) {
    firstName = fn;
    lastName = ln;
    cellNum = num;
    age = a;
    emailAddress = email;
    homeAddress = hAdd;
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

















