#include "login.h"

Login::Login(std::string name):Database (name)
{

}

Login::~Login(){
    curr_db->close();
    curr_db = NULL;
}
/**
 * @brief Login::getUserInput
 * Get the user name input through command line
 */
void Login::getUserNameInput(){
    cout<<"Enter username: ";
    cin >> username; // Get user input from the keyboard
}

/**
 * @brief Login::getPasswordInput
 * Get the user password input through command line
 */
void Login::getPasswordInput(){
    cout<<"Enter password: ";
    cin >> password; // Get user input from the keyboard
}

/**
 * @brief Login::signUp
 * Verify if the user is valid
 */
void Login::signUp(){
    if(authenticate(QString::fromStdString(username),QString::fromStdString(password))==true){
        cout<<"Login successful"<<endl;
        return ;
    }
    else {cout<<"Login unsuccessful"<<endl;}
}

/**
 * @brief Login::signUp
 * Verify if the user is valid
 * @param usr:the username
 * @param pwd: password
 */
bool Login::signUp(string usr, string pwd){
    if(authenticate(QString::fromStdString(usr),QString::fromStdString(pwd))==true){
        cout<<"Login successful"<<endl;
        return true ;
    }
    else {cout<<"Login unsuccessful"<<endl;
        return false;}
}
/**
 * @brief Login::close
 * Close the login file
 */
void Login::close(){


    curr_db->close();
    curr_db = NULL;
}

int Login::getUserId( string usrname){
    QSqlQuery query;
    string table_name="user";
    string parameter="userName";
    string output="userId";
    std::string com = "SELECT "+output+" FROM "+ table_name + " WHERE "+parameter+"=:"+parameter;
    query.prepare(QString::fromStdString(com));
    string temp =":"+parameter;
    query.bindValue(QString::fromStdString(temp),QString::fromStdString(usrname));
    query.exec(); //execute the command
    query.next();
    int out =stoi(query.value(0).toString().toStdString());
    return out;

}

/**
 * @brief Database:authenticate
 * Method to verify if a user with a certain username and passwrd is in the database
 * @param usr : the username
 * @param pwd : password
 */
bool Login::authenticate(QString usr, QString pwd){

    try{
        QSqlQuery query;
        QString query_str_id = "SELECT password FROM user WHERE userName='"+usr+"' ;"; //get password
        query.exec(query_str_id);
        query.next();
        std::string result=query.value(0).toString().toStdString();
        std::string temp=pwd.toStdString();

        if(temp==result){
            return true;
        }
        else{
            return false;
        }
    }

    catch(...){
        cout<<"error occured"<<endl;
        return false;
    }
}
