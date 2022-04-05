#include "savedmessages.h"

SavedMessages::SavedMessages()
{

}

void SavedMessages::createMessage(string title, string message) {
    QString Qtitle = QString::fromUtf8(title.c_str());
    QString Qmessage = QString::fromUtf8(message.c_str());
    this->db.write();
}

void SavedMessages::viewMessage(string title) {
    QString Qtitle = QString::fromUtf8(title.c_str());
    this->db.read();
}

void SavedMessages::deleteMessage(string title) {
    QString Qtitle = QString::fromUtf8(title.c_str());
    this->db.remove();
}
