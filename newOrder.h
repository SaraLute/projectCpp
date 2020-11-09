#ifndef PROJECTCPP_NEWORDER_H
#define PROJECTCPP_NEWORDER_H

#include <iostream>
#include <fstream>
#include <vector>
#include "userData.h"


class newOrder {
private:
    std::string restaurant;
    std::vector<int> items;
    std::vector<int> resCoordinates;
    int tempRes{};
public:
    newOrder();
    ~newOrder();

    int restaurantDec();
    std::vector<int> itemDec(int tempRes);
    std::string setRestaurant(int tempRes);
    std::vector<int> setResCoordinates(int tempRes);


    static void menuCard();

    std::vector<int> getResCoordinates(){
        return resCoordinates;
    }
    int getTempRes(){
        return tempRes;
    }
    std::string getRestaurant(){
        return restaurant;
    }
    std::vector<int> getItems(){
        return items;
    }
};

#endif //PROJECTCPP_NEWORDER_H