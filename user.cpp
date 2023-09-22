//
// Created by Kujo Jotaro on 17/09/2023
//
#include <iostream>
#include <fstream>
#include <regex>
#include <list>
#include "user.h"

//Registration Function
void Registerr::rgstion()
{
    //Regex and bool variables for password
    bool upper, lower, digit, special;
    bool done = false;
    std::regex upper_case("[A-Z]+");
    std::regex lower_case("[a-z]+");
    std::regex digit_case("[0-9]+");
    std::regex special_case("[!@#$%^&*()_+{}|:<>?]+");
    //string variables
    std::string lname, fname, uname, phone, email, pass;

    //output stream to write data to a file
    std::ofstream UFile("UserFiles.txt", std::ios::app);
    User user;
    //list container for saving a users file
    std::list<User> users;
        //user object
        user.lname = lname;
        user.fname = fname;
        user.uname = uname;
        user.phone = phone;
        user.email = email;
        user.pass = pass;

        //get inputs and assign to user object
        std::cout << "Fill in your information:" << std::endl;
        std::cout << "Last Name: ";
        std::cin >> user.lname;
        std::cout << std::endl;
        std::cout << "First Name: ";
        std::cin >> user.fname;
        std::cout << std::endl;
        std::cout << "Username: ";
        std::cin >> user.uname;
        std::cout << std::endl;
        std::cout << "Contact Number: ";
        std::cin >> user.phone;
        std::cout << std::endl;
        std::cout << "Email Address: ";
        std::cin >> user.email;
        std::cout << std::endl;

        //Using regex function for password
        // Don't know how to hide passwords when inputting as '*'
        do
        {
            std::cout << "Password: ";
            std::getline(std::cin, user.pass);

            if(user.pass.length() < 8)
            {
                std::cout << "Password must be at least 8 characters long." << std::endl;
            }
            else
            {
                upper = std::regex_search(user.pass, upper_case);
                lower = std::regex_search(user.pass, lower_case);
                digit = std::regex_search(user.pass, digit_case);
                special = std::regex_search(user.pass, special_case);

                int pass_valid = upper + lower + digit + special;

                if(pass_valid < 3)
                {
                    std::cout << "Password must contain at least 3 of the following: uppercase, lowercase, digit, special character." << std::endl;
                }
                else
                {
                    std::cout << "Password is valid." << std::endl;
                    done = true;
                }
            }
        }while(!done);

        {
            std::cout << "Confirm Password: ";
            std::getline(std::cin, user.pass);

            if(user.pass != user.pass)
            {
                std::cout << "Passwords do not match." << std::endl;
            }
        }
        //push user to users list
        users.push_back(user);
        //for loop std::list to a file
        for(auto user: users)
        {
            //getting inputs to a file
            UFile << user.lname << "," << user.fname << "," << user.uname << "," << user.phone << "," << user.email << "," << user.pass << std::endl;
        }

        std::cout << "Registered" << std::endl;

}
