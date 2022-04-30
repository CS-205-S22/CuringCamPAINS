#include "logtest.h"

LogTest::LogTest() {
}

//LogForm logFile = LogForm("../../../../../database.sqlite");



//LogForm logFile = LogForm();

//LogForm logFile = LogForm("../../../../../database.sqlite");
LogForm logFile = LogForm(1,"../../test.sqlite");




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

/*TEST(Log, deleteFromDatabase) {

    logFile.saveLogForm("Josh G", "19", "717-111-2222", "5", "text", "excited", "04/12/2022", "false");

    QSqlQuery q;
    q.exec("SELECT logId FROM logForm");
    string str;
    while(q.next()){
        str = q.value(0).toString().toStdString();
    }
    cout << "STR:" << str << endl;

    logFile.deleteLog("717-111-2222");

    q.exec("SELECT logId FROM logForm");
    string strTwo;
    while(q.next()){
        strTwo = q.value(0).toString().toStdString();
    }
    cout << "STR_TWO:" << strTwo << endl;

    ASSERT_EQ(str,"23");
    ASSERT_EQ(strTwo,"22");
}*/

TEST(Log, betterDeleteFromDatabase){
    //count how many entries match the exact entry that I am about to pass
    //then add the new entry
    //then count how many match the entry
    //then delete the entry
    //then count how many match the entry

    logFile.deleteLog("123-456-7890");

    QSqlQuery q;
    q.exec("SELECT COUNT(logId) FROM logForm WHERE fullName = 'Josh Garcia' AND age = '19' AND phoneNumber = '123-456-7890' ");
    q.next();
    string result = q.value(0).toString().toStdString();
    cout << "Result :" << result << endl;
    ASSERT_EQ(result, "0");

    logFile.saveLogForm("Josh Garcia", "19", "123-456-7890", "5", "text", "excited", "04/12/2022", "false");

    q.exec("SELECT COUNT(logId) FROM logForm WHERE fullName = 'Josh Garcia' AND age = '19' AND phoneNumber = '123-456-7890' ");
    q.next();
    result = q.value(0).toString().toStdString();
    cout << "Result :" << result << endl;
    ASSERT_EQ(result, "1");

    logFile.deleteLog("123-456-7890");

    q.exec("SELECT COUNT(logId) FROM logForm WHERE fullName = 'Josh Garcia' AND age = '19' AND phoneNumber = '123-456-7890' ");
    q.next();
    result = q.value(0).toString().toStdString();
    cout << "Result :" << result << endl;
    ASSERT_EQ(result, "0");
}
