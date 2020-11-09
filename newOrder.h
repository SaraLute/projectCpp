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
    int tempRes{};
public:
    newOrder();
    ~newOrder();

    int restaurantDec();
    std::vector<int> itemDec(int tempRes);
    std::string setRestaurant(int tempRes);

    static void menuCard();

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