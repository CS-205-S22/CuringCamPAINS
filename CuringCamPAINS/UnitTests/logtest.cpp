#include "logtest.h"

LogTest::LogTest() {
}

//LogForm logFile = LogForm("../../../../../database.sqlite");
//LogForm logFile = LogForm();

//LogForm logFile = LogForm("../../../../../database.sqlite");
LogForm logFile = LogForm("../../test.sqlite");


TEST(Log, saveLogFormTest) {
    //ASSERT_TRUE(false) << "This test was not implemented. Failing...";
    ASSERT_EQ(logFile.name, "");
    ASSERT_EQ(logFile.age, "");
    ASSERT_EQ(logFile.phoneNumber, "");
    ASSERT_EQ(logFile.numOfAttempts, "");
    ASSERT_EQ(logFile.methodOfContact, "");
    ASSERT_EQ(logFile.reaction, "");
    ASSERT_EQ(logFile.date, "");
    ASSERT_EQ(logFile.committed, "");

    //logFile.saveLogForm("John Doe", "21", "123123", "5", "text", "excited", "March 20th, 2022", "false");
    QSqlQuery q;
    q.exec("SELECT fullName FROM logForm");
    string str;
    while(q.next()){
        str = q.value(0).toString().toStdString();
    }
    ASSERT_EQ(str,"John Doe");

    q.exec("SELECT age FROM logForm");
    while(q.next()){
        str = q.value(0).toString().toStdString();
    }
    ASSERT_EQ(str,"21");

    q.exec("SELECT phoneNumber FROM logForm");
    while(q.next()){
        str = q.value(0).toString().toStdString();
    }
    ASSERT_EQ(str,"123123");

    q.exec("SELECT numOfAttempts FROM logForm");
    while(q.next()){
        str = q.value(0).toString().toStdString();
    }
    ASSERT_EQ(str,"5");

    q.exec("SELECT methodOfContact FROM logForm");
    while(q.next()){
        str = q.value(0).toString().toStdString();
    }
    ASSERT_EQ(str,"text");

    q.exec("SELECT reaction FROM logForm");
    while(q.next()){
        str = q.value(0).toString().toStdString();
    }
    ASSERT_EQ(str,"excited");

    q.exec("SELECT isCommitted FROM logForm");
    while(q.next()){
        str = q.value(0).toString().toStdString();
    }
    ASSERT_EQ(str,"false");

}
