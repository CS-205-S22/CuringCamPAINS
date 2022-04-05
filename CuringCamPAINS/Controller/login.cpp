#include "login.h"

Login::Login(std::string name):Database (name)
{

}
void Login::getUserNameInput(){
    cout<<"Enter username: ";
    cin >> username; // Get user input from the keyboard
}


void Login::getPasswordInput(){
    cout<<"Enter password: ";
    cin >> password; // Get user input from the keyboard
}

void Login::signUp(){
    if(authenticate(QString::fromStdString(username),QString::fromStdString(password))==true){
            cout<<"Login successful"<<endl;
            return ;
}
    else {cout<<"Login unsuccessful"<<endl;}
}


void Login::signUp(string usr, string pwd){
    if(authenticate(QString::fromStdString(usr),QString::fromStdString(pwd))==true){
            cout<<"Login successful"<<endl;
            return ;
}
    else {cout<<"Login unsuccessful"<<endl;}
}
