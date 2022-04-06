#ifndef SAVEDMESSAGES_H
#define SAVEDMESSAGES_H
#include "database.h"
#include <iostream>

using namespace std;

class SavedMessages
{
public:
    SavedMessages();

    void createMessage(string title, string message);
    void viewMessage(string title);
    void deleteMessage(string title);

    Database db;
};

#endif // SAVEDMESSAGES_H
