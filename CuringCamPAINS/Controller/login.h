#ifndef LOGIN_H
#define LOGIN_H
#include "database.h"

class Login:public Database
{
public:
    Login(std::string name);
    ~Login();

    /**
     * @brief Login::getUserInput
     * Get the user name input through command line
     */
    void getUserNameInput();
    /**
     * @brief Login::getPasswordInput
     * Get the user password input through command line
     */
    void getPasswordInput();

    /**
     * @brief Database:authenticate
     * Method to verify if a user with a certain username and passwrd is in the database
     * @param usr : the username
     * @param pwd : password
     */
    bool authenticate(QString usr, QString pwd);

    /**
     * @brief Login::signUp
     * Verify if the user is valid
     */
    void signUp();
    void validateAccount();

    /**
     * @brief Login::signUp
     * Verify if the user is valid
     * @param usr:the username
     * @param pwd: password
     */
    bool signUp(string usr, string pwd);
    /**
     * @brief Login::close
     *Close the login
     */
    void close();

    int getUserId(string usrname);
private:
    std:: string username;
    std::string password;

};

#endif // LOGIN_H
