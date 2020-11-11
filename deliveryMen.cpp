#include "deliveryMen.h"
#include <cmath>
#include <numeric>

deliveryMen::deliveryMen() = default;

deliveryMen::~deliveryMen() = default;

std::vector<int> deliveryMen::setDelCoordinates(int x) {
    delCoordinates = {x_del[x-1], y_del[x-1]};
    return delCoordinates;
}

std::vector<int> square(std::vector<int> diff) {
    int size = 14;
    for (int i = 0; i < size; ++i) {
        diff[i] *= diff[i];
    }
    return diff;
}

std::vector<int> sumed(std::vector<int> sqrs) {
    std::vector<int> sqrsee;
    for (int i = 0; i<sqrs.size(); i+=2) {
        sqrsee.push_back(sqrs[i] + sqrs[i+1]);
    }
    return sqrsee;
}
std::vector<double> squarerooted(std::vector<int> sumed) {
    std::vector<double> sqroot;
    sqroot.reserve(sumed.size());       //pre-allocation
    for (int i : sumed) {
        sqroot.push_back(sqrt(i));
    }
    return sqroot;
}

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


std::string deliveryMen::setClosestDel(int minElemIndex) {
    closestDelName = deliveryJoe[minElemIndex];
    return closestDelName;
}
