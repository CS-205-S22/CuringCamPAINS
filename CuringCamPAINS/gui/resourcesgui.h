#ifndef RESOURCESGUI_H
#define RESOURCESGUI_H

#include <QWidget>
#include <QColorDialog>
#include <sstream>
#include "../Controller/savedmessages.h"

using namespace std;

namespace Ui {
class ResourcesGui;
}

class ResourcesGui : public QWidget
{
    Q_OBJECT

public:
    explicit ResourcesGui(QWidget *parent = nullptr);
    explicit ResourcesGui(int usr,QWidget *parent = nullptr);
    ~ResourcesGui();
    QString getSyle();

    int cur_usr;
private slots:
    void on_pushButton_changeColor_clicked();

    void on_pushButton_createMessage_clicked();

    void on_pushButton_viewMessage_clicked();

    void on_pushButton_deleteMessage_clicked();

    void on_pushButton_saveMessage_clicked();

    void on_pushButton_view_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_back2_clicked();

    void on_pushButton_back3_clicked();

    void on_pushButton_profileUpdate_clicked();

private:
    Ui::ResourcesGui *ui;
    string title, text;
    SavedMessages *sm;
    QString style;

signals:
    void changeColorSignal();
};

#endif // RESOURCESGUI_H
