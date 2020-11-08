#include <string>
#include <iostream>
#include <vector>
#include "userData.h"

using namespace std;

userData::userData() {
    setName();
    setAddress();
    setCoordinates(address);
}

userData::~userData() {
    //can stay empty i think???
}

std::vector<int> userData::setCoordinates(std::string addr) {
    std::vector<int> x_des = {836, 1040, 1186, 1186, 822, 1186, 1186, 993, 1186, 822, 945, 1186, 1186, 1186, 1122, 822};
    std::vector<int> y_des = {447, 53, 383, 394, 291, 403, 383, 53, 145, 268, 53, 320, 132, 386, 447, 107};
    bool found = false;
    fstream addressbook;
    addressbook.open ("addressbook.txt");
    unsigned int curLine = 0;
    if (addressbook.is_open()) {
        std::string line;
        while(getline(addressbook, line)) { // I changed this, see below
            curLine++;
            if (line.find(addr, 0) != string::npos) {
                // cout << "found: " << addr << " in line: " << curLine << endl;
                found = true;
                coordinates = {x_des[curLine-1], y_des[curLine-1]};
            }
        }
        addressbook.close();
    } else {
        cerr << "Unable to open addressbook.txt" << endl;
        exit(1);    //call system to stop
    }
    for (auto& i: coordinates)
        std::cout << i << ' ';
    return coordinates;
}

std::string userData::setAddress() {
    std::cout << "\n Please enter your address: ";
    std::cin >> address;
    return address;
}

std::string userData::setName() {
    std::cout << "\n Please enter your name: ";
    std::cin >> fullName;
    return fullName;
}


