#ifndef SAVEDMESSAGES_H
#define SAVEDMESSAGES_H
#include "database.h"
#include <iostream>

using namespace std;

class SavedMessages:public Database
{
public:
    SavedMessages(string name);
    SavedMessages(int usr, string name);

    /**
     * @brief Function writes a saved message to the savedmessages table within the system's database.
     * @param title - title of the message
     * @param message - text of the desired saved message
     */
    void createMessage(string title, string message);
    /**
     * @brief Function reads a saved message from the savedmessages table within the system's database for
     * the user to view.
     * @param title - title of the message
     */
    vector<string> viewMessage(string title);
    /**
     * @brief Function reads a saved message from the savedmessages table within the system's database for
     * the user to view.
     * @param title - title of the message
     */
    vector<string> viewTitles();
    /**
     * @brief Function deletes a saved message from the savedmessages table within the system's database.
     * @param title - title of the message
     */
    void deleteMessage(string title);

    int getMessageMaxId();

    /**
     * @brief Database:readText
     * Method get the content of a table on for a specific conditions
     * @param table_name : name of the table in the database
     * @param parameters: column names in the table
     * @param condition: values of the condition
     */
    vector<string> readText(string table_name,string usr_id,string parameter,string conditions);

    /**
     * @brief Database:readTitle
     * Method get the the title from savedmessage table
     * @param table_name : name of the table in the database
     * @param parameters: column names in the table
     * @param condition: values of the condition
     */
    vector<string> readTitle(string table_name,string usr_id,string parameter);

    /**
     * @brief Database:remove
     * Method to remove a row in the database based on a given condition
     * @param table_name : name of the table in the database
     * @param parameters: column name in the table
     * @param condition: values of the condition
     */
    void remove(string table_name,string usr_id,string parameter,string condition);


    //messageId to be incremented for each write to the database
    int messageId = getMaxId("savedmessages", "messageId") + 1;

    vector<string> retStrings;

    //so each system is specific to user
    int cur_id;
};

#endif // SAVEDMESSAGES_H
