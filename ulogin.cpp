//
// It cannot retrieve the user's information
//

#include <iostream>
#include <fstream>
#include <list>
#include "user.h"

void Login::login()
{
    std::string uname, username, password, pass;
    if (std::ifstream ULogin{"UserLog.txt", std::ios::in}) {

        User login;
        //
        std::list<User> logins;
        //
        login.uname = uname;
        login.pass = pass;

        std::cout << "\t\t-----LOG IN-----" << std::endl;
        std::cout << "\t\tUsername" << std::endl;
        std::cin >> username;
        std::cout << std::endl;
        std::cout << "\t\tPassword" << std::endl;
        std::cin >> password;

        while (ULogin >> login.uname >> login.pass) {
            if (username == login.uname && password == login.pass) {
                std::string fname, lname, phone, email;
                if (std::ifstream Uuser{"UserFiles", std::ios::in}) {

                    login.lname = lname;
                    login.fname = fname;
                    login.phone = phone;
                    login.email = email;

                    while (Uuser >> login.lname >> login.fname >> login.phone >> login.pass) {

                        std::cout << "\t\tSuccessfully Login" << std::endl;
                        std::cout << "Name:" << " ";
                        Uuser >> login.lname;
                        std::cout << ", ";
                        Uuser >> login.fname;
                        std::cout << std::endl;
                        std::cout << "Phone Number:" << " ";
                        Uuser >> login.phone;
                        std::cout << std::endl;
                        std::cout << "Email Address:" << " ";
                        Uuser >> login.email;
                        std::cout << std::endl;
                    }
                } else
                    std::cout << "Cannot open/find the file" << std::endl;
            } else if (login.uname == uname && login.pass != pass) {
                std::cout << "\t\tWrong Password Try again" << std::endl;
                break;
            } else {
                std::cout << "\t\tCheck again your username & password" << std::endl;
                break;
            }
        }
    }
    else
        std::cout << "\t\tFile not found" << std::endl;
}
