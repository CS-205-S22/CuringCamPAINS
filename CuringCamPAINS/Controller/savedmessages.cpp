#include "savedmessages.h"

SavedMessages::SavedMessages(string name):Database(name)
{

}

/**
 * @brief Function writes a saved message to the savedmessages table within the system's database. The function
 * takes a string title and message, which is taken from the user input. The function creates a string array
 * of the table's columns. Also, the class's messageId is turned to a string so that it can be input into the table.
 * The messages string array holds the id, title and text to be written to the table. The function inherits the
 * Database's write function and inserts the necessary parameters. The messageId is incremented.
 * @param title - title of the message
 * @param message - text of the desired saved message
 */
void SavedMessages::createMessage(string title, string message) {
    string cols[] = {"messageId","messageTitle", "messageText"};
    string messageId = to_string(this->messageId);
    string messages[] = {messageId, title, message};
    write("savedmessages", cols, 3, messages);
    this->messageId++;
}

/**
 * @brief Function reads a saved message from the savedmessages table within the system's database for the user to view.
 * Function has one parameter, string title. This is the title of the desired message. The function inherits the
 * Database's read function and inputs the necessary parameters.
 * @param title - title of the message
 */
vector<string> SavedMessages::viewMessage(string title) {
    this->retStrings.clear();
    this->retStrings = readText("savedmessages", "messageTitle", title);
    return retStrings;
}

/**
 * @brief Function reads a saved message from the savedmessages table within the system's database for the user to view.
 * Function has one parameter, string title. This is the title of the desired message. The function inherits the
 * Database's read function and inputs the necessary parameters.
 * @param title - title of the message
 */
vector<string> SavedMessages::viewTitles() {
    this->retStrings.clear();
    this->retStrings = readTitle("savedmessages", "messageTitle");
    return retStrings;
}

/**
 * @brief Function deletes a saved message from the savedmessages table within the system's database. The function takes
 * one parameter, which is the string title of the message to be deleted. The function inherits the Database's remove
 * function and inserts the name of the table, the name of the column and the title parameter.
 * @param title - title of the message
 */
void SavedMessages::deleteMessage(string title) {
    remove("savedmessages", "messageTitle", title);
}

int SavedMessages::getMessageMaxId() {
    return getMaxId("savedmessages", "messageId");
}
