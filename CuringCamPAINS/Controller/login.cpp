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

    //std::cerr << "closing object\n";

    curr_db->close();
    curr_db = NULL;
}
