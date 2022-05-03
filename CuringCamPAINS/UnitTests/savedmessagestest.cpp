#include "savedmessagestest.h"

SavedMessages sm(0,"../../test.sqlite");

SavedMessagesTest::SavedMessagesTest()
{

}

TEST(SavedMessages, UnimplementedTest) {
    ASSERT_TRUE(true) << "This test was not implemented. Failing...";
}


TEST(createMessage, createMessageTest) {
    sm.createMessage("TestClass", "Is this working?");
    //use query
    QSqlQuery q;
    q.exec("SELECT messageTitle FROM savedmessages");
    string ret;
    while(q.next()) {
        ret = q.value(0).toString().toStdString();
    }
    ASSERT_EQ(ret, "TestClass");
}

TEST(viewMessage, viewMessageTest) {
    vector<string> ret;
    ret = sm.viewMessage("TestClass");
    ASSERT_EQ("Is this working?", ret.at(0));
}

TEST(deleteMessage, deleteMessageTest) {
    sm.createMessage("One", "one");
    int ret = sm.getMessageMaxId();
    ASSERT_EQ(3, ret);
    sm.deleteMessage("One");
    int ret2 = sm.getMessageMaxId();
    ASSERT_EQ(2, ret2);
    //empty table
    sm.deleteMessage("TestClass");
}



