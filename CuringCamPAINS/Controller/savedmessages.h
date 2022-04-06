#ifndef SAVEDMESSAGES_H
#define SAVEDMESSAGES_H
#include "database.h"
#include <iostream>

using namespace std;

class SavedMessages:public Database
{
public:
    SavedMessages(string name);

    void createMessage(string title, string message);
    void viewMessage(string title);
    void deleteMessage(string title);

    int messageId = 0;
};

#endif // SAVEDMESSAGES_H
