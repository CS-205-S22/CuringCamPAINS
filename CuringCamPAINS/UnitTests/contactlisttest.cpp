#include "contactlisttest.h"

ContactListTest::ContactListTest() {
}

TEST(ContactList, UnimplementedTest) {
    ASSERT_TRUE(false) << "This test was not implemented. Failing...";
}

TEST(ContactList, addContactTest) {
    ContactList* cl = new ContactList("../../test.sqlite");
    Contact* c = new Contact("Justin", "Smith", "1345672890", "justin@gmail", "blabla", 12);
    cl->addContact(c);
    ASSERT_EQ(1, cl->masterList->size());
}

TEST(ContactList, addContactTest2) {
    ContactList* cl = new ContactList("../../test.sqlite");
    Contact* c = new Contact("Justin", "Smith", "1345672890", "justin@gmail", "blabla", 12);
    Contact* c2 = new Contact("Steve", "Blah", "1345672895", "adfa", "blabla", 34);
    cl->addContact(c);
    cl->addContact(c2);

    ASSERT_EQ(1, c->contactListId);
    ASSERT_EQ(2, c2->contactListId);
}

TEST(ContactList, containsContactTest) {
    ContactList* cl = new ContactList("../../test.sqlite");
    Contact* c = new Contact("Justin", "Smith", "1345672890", "justin@gmail", "blabla", 12);

    ASSERT_EQ(true, cl->containsContact("1345672890"));
    ASSERT_EQ(false, cl->containsContact("1234567890"));
}

TEST(ContactList, divideIntoGroupsTest) {
    ContactList* cl = new ContactList("../../test.sqlite");
    Contact* c = new Contact("Justin", "Smith", "1345672890", "justin@gmail", "blabla", 12);
    Contact* c2 = new Contact("Steve", "Blah", "1345672895", "adfa", "blabla", 34);
    Contact* c3 = new Contact("Matt", "Blaker", "1345672854", "afgh", "ergr", 45);

    cl->addContact(c);
    cl->addContact(c2);
    cl->addContact(c3);
    cl->divideIntoGroups();

//    ASSERT_EQ(1, cl.)
}
