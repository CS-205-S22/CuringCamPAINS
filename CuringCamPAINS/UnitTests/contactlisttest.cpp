#include "contactlisttest.h"

ContactListTest::ContactListTest() {
    ContactList* cl = new ContactList();
}

TEST(ContactList, UnimplementedTest) {
    ASSERT_TRUE(false) << "This test was not implemented. Failing...";
}

TEST(ContactList, addContactTest) {
//    void ContactList::addContact(string fn, string ln, string cellNum, string email, string hAdd, string age){
    Contact* c = new Contact("Justin", "Smith", "1345672890", "justin@gmail", "blabla", 12);

}
