#include <iostream>
#include "user.h"


int main()
{
    int choice;
    Registerr reg;

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
                /* code */
                reg.rgstion();
                break;

            case 2:
                break;

            case 3:
                std::cout << "\t\tThank you for visiting the hotel" << std::endl;
                /* code */
                break;

            default:
                std::cout << "\t\tWrong Input" << std::endl;
                break;
        }
    }
    while(choice != 3);

    return 0;
}
