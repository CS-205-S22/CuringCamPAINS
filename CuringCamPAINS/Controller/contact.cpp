#include "contact.h"

using namespace std;

int Contact::counter = 0;

Contact::Contact(int usr_cur)
{
    usr_id = usr_cur;
}

Contact::Contact(int usr_cur, int id, int listId, string fn, string ln, string num, string email, string hAdd, int a) {
    usr_id = usr_cur;
    this->id = id;
    contactListId = listId;
    firstName = fn;
    lastName = ln;
    cellNum = num;
    cerr << "cel num in contact " << cellNum << endl;
    age = a;
    emailAddress = email;
    homeAddress = hAdd;
    counter = id;
//    cerr << "First name: " << fn << endl;
//    cerr << "ID: " << to_string(id) << endl;
}

Contact::Contact(int usr_cur, string fn, string ln, string num, int a) {
    usr_id=usr_cur;
    id = ++counter;
    firstName = fn;
    lastName = ln;
    cellNum = num;
    cerr << "cel num in contact " << cellNum << endl;
    age = a;
    emailAddress = "";
    homeAddress = "";
    contactListId = id % 3;
}

Contact::Contact(int usr_cur, string fn, string ln, string num, string email, int a) {
    usr_id=usr_cur;
    id = ++counter;
    firstName = fn;
    lastName = ln;
    cellNum = num;
    cerr << "cel num in contact " << cellNum << endl;
    age = a;
    emailAddress = email;
    homeAddress = "";
    contactListId = id % 3;
}

Contact::Contact(int usr_cur, string fn, string ln, string num, string email, string hAdd, int a) {
    usr_id=usr_cur;
    id = ++counter;
    firstName = fn;
    lastName = ln;
    cellNum = num;
    age = a;
    emailAddress = email;
    homeAddress = hAdd;
    contactListId = id % 3;
}

Contact::Contact(int usr_cur, int id, string fn, string ln, string num, string email, string hAdd, int a) {
    usr_id = usr_cur;
    this->id = id;
    firstName = fn;
    lastName = ln;
    cellNum = num;
    age = a;
    emailAddress = email;
    homeAddress = hAdd;
    contactListId = id % 3;
    counter = id;
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

















