// Last Modified: 9/26/23
//Might add password tries and lockout?
//PROBLEM: When logging in, it reads the other user's information

#include <iostream>
#include <fstream>
#include "user.h"

void Login::login() {
    std::string uname, pass, username, password;
    //file input to read data for login
    if (std::ifstream ULogin{"UserLog.txt", std::ios::in}) {

        User login;
        //login user object
        login.uname = uname;
        login.pass = pass;

        //get inputs for login
        std::cout << "\t\t-----LOG IN-----" << std::endl;
        std::cout << "\t\tUsername" << std::endl;
        std::cin >> username;
        std::cout << std::endl;
        std::cout << "\t\tPassword" << std::endl;
        std::cin >> password;
        std::cout << std::endl;

        while (ULogin >> login.uname >> login.pass) {
            //file input to read the user's information
            if (username == login.uname && password == login.pass) {
                std::ifstream Uuser("UserFiles.txt", std::ios::in);

                    std::string fname, lname, phone, email;

                    login.lname = lname;
                    login.fname = fname;
                    login.phone = phone;
                    login.email = email;

                    while(Uuser >> login.lname >> login.fname >> login.phone >> login.email) {
                        std::cout << "\t\tSuccessfully Login" << std::endl;
                        std::cout << "Name: " << login.lname << ", " << login.fname << std::endl;
                        std::cout << "Phone Number: " << login.phone << std::endl;
                        std::cout << "Email Address: " << login.email << std::endl;
                    }
            } else if (login.uname == uname && login.pass != pass) {
                std::cout << "\t\tWrong Password Try again" << std::endl;
            } else {
                std::cout << "\t\tCheck again your username & password" << std::endl;
            }
        }
    } else
        std::cout << "\t\tFile not found" << std::endl;

}