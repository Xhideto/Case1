// Last Modified: 9/26/23
//Might add password tries and lockout?
//PROBLEM: When logging in, it reads the other user's information

#include <iostream>
#include <fstream>
#include "user.h"

void Login::login() {
    std::string uname, pass, username, password;

    if (std::ifstream ULogin{"UserLog.txt", std::ios::in}) {

        User login;

        std::cout << "\t\t-----LOG IN-----" << std::endl;
        std::cout << "\t\tUsername" << std::endl;
        std::cin >> username;
        std::cout << std::endl;
        std::cout << "\t\tPassword" << std::endl;
        std::cin >> password;
        std::cout << std::endl;

        bool found = false;

        while (ULogin >> login.uname >> login.pass) {
            // File input to read the user's information
            if (username == login.uname && password == login.pass) {
                found = true;
                std::ifstream Uuser("UserFiles.txt", std::ios::in);

                std::string fname, lname, phone, email;

                while (Uuser >> lname >> fname >> phone >> email) {
                    std::cout << "\t\tSuccessfully Login" << std::endl;
                    std::cout << "Name: " << lname << ", " << fname << std::endl;
                    std::cout << "Phone Number: " << phone << std::endl;
                    std::cout << "Email Address: " << email << std::endl;
                }
                Uuser.close();
                break;
            }
        }

        if (!found) {
            std::cout << "\t\tCheck again your username & password" << std::endl;
        }

        ULogin.close();
    } else {
        std::cout << "\t\tFile not found" << std::endl;
    }
}