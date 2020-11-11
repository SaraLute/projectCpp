#ifndef PROJECTCPP_USERDATA_H
#define PROJECTCPP_USERDATA_H

#include <iostream>
#include "newOrder.h"


class userData {
private:
    std::string fullName;
    std::string address = "Oldenzaalsestraat 1";
    std::vector<int> coordinates;

public:
    userData();
    ~userData();

    std::string setName();
    std::string setAddress();
    std::vector<int> setDesCoordinates(const std::string& address);
    void addressBook();

    std::string getName(){
        return fullName;
    }
    std::string getAddress() {
        return address;
    }
    std::vector<int> getDesCoordinates(){
        return coordinates;
    }
};


#endif //PROJECTCPP_USERDATA_H