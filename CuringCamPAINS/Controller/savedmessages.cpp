#include "savedmessages.h"

SavedMessages::SavedMessages(string name):Database(name)
{

}

SavedMessages::SavedMessages(int id,string name):Database(name)
{
    cur_id=id;
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
    string messageId = to_string(this->messageId);
    cout<<messageId<<endl;
    string messages[] = {messageId,std::to_string(cur_id), title, message};
    write("savedmessages", messages);
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
    this->retStrings = readText("savedmessages",std::to_string(cur_id), "messageTitle", title);
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
    this->retStrings = readTitle("savedmessages",std::to_string(cur_id), "messageTitle");
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
    //check if now empty, can reset id
}

/**
 * @brief Database:readText
 * Method get the content of a table on for a specific conditions
 * @param table_name : name of the table in the database
 * @param parameters: column names in the table
 * @param condition: values of the condition
 */
vector<string> SavedMessages::readText(string table_name,string usr_id,string parameter,string condition) {
    QSqlQuery query;
    std::string com = "SELECT* FROM "+ table_name + " WHERE "+parameter+"=:"+parameter+" AND userId="+usr_id;
    query.prepare(QString::fromStdString(com));
    string temp =":"+parameter;
    query.bindValue(QString::fromStdString(temp),QString::fromStdString(condition));
    query.exec(); //execute the command
    vector<string> messages;
    while(query.next()) {
        QString text = query.value(2).toString();
        messages.push_back(text.toStdString());
    }
    return messages;
}

int SavedMessages::getMessageMaxId() {
    return getMaxId("savedmessages", "messageId");
}

/**
 * @brief SavedMessages:readTitle
 * Method get the the title from savedmessage table
 * @param table_name : name of the table in the database
 * @param parameters: column names in the table
 * @param condition: values of the condition
 */
vector<string> SavedMessages::readTitle(string table_name,string usr_id, string parameter) {
    QSqlQuery query;
    std::string com = "SELECT "+ parameter + " FROM "+table_name+" AND userId="+usr_id;
    query.prepare(QString::fromStdString(com));
    query.exec(); //execute the command
    vector<string> titles;
    while(query.next()) {
        QString text = query.value(0).toString();
        titles.push_back(text.toStdString());
    }
    return titles;
}
