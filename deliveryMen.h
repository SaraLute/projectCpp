#ifndef PROJECTCPP_DELIVERYMEN_H
#define PROJECTCPP_DELIVERYMEN_H

#include <vector>
#include <array>
#include <string>
// uses the location of the restaurants, delivery man itself and the destination
// destination coordinates come from: getDesCoordinates();
// restaurant coordinates come from: getResCoordinates();
// delivery man coordinates come from this class: getDelCoordinates();

class deliveryMen {
private:
    std::vector<int> delCoordinates;
    std::vector<int> distance;
    int minElementIndex;
    std::vector<int> x_del = {43, 301, 383, 41, 41, 69, 86};
    std::vector<int> y_del = {54, 54, 448, 390, 232, 54, 54};
    std::array<std::string, 7> deliveryJoe = {"Allen", "Bob", "Carol", "Dion", "Edward", "Ferry", "Gosline"};
public:
    std::string closestDel(std::vector<int> restLocation);
    std::vector<int> setDelCoordinates(int minElementIndex);

    std::vector<int> getDelCoordinates(){
        return delCoordinates;
    }
    std::string getDeliveryMen() {
        return deliveryJoe[minElementIndex];
    }
};


#endif //PROJECTCPP_DELIVERYMEN_H
