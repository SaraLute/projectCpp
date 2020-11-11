#ifndef PROJECTCPP_DELIVERYMEN_H
#define PROJECTCPP_DELIVERYMEN_H

#include <vector>
#include <array>
#include <string>
#include "userData.h"

//This is "deliverMen.h" file containing the class deliveryMen. This class contains functions that take the location
// of the restaurant chosen in the newOrder class and calculates the closest delivery person in the system.
//The class returns the index number of the closest delivery person, the coordinates of the closest person and the name
// of the closest delivery person.
//- destination coordinates come from: getDesCoordinates(); (userData)
//- restaurant coordinates come from: getResCoordinates(); (newOrder)
//- delivery man coordinates come from this class: getDelCoordinates();

class deliveryMen {
private:
    std::vector<int> delCoordinates;
    std::string closestDelName;
    int delIndex{};
    std::vector<int> x_del = { 42, 300, 382, 40, 40, 68, 85 };
    std::vector<int> y_del = { 53, 53, 447, 389, 231, 53, 53 };
    std::array<std::string, 7> deliveryJoe = {"Allen", "Bob", "Carol", "Dion", "Edward", "Ferry", "Gosline"};
public:
    deliveryMen();
    ~deliveryMen();

    //Setters
    int setDelIndex(std::vector<int> restLocation);
    std::string setClosestDel(int minElementIndex);
    std::vector<int> setDelCoordinates(int minElementIndex);

    //Getters
    std::vector<int> getDelCoordinates(){
        return delCoordinates;
    }
    int getDelIndex() {
        return delIndex;
    }
    std::string getDeliveryMen() {
        return closestDelName;
    }
};


#endif //PROJECTCPP_DELIVERYMEN_H
