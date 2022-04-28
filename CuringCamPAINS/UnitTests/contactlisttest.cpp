#include "contactlisttest.h"

ContactListTest::ContactListTest() {

}

TEST(ContactList, UnimplementedTest) {
//    ASSERT_TRUE(false) << "This test was not implemented. Failing...";
}

TEST(ContactList, addContactTest) {
    ContactList* cl = new ContactList(1,"../../test.sqlite");
    Contact* c = new Contact(1,"Justin", "Smith", "1345672890", "justin@gmail", "blabla", 12);
    cl->addContact(c);

    ASSERT_EQ(1, cl->masterList->size());

    cl->deleteContact("1345672890");
}

TEST(ContactList, addContactTest2) {
    ContactList* cl = new ContactList(1,"../../test.sqlite");
    Contact* c = new Contact(1,"Justin", "Smith", "1345672890", "justin@gmail", "blabla", 12);
    Contact* c2 = new Contact(1,"Steve", "Blah", "1345672895", "adfa", "blabla", 34);
    cl->addContact(c);
    cl->addContact(c2);

    ASSERT_EQ(2, c->contactListId);
    ASSERT_EQ(0, c2->contactListId);

    cl->deleteContact("1345672890");
    cl->deleteContact("1345672895");
}

TEST(ContactList, containsContactTest) {
    ContactList* cl = new ContactList(1,"../../test.sqlite");
    Contact* c = new Contact(1,"Justin", "Smith", "1345672890", "justin@gmail", "blabla", 12);
    cl->addContact(c);

    ASSERT_EQ(true, cl->containsContact("1345672890"));
    ASSERT_EQ(false, cl->containsContact("1234567890"));

    cl->deleteContact("1345672890");
}

TEST(ContactList, containsContactFalseTest) {
    ContactList* cl = new ContactList(1,"../../test.sqlite");
    Contact* c = new Contact(1,"Justin", "Smith", "1345672890", "justin@gmail", "blabla", 12);
    cl->addContact(c);

    ASSERT_EQ(false, cl->containsContact("1234567890"));

    cl->deleteContact("1345672890");
}

TEST(ContactList, divideIntoGroupsTest) {
    ContactList* cl = new ContactList(1,"../../test.sqlite");
    Contact* c = new Contact(1,"Justin", "Smith", "1345672890", "justin@gmail", "blabla", 12);
    Contact* c2 = new Contact(1,"Steve", "Blah", "1345672895", "adfa", "blabla", 34);
    Contact* c3 = new Contact(1,"Matt", "Blaker", "1345672854", "afgh", "ergr", 45);

    cl->addContact(c);
    cl->addContact(c2);
    cl->addContact(c3);

    ASSERT_EQ(1, cl->treatmentGroup->size());
    ASSERT_EQ(1, cl->controlGroup->size());
    ASSERT_EQ(1, cl->noContactGroup->size());

    cl->deleteContact("1345672890");
    cl->deleteContact("1345672895");
    cl->deleteContact("1345672854");
}

TEST(ContactList, deleteContact) {
    ContactList* cl = new ContactList(1,"../../test.sqlite");
    Contact* c = new Contact(1,"Justin", "Smith", "1345672890", "justin@gmail", "blabla", 12);
    cl->addContact(c);
    cl->deleteContact(c->cellNum);

    ASSERT_EQ(0, cl->masterList->size());
}
