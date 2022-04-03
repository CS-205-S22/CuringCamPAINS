#ifndef LOGIN_H
#define LOGIN_H
#include "database.h"

class Login
{
public:
    Login();
    void getUserNameInput();
    void getPasswordInput();
    void signUp();
    void validateAccount();
private:
    std:: string username;
    std::string password;

};

#endif // LOGIN_H
