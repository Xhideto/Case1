// Last Modified: 9/26/23
//Might add password tries and lockout?
//PROBLEM: When logging in, it reads the other user's information

#include <iostream>
#include <fstream>
#include "user.h"

void Login::login() {
    std::string username, password;

        User login;
        //get inputs and assign to user object
        std::cout << "\t\t-----LOG IN-----" << std::endl;
        std::cout << "\t\tUsername" << std::endl;
        std::cin >> username;
        std::cout << std::endl;
        std::cout << "\t\tPassword" << std::endl;
        std::cin >> password;
        std::cout << std::endl;

        bool found = false;

    // File input to read the user's information
        std::ifstream ULogin("UserFiles.txt");
        while (ULogin >> login.uname >> login.pass >> login.lname >> login.fname >> login.phone >> login.email) {
            if (username == login.uname && password == login.pass) {
                std::cout << "\t\tSuccessfully Login" << std::endl;
                std::cout << "Name: " << login.lname << ", " << login.fname << std::endl;
                std::cout << "Phone Number: " << login.phone << std::endl;
                std::cout << "Email Address: " << login.email << std::endl;
                found = true;
                break;
            }
        }

        if (!found) {
            std::cout << "\t\tCheck again your username & password" << std::endl;
        }
        ULogin.close();
    }