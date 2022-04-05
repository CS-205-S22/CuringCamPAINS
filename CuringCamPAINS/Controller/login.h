#ifndef LOGIN_H
#define LOGIN_H
#include "database.h"

class Login:public Database
{
public:
    Login(std::string name);
    void getUserNameInput();
    void getPasswordInput();
    void signUp();
    void validateAccount();
    void signUp(string usr, string pwd);
private:
    std:: string username;
    std::string password;

};

#endif // LOGIN_H
