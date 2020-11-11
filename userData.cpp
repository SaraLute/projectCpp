#include <string>
#include <iostream>
#include <vector>
#include "userData.h"

using namespace std;

userData::userData() = default;

userData::~userData() = default;

std::vector<int> userData::setDesCoordinates(const std::string& address) {
    std::vector<int> x_des = {835, 1039, 1185, 1185, 821, 1185, 1185, 992, 1185, 821, 944, 1185, 1185, 1185, 1121, 821};
    std::vector<int> y_des = {446, 52, 382, 393, 290, 402, 382, 52, 144, 267, 52, 319, 131, 385, 446, 106};
    bool found = false;
    fstream addressbook;
    addressbook.open ("addressbook.txt");
    unsigned int curLine = 0;
    if (addressbook.is_open()) {
        std::string line;
        while(getline(addressbook, line)) {
            curLine++;
            if (line.find(address, 0) != string::npos) {
                found = true;
                coordinates = {x_des[curLine-1], y_des[curLine-1]};
            }
        }
        addressbook.close();
    } else {
        cerr << "Unable to open addressbook.txt" << endl;
        exit(1);    //call system to stop
    }
    return coordinates;
}

std::string userData::setAddress() {
    std::cout << "\n Please enter your address: ";
    getline(cin >> ws, address);        // cin always considers spaces as terminating the value being extracted, and thus extracting a string means to always extract a single word, not a phrase or an entire sentence.
    // cout << address << endl;                   ws consumes whitespace from an input stream
    return address;
}

std::string userData::setName() {
    std::cout << "\n Please enter your name: ";
    getline(cin >> ws, fullName);
    return fullName;
}

void userData::addressBook() {
    std::cout << "**********************************************************" << std::endl;
    std::cout << "         WELCOME to this food ordering system" << std::endl;
    std::cout << "We hope you will be able to find the food you like!" << std::endl;
    std::cout << "\nIMPORTANT we only deliver on the following addresses: " << std::endl;
    std::cout << "      Oldenzaalsestraat 1-4, Molenstraat 5-8, \n       Kuipersdijk 9-12 and Hengelosestraat 13-16" << std::endl;
    std::cout << "Make sure you live in one of these addresses!" << endl;
    std::cout << "**********************************************************" << std::endl;
}


