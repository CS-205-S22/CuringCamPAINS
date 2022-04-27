#include "logtest.h"

LogTest::LogTest() {
}

//LogForm logFile = LogForm("../../../../../database.sqlite");
//LogForm logFile = LogForm();

//LogForm logFile = LogForm("../../../../../database.sqlite");
LogForm logFile = LogForm("../../test.sqlite");


TEST(Log, SaveLog) {
    //ASSERT_TRUE(false) << "This test was not implemented. Failing...";
    ASSERT_EQ(logFile.name, "");
    ASSERT_EQ(logFile.age, "");
    ASSERT_EQ(logFile.phoneNumber, "");
    ASSERT_EQ(logFile.numOfAttempts, "");
    ASSERT_EQ(logFile.methodOfContact, "");
    ASSERT_EQ(logFile.reaction, "");
    ASSERT_EQ(logFile.date, "");
    ASSERT_EQ(logFile.committed, "");

    logFile.saveLogForm("John Doe", "21", "123123", "5", "text", "excited", "March 20th, 2022", "false");
    ASSERT_EQ(logFile.name, "John Doe");
    ASSERT_EQ(logFile.age, "21");
    ASSERT_EQ(logFile.phoneNumber, "123123");
    ASSERT_EQ(logFile.numOfAttempts, "5");
    ASSERT_EQ(logFile.methodOfContact, "text");
    ASSERT_EQ(logFile.reaction, "excited");
    ASSERT_EQ(logFile.date, "March 20th, 2022");
    ASSERT_EQ(logFile.committed, "false");
}
