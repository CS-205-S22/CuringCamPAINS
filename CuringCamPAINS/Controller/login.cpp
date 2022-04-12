#include "login.h"

Login::Login(std::string name):Database (name)
{

}

Login::~Login(){
    curr_db->close();
    curr_db = NULL;
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


bool Login::signUp(string usr, string pwd){
    cout<<usr<<endl;
    cout<<pwd<<endl;
    if(authenticate(QString::fromStdString(usr),QString::fromStdString(pwd))==true){
        cout<<"Login successful"<<endl;
        return true ;
    }
    else {cout<<"Login unsuccessful"<<endl;
        return false;}
}

void Login::close(){

        //std::cerr << "closing object\n";

        curr_db->close();
        curr_db = NULL;
}
