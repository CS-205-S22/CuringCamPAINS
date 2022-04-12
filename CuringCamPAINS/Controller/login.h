#ifndef LOGIN_H
#define LOGIN_H
#include "database.h"

class Login:public Database
{
public:
    Login(std::string name);
    ~Login();
    void getUserNameInput();
    void getPasswordInput();
    void signUp();
    void validateAccount();
    bool signUp(string usr, string pwd);
    void close();
private:
    std:: string username;
    std::string password;

};

#endif // LOGIN_H
