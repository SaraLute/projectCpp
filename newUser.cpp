//
// Created by Sara Lute on 01/11/2020.
//

#include <string>
#include <iostream>
#include <vector>
#include "newUser.h"

// newUser requests user input on account information
// Input dialogbox prompting for name and addres of user. And storing said input in variable newInput. (transposed to save in a structure)

struct order {
    std::string restaurant;
    std::vector<char> items;
};

struct userType {
    std::string name;
    std::string address;
    struct order newOrder;

};

userType input() {
    userType newUser;
    std::cout << "\n Please enter your user information: \n";

    std::cout << "\n Full name: ";
    std::cin >> newUser.name;

    std::cout << "\n Address: ";
    std::cin >> newUser.address;


    // newUser.newOrder = getOrder();

    return newUser;
}

int main() {
    userType u;
    u = input();
    std::cout <<"\n========"<< std::endl << "Collected the details of "
         << u.name << std::endl;

    return 0;
}