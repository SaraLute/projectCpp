#include "deliveryMen.h"
#include <cmath>
#include <algorithm>    //used for transform and min_element

//"deliveryMen.cpp" file containing all the setter functions
deliveryMen::deliveryMen() = default;
deliveryMen::~deliveryMen() = default;

//Local function that calculates the square of each of the elements of a given vector
std::vector<int> square(std::vector<int> diff) {
    int size = 14;
    for (int i = 0; i < size; ++i) {
        diff[i] *= diff[i];
    }
    return diff;
}
//Local function that calculates the sum of the 1st and 2nd, 3rd and 4th, 5th and 6th, etc element of a given vector
std::vector<int> sumed(std::vector<int> sqrs) {
    std::vector<int> sqrsee;
    for (int i = 0; i<sqrs.size(); i+=2) {
        sqrsee.push_back(sqrs[i] + sqrs[i+1]);
    }
    return sqrsee;
}
//Local function that calculates the square root of a given vector
std::vector<double> squarerooted(std::vector<int> sumed) {
    std::vector<double> sqroot;
    sqroot.reserve(sumed.size());       //pre-allocation
    for (int i : sumed) {
        sqroot.push_back(sqrt(i));
    }
    return sqroot;
}

//setDelIndex takes the coordinates from getResCoordinates (newOrder) and with the use of several functions it
// calculates the lowest distance between the restaurant location and the locations of the deliveryMen
int deliveryMen::setDelIndex(std::vector<int> restLocation) {
    std::vector<int> difference;
    for (int i = 0; i < 7; ++i) {
        std::vector<int> DMLocation = {x_del[i], y_del[i]};
        std::transform(restLocation.begin(), restLocation.end(), DMLocation.begin(), std::back_inserter(difference), [&](int l, int r) {
            return std::abs(l - r); });
    }
    std::vector<int> squarese = square(difference);
    std::vector<int> sumede = sumed(squarese);
    std::vector<double> distance = squarerooted(sumede);
    delIndex = std::min_element(distance.begin(),distance.end()) - distance.begin();
    return delIndex;
}

//setClosestDel takes the integer index of the closest deliveryMen calculated in setDelIndex and returns the
// corresponding name.
std::string deliveryMen::setClosestDel(int minElemIndex) {
    closestDelName = deliveryJoe[minElemIndex];
    return closestDelName;
}

//setDelCoordinates takes the integer index of the closest deliveryMen calculated in setDelIndex and returns the
// corresponding coordinates.
std::vector<int> deliveryMen::setDelCoordinates(int minElmIndx) {
    delCoordinates = {x_del[minElmIndx-1], y_del[minElmIndx-1]};
    return delCoordinates;
}