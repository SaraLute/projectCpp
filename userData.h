#ifndef PROJECTCPP_USERDATA_H
#define PROJECTCPP_USERDATA_H

#include <iostream>
#include "newOrder.h"


class userData {
private:
    std::string fullName;
    std::string address;
    std::vector<int> coordinates;

public:
    userData();
    ~userData();

    std::string setName();
    std::string setAddress();
    std::vector<int> setCoordinates(const std::string& address);

    std::string getName(){
        return fullName;
    }
    std::string getAddress() {
        return address;
    }
    std::vector<int> getCoordinates(){
        return coordinates;
    }
};


#endif //PROJECTCPP_USERDATA_H