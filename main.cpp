#include <iostream>
#include "user.h"

int main()
{
    int choice;
    Registerr reg;
    Login log;

    //Main Menu
    do{
        std::cout << "\t\t   HOTEL" << std::endl;
        std::cout << "\t\t1. Register" << std::endl;
        std::cout << "\t\t2. Login" << std::endl;
        std::cout << "\t\t3. Exit" << std::endl;
        std::cout << "\t\tEnter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
            case 1:
                //Registration
                system("cls");
                reg.rgstion();
                break;

            case 2:
                //login
                system("cls");
                log.login();
                break;

            case 3:
                std::cout << "\t\tThank you for visiting the hotel" << std::endl;
                break;

            default:
                std::cout << "\t\tWrong Input" << std::endl;
                break;
        }
    }
    while(choice != 3);

    return 0;
}
