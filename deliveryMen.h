#ifndef PROJECTCPP_DELIVERYMEN_H
#define PROJECTCPP_DELIVERYMEN_H

#include <vector>
#include <array>
#include <string>
#include <algorithm>
//#include <cctype>
#include "userData.h"
// uses the location of the restaurants, delivery man itself and the destination
// destination coordinates come from: getDesCoordinates();
// restaurant coordinates come from: getResCoordinates();
// delivery man coordinates come from this class: getDelCoordinates();

class deliveryMen {
private:
    std::vector<int> delCoordinates;
    std::string closestDelName;
    int delIndex;
    std::vector<int> x_del = {42, 300, 382, 40, 40, 68, 85};
    std::vector<int> y_del = {53, 53, 447, 389, 231, 53, 53};
    std::array<std::string, 7> deliveryJoe = {"Allen", "Bob", "Carol", "Dion", "Edward", "Ferry", "Gosline"};
public:
    deliveryMen();
    ~deliveryMen();

    std::string setClosestDel(int minElementIndex);
    std::vector<int> setDelCoordinates(int minElementIndex);
    int setDelIndex(std::vector<int> restLocation);

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
