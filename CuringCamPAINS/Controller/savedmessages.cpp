#include "savedmessages.h"

SavedMessages::SavedMessages(string name):Database(name)
{

}

void SavedMessages::createMessage(string title, string message) {
    string cols[] = {"messageId","messageTitle", "messageText"};
    string messageId = to_string(this->messageId);
    string messages[] = {messageId, title, message};
    write("savedmessages", cols, 3, messages);
    this->messageId++;
}

void SavedMessages::viewMessage(string title) {
    //read(title);
}

void SavedMessages::deleteMessage(string title) {
    remove("savedmessages", "messageTitle", title);
}
