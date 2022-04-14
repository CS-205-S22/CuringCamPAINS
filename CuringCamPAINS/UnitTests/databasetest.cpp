#include "databasetest.h"

DatabaseTest::DatabaseTest() {
}

TEST(getMaxId, getMaxIdTest) {
   Database *dbb;
    dbb=new Database("../../test.sqlite");
    int result=dbb->getMaxId("user","userId");
    int expected=5;
     cout<<"Here"<<endl;
    ASSERT_EQ(result, expected);

}

TEST(write,writeDBTest ) {
   Database *dbb;
    dbb=new Database("../../test.sqlite");
    int old=dbb->getMaxId("user","userId");
    string id =std::to_string(old+1);
    string parameters[] = {"userId", "name", "password", "userName","isResearcher"};
    string values[] = {id, "Test", "pluss", "litat","0"};
    dbb->write("user",parameters,5,values);
    int result=dbb->getMaxId("user","userId");
    int expected=6;
    ASSERT_EQ(result, expected);

}

TEST(remove,removeDBTest ) {
   Database *dbb;
    dbb=new Database("../../test.sqlite");
    dbb->remove("user","name","Test");
    int result=dbb->getMaxId("user","userId");
    int expected=5;
    ASSERT_EQ(result, expected);

}
