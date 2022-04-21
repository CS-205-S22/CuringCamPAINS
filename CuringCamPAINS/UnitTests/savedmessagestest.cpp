#include "savedmessagestest.h"

SavedMessages sm("../../test.sqlite");

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

TEST(viewMessage, createMessageTest) {
    vector<string> ret;
    ret = sm.viewMessage("TestClass");
    ASSERT_EQ("Is this working?", ret.at(0));
}

TEST(deleteMessage, createMessageTest) {
    sm.createMessage("One", "one");
    int ret = sm.getMessageMaxId();
    ASSERT_EQ(2, ret);
    sm.deleteMessage("One");
    int ret2 = sm.getMessageMaxId();
    ASSERT_EQ(1, ret2);
}



