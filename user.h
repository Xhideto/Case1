//
// Created by Kujo Jotaro on 17/09/2023.
//

#ifndef CASE_USER_H
#define CASE_USER_H

#include <iostream>

class User
{
public:
    User(){}
    User(std::string lname, std::string fname, std::string uname, std::string phone, std::string email, std::string pass):
    lname(lname), fname(fname), uname(uname), phone(phone), email(email), pass(pass) {}

    std::string lname;
    std::string fname;
    std::string uname;
    std::string phone;
    std::string email;
    std::string pass;

};

class Registerr
{
public:
    Registerr() {}
    void rgstion();
};


#endif //CASE_USER_H
