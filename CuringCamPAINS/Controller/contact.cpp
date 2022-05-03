#include "contact.h"

using namespace std;

int Contact::counter = 0;

/**
 * @brief Contact::Contact
 * @param usr_cur - current user ID
 * @param id - contact ID
 * @param listId - contactList / group ID
 * @param fn - first name
 * @param ln - last name
 * @param num - phone number
 * @param email - email address
 * @param hAdd - home address
 * @param a - age
 */
Contact::Contact(int usr_cur, int id, int listId, string fn, string ln, string num, string email, string hAdd, int a) {
    usr_id = usr_cur;
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

/**
 * @brief Contact::update
 * @param fn
 * @param ln
 * @param num
 * @param email
 * @param hAdd
 * @param a
 * Updates information in the contact with the given new info
 */
void Contact::update(string fn, string ln, string num, string email, string hAdd, int a) {
    firstName = fn;
    lastName = ln;
    cellNum = num;
    age = a;
    emailAddress = email;
    homeAddress = hAdd;
}

















