#include <iostream>
#include <vector>
#include <array>
#include "newOrder.h"

//"newOrder.cpp" file containing all the setter functions
newOrder::newOrder()= default;
newOrder::~newOrder()= default;

//restaurantDec requests user input on what restaurant the user wants and returns the index number of this restaurant.
int newOrder::restaurantDec() {
    std::cout << "Let's order!" << std::endl << "Pick one of the available restaurants: " << std::endl;
    std::cout << "(1)Sushi place, (2)Pizza place, (3)Thai place, (4)Burger place or (5)Expensive place" << std::endl;
    std::array<std::string, 5> decisionRes = {"Sushi place", "Pizza place", "Thai place", "Burger place", "Expensive place"};
    std::cin >> tempRes;
    restaurant = decisionRes[tempRes-1];
    std::cout << "You chose : " << restaurant << "! " << std::endl;
    return tempRes;
}

//itemDec takes the chosen restaurant index number and shows the corresponding menu, from which the user can pick their preferred items.
std::vector<int> newOrder::itemDec(int tempRs) {
    if (tempRes==1) {
        int tempItem=1;
        std::cout << "Pick your menu items: " << std::endl;
        std::cout << "(1)salmon roll, (2)ebi roll, (3)tuna sashimi, (4)edame beans, (5)grilled veggies, (6)noodles or (7)tomato soup' (0 to end)" << std::endl;
        std::cout << "Type the item number and press enter, type 0 and enter to finish." << std::endl;
        while (tempItem) {
            std::cin >> tempItem;
            items.push_back(tempItem);
        }
        std::array<std::string,7> sushiItems = {"salmon roll", "ebi roll", "tuna sashimi", "edame beans", "grilled veggies", "noodles", "tomato soup"};
        std::cout << "These are the items you have ordered: " << std::endl;
        for (int i: items)
            std::cout << sushiItems[i] << "\n";

    } else if (tempRes==2) {
        int tempInt=1;
        std::cout << "Pick your menu items: " << std::endl;
        std::cout << "(1)margarita, (2)mozzarella or (3)hawaii (0 to end)" << std::endl;
        std::cout << "Type the item number and press enter, type 0 and enter to finish." << std::endl;
        while (tempInt) {
            std::cin >> tempInt;
            items.push_back(tempInt);
        }
        std::array<std::string,7> pizzaItems = {"Thanks!", "margarita", "mozarella", "hawaii"};
        std::cout << "These are the items you have ordered: " << std::endl;
        for (int i: items)
            std::cout << pizzaItems[i] << "\n";

    } else if (tempRes==3) {
        int tempInt=1;
        std::cout << "Pick your menu items: " << std::endl;
        std::cout << "(1)thai menu 1, (2)thai menu 2 or (3)thai menu 3 (0 to end)" << std::endl;
        std::cout << "Type the item number and press enter, type 0 and enter to finish." << std::endl;
        while (tempInt) {
            std::cin >> tempInt;
            items.push_back(tempInt);
        }
        std::array<std::string,7> thaiItems = {"Thanks!","thai menu 1", "thai menu 2", "thai menu 3"};
        std::cout << "These are the items you have ordered: " << std::endl;
        for (int i: items)
            std::cout << thaiItems[i] << "\n";

    } else if (tempRes==4) {
        int tempInt=1;
        std::cout << "Pick your menu items: " << std::endl;
        std::cout << "(1)hamburger, (2)cheeseburger and/or (3)fries (0 to end)" << std::endl;
        std::cout << "Type the item number and press enter, type 0 and enter to finish." << std::endl;
        while (tempInt) {
            std::cin >> tempInt;
            items.push_back(tempInt);
        }
        std::array<std::string,7> burgerItems = {"Thanks!","hamburger", "cheeseburger", "fries"};
        std::cout << "These are the items you have ordered: " << std::endl;
        for (int i: items)
            std::cout << burgerItems[i] << "\n";

    } else if (tempRes==5) {
        int tempInt=1;
        std::cout << "Pick your menu items: " << std::endl;
        std::cout << "(1)truffle risotto, (2)entrecote with aubergine tartar and/or (3)vegan option (0 to end)" << std::endl;
        std::cout << "Type the item number and press enter, type 0 and enter to finish." << std::endl;
        while (tempInt) {
            std::cin >> tempInt;
            items.push_back(tempInt);
        }
        std::array<std::string,7> expensiveItems = {"Thanks!","truffle risotto", "entrecote with aubergine tartar", "vegan option"};
        std::cout << "These are the items you have ordered: " << std::endl;
        for (int i: items)
            std::cout << expensiveItems[i] << "\n";
    } else {

    }
return items;
}

//setRestaurant takes the chosen restaurant index number and returns the name of the restaurant.
std::string newOrder::setRestaurant(int tempRst) {
    std::array<std::string, 5> decisionRes = {"Sushi place", "Pizza place", "Thai place", "Burger place", "Expensive place"};
    restaurant = decisionRes[tempRes];
    return restaurant;
}

//setResCoordinates takes the chosen restaurant index number and returns the corresponding coordinates of the chosen restaurant.
std::vector<int> newOrder::setResCoordinates(int tempRstr) {
    std::vector<int> x_res = {640, 627, 486, 751, 678};
    std::vector<int> y_res = {523, 743, 523, 545, 523};
    resCoordinates = {x_res[tempRes-1], y_res[tempRes-1]};
    return resCoordinates;
}

//menuCard is a void that simply outputs and introduction/explanation to the user on the menu.
void newOrder::menuCard() {
    std::cout << "\n**********************************************" << std::endl;
    std::cout << "  WELCOME to the menu's that are available" << std::endl;
    std::cout << "You will first be asked to pick a restaurant" << std::endl;
    std::cout << "and after you can pick the items you'd like!" << std::endl;
    std::cout << "**********************************************" << std::endl;
}
