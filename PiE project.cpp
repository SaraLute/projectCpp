// PiE project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "trackDelivery.h"
#include "userData.h"
#include "newOrder.h"
#include "deliveryMen.h"

int main()
{
	userData one;                                                                                                                               //Object to invoke customer information
	newOrder two;                                                                                                                               //Object to invoke order infomration
    deliveryMen three;                                                                                                                          //Object to initialize Deliveryman
	
    //Temporary variables declared for exchanging coordinates between User information and Delivery tracking
    std::vector<int> cust, res, dm;                                                                                                             // temporary variables to store inputs from user
    int x0, y0, x1, x2, y1, y2;                                                                                                                 // temporary variables to pass input from user as X,Y coordinates to trackDelivery
    char action;                                                                                                                                // variable to store action for switch case/ response from user

	std::cout << "Hello, and welcome to this food ordering system." << std::endl;
    std::cout << "Do you have an account? [Y|N] " << std::endl;
    std::cin >> action;

    // The action stored in 'action' is used in this switch to either make an account first or to go directly
    // to placing the order. After the account is setup with the order attached, it is send on to pick the nearest
    // deliveryman and then into the TrackDelivery script.

    switch (action) {
    case 'N':

        char action2;                                                                                                                               // action variable for the nested switch case
        one.addressBook();
        one.setName();
        one.setAddress();

        // Extract Customer's location - use functions from userData
        cust = one.setDesCoordinates(one.getAddress());
        x0 = cust.at(0);                                                                                                                            // X coordinate of user's location
        y0 = cust.at(1);                                                                                                                            // Y coordinate of user's location

        std::cout << "Thanks for signing up!" << std::endl;
        std::cout << "Do you want to order now? [Y|N] " << std::endl;
        std::cin >> action2;
        switch (action2) {
        case 'Y':
            std::cout << "Then let's go get your order!" << std::endl;
            two.menuCard();
            two.restaurantDec();
            two.itemDec(two.getTempRes());
            two.setRestaurant(two.getTempRes());
            two.setResCoordinates(two.getTempRes());

            // Extract Restaurant location use functions from newOrder
            res = two.getResCoordinates();
            x1 = res.at(0);                                                                                                                           // X coordinate of restaurant's location
            y1 = res.at(1);                                                                                                                           // Y coordinate of restaurant's location

            // Extract Delivery location use functions from deliveryMen
            dm = three.setDelCoordinates(three.setDelIndex(res));
            x2 = dm.at(0);                                                                                                                            // X coordinate of delivery person's location
            y2 = dm.at(1);                                                                                                                            // Y coordinate of delivery person's location

            break;
        case 'N':
            std::cout << "Thanks for visiting the system, goodbye!" << std::endl;
            break;
        default:
            std::cout << "This is not an option..." << std::endl;
        }
        break;
    case 'Y':

        // Extract Customer's location - brute force given/constant address -use functions from userData
        cust = one.setDesCoordinates(one.getAddress());
        x0 = cust.at(0);
        y0 = cust.at(1);

        std::cout << "Then let's go get your order!" << std::endl;
        two.menuCard();
        two.restaurantDec();
        two.itemDec(two.getTempRes());
        two.setRestaurant(two.getTempRes());
        two.setResCoordinates(two.getTempRes());

        // Extract Restaurant location - use functions from newOrder
        res = two.getResCoordinates();
        x1 = res.at(0);
        y1 = res.at(1);

        // Extract Delivery location - use functions from deliveryMen
        dm = three.setDelCoordinates(three.setDelIndex(res));
        x2 = dm.at(0);
        y2 = dm.at(1);

        break;
    default:
        std::cout << "This is not an option..." << std::endl;
    }



	///		TRACKING PROCESS BEGING HERE 
	/// 
	
	std::cout << "Let us initiate the delivery process : " << std::endl;
	
	trackDelivery DM2Restaurant(0, x2, y2, x1, y1);                                                                                                     // Calling trackDelivery object to initialize delivery process to pick up from restuarant

    trackDelivery Restaurant2Customer(1, x1, y1, x0, y0);	                                                                                            // Calling trackDelivery object to conclude delivery process to delivery at customer address

    std::cout << "Eet smaakelijk" << std::endl;
	return 0;
    
}

