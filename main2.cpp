// PiE project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "trackDelivery.h"
#include "userData.h"
#include "newOrder.h"
#include "deliveryMen.h"

using namespace cv;
using namespace std;

int main()
{
	userData one;                                                                                                                               //Object to invoke customer information
	newOrder two;                                                                                                                               //Object to invoke order infomration
    deliveryMen three;                                                                                                                          //Object to initialize Deliveryman
	
    //temporary variables
    std::vector<int> cust, res, dm;
    int x0, y0, x1, x2, y1, y2;

	std::cout << "Hello, and welcome to this food ordering system." << std::endl;

	///// SWITCH FROM SARA'S CODE
 
    std::cout << "Do you have an account? [Y|N] " << std::endl;
    char action;
    std::cin >> action;

    // The action stored in 'action' is used in this switch to either make an account first or to go directly
    // to placing the order. After the account is setup with the order attached, it is send on to pick the nearest
    // deliveryman and then into the TrackDelivery script.

    switch (action) {
    case 'N':
        one.addressBook();
        one.setName();
        one.setAddress();

        // Extract Customer's location
        cust = one.setDesCoordinates(one.getAddress());
        x0 = cust.at(0);
        y0 = cust.at(1);
        std::cout << "Customer's location are X:  " << x0 << " and Y: " << y0 << std::endl;


        std::cout << "Thanks for signing up!" << std::endl;
        std::cout << "Do you want to order now? [Y|N] " << std::endl;
        char action2;
        std::cin >> action2;
        switch (action2) {
        case 'Y':
            std::cout << "Then let's go get your order!" << std::endl;
            two.menuCard();
            two.restaurantDec();
            two.itemDec(two.getTempRes());
            two.setRestaurant(two.getTempRes());
            two.setResCoordinates(two.getTempRes());

            // Extract Restaurant location
            res = two.getResCoordinates();
            x1 = res.at(0);
            y1 = res.at(1);
            std::cout << "Restaurant location are X:  " << x1 << " and Y: " << y1 << std::endl;

            // Extract Delivery location
            dm = three.setDelCoordinates(three.setDelIndex(res));
            x2 = dm.at(0);
            y2 = dm.at(1);
            std::cout << "Delivery person's location are X:  " << x2 << " and Y: " << y2 << std::endl;

            //deliveryMen
            //TrackDelivery
            break;
        case 'N':
            std::cout << "Thanks for visiting the system, goodbye!" << std::endl;
            break;
        default:
            std::cout << "This is not an option..." << std::endl;
        }
        break;
    case 'Y':

        // Extract Customer's location - brute force given/constant address
        cust = one.setDesCoordinates(one.getAddress());
        x0 = cust.at(0);
        y0 = cust.at(1);
        std::cout << "Customer's location are X:  " << x0 << " and Y: " << y0 << std::endl;

        std::cout << "Then let's go get your order!" << std::endl;
        two.menuCard();
        two.restaurantDec();
        two.itemDec(two.getTempRes());
        two.setRestaurant(two.getTempRes());
        two.setResCoordinates(two.getTempRes());

        // Extract Restaurant location

        res = two.getResCoordinates();
        x1 = res.at(0);
        y1 = res.at(1);
        std::cout << "Restaurant location are X:  " << x1 <<" and Y: " <<y1<<std::endl;

        // Extract Delivery location
        dm = three.setDelCoordinates(three.setDelIndex(res));
        x2 = dm.at(0);
        y2 = dm.at(1);
        std::cout << "Delivery person's location are X:  " << x2 << " and Y: " << y2 << std::endl;

        // Extract Customer's location
       /* dm = three.setDelCoordinates(three.setDelIndex(res));
        x2 = dm.at(0);
        y2 = dm.at(1);
        std::cout << "Delivery person's location are X:  " << y2 << " and Y: " << y2 << std::endl;*/

        //deliveryMen
        //trackDelivery
        break;
    default:
        std::cout << "This is not an option..." << std::endl;
    }



	///		TRACKING PROCESS BEGING HERE 
	/// 
	
	std::cout << "Let us initiate the delivery process : " << std::endl;
	
	trackDelivery DM2Restaurant(0, x2, y2, x1, y1);                                                                                                     // Calling trackDelivery object to initialize delivery process to pick up from restuarant

    trackDelivery Restaurant2Customer(1, x1, y1, x0, y0);	                                                                                              // Calling trackDelivery object to conclude delivery process to delivery at customer address

	return 0;
    
}

