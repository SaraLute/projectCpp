#include "deliveryMen.h"
#include <cmath>
#include <numeric>

std::vector<int> deliveryMen::setDelCoordinates(int x) {
    delCoordinates = {x_del[x-1], y_del[x-1]};
    return delCoordinates;
}

std::vector<int> square(std::vector<int> diff) {
    int size = sizeof(diff)/sizeof(diff[0]);
    for (int i = 0; i < size; ++i) {
        diff[i] *= diff[i];
    }
    return diff;
}

std::string deliveryMen::closestDel(std::vector<int> restLocation) {
    for (int i = 0; i < 7; ++i) {
        std::vector<int> DMLocation = {x_del[i], y_del[i]};
        std::vector<int> difference;
        std::set_difference(DMLocation.begin(), DMLocation.end(), restLocation.begin(), restLocation.end(), std::back_inserter(difference));
        std::vector<int> squarese = square(difference);
        int sum = std::accumulate(squarese.begin(), squarese.end(),decltype(squarese)::value_type(0));
        distance[i]=sqrt(sum);
        minElementIndex = std::min_element(distance.begin(),distance.end()) - distance.begin();
    }
    return deliveryJoe[minElementIndex];
}


