#ifndef SAVEDMESSAGES_H
#define SAVEDMESSAGES_H
#include "database.h"
#include <iostream>

using namespace std;

class SavedMessages:public Database
{
public:
    SavedMessages(string name);

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
     * @brief Function deletes a saved message from the savedmessages table within the system's database.
     * @param title - title of the message
     */
    void deleteMessage(string title);

    int getMessageMaxId();

    //messageId to be incremented for each write to the database
    int messageId = getMaxId("savedmessages", "messageId");

    vector<string> retStrings;
};

#endif // SAVEDMESSAGES_H
