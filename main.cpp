#include "userData.h"
#include "newOrder.h"
#include "deliveryMen.h"

int main() {
    userData one;
    newOrder two;
    deliveryMen three;

    std::cout << "Hello, and welcome to this food ordering system." << std::endl;
    std::cout << "Do you have an account? [Y|N] " << std::endl;
    char action;
    std::cin >> action;

    // The action stored in 'action' is used in this switch to either make an account first or to go directly
    // to placing the order. After the account is setup with the order attached, it is send on to pick the nearest
    // deliveryman and then into the TrackDelivery script.

    switch (action) {
        case 'N' :
            one.addressBook();
            one.setName();
            one.setAddress();
            one.setDesCoordinates(one.getAddress());

            std::cout << "Thanks for signing up!" << std::endl;
            std::cout << "Do you want to order now? [Y|N] " << std::endl;
            char action2;
            std::cin >> action2;
            switch (action2) {
                case 'Y' :
                    std::cout << "Then let's go get your order!" << std::endl;
                    two.menuCard();
                    two.restaurantDec();
                    two.itemDec(two.getTempRes());
                    two.setRestaurant(two.getTempRes());
                    three.setDelIndex(two.getResCoordinates());
                    three.setDelCoordinates(three.getDelIndex());
                    three.setClosestDel(three.getDelIndex());           //not used if the name of the closest deliverymen isn't asked through getter here.
                    goto t;
                case 'N' :
                    std::cout << "Thanks for visiting the system, goodbye!" << std::endl;
                    break;
                default:
                    std::cout << "This is not an option..." << std::endl;
            }
            break;
        case 'Y' :
            std::cout << "Then let's go get your order!" << std::endl;
            two.menuCard();
            two.restaurantDec();
            two.itemDec(two.getTempRes());
            two.setRestaurant(two.getTempRes());
            three.setDelIndex(two.getResCoordinates());
            three.setDelCoordinates(three.getDelIndex());
            three.setClosestDel(three.getDelIndex());           //not used if the name of the closest deliverymen isn't asked through getter here.
            goto t;
        default:
            std::cout << "This is not an option..." << std::endl;
    }

    t:      //jump to here from "goto t;", so implement trackDelivery here
         std::cout << "Let us initiate the delivery process : " << std::endl;
         //Calling trackDelivery object to initialize delivery process to pick up from restaurant
         // trackDelivery DM2Restaurant(0, 1, 1);

         //Calling trackDelivery object to conclude delivery process to delivery at customer address
         // trackDelivery Restaurant2Customer(1, 2, 4);

         //To get the input values you need use the getters. As i send over WhatsApp, i can't declare variables in a switch

    return 0;
}