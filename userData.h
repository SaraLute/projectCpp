#ifndef PROJECTCPP_USERDATA_H
#define PROJECTCPP_USERDATA_H

#include <iostream>
#include "newOrder.h"

//This is "userData.h" file containing the class userData. This class contains functions that create a user with name,
// address and the corresponding coordinates.
//The class returns the name, address and coordinates of the destination of an order aka the person who ordered.
class userData {
private:
    std::string fullName;
    std::string address = "Molenstraat 5";
    std::vector<int> coordinates;

public:
    userData();
    ~userData();

    //Setters
    std::string setName();
    std::string setAddress();
    std::vector<int> setDesCoordinates(const std::string& addrss);
    void addressBook();

    //Getters
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