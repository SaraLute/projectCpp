// PiE project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "trackDelivery.h"
#include "userData.h"
#include "newOrder.h"

using namespace cv;
using namespace std;

int main()
{
	//userData one;
	//newOrder two;
	
	std::cout << "Hello, and welcome to this food ordering system." << std::endl;

	///// SWITCH FROM SARA'S CODE
 
 //   std::cout << "Do you have an account? [Y|N] " << std::endl;
 //   char action;
 //   std::cin >> action;

 //   // The action stored in 'action' is used in this switch to either make an account first or to go directly
 //   // to placing the order. After the account is setup with the order attached, it is send on to pick the nearest
 //   // deliveryman and then into the TrackDelivery script.

 //   switch (action) {
 //   case 'N':
 //       one.addressBook();
 //       one.setName();
 //       one.setAddress();
 //       one.setDesCoordinates(one.getAddress());

 //       std::cout << "Thanks for signing up!" << std::endl;
 //       std::cout << "Do you want to order now? [Y|N] " << std::endl;
 //       char action2;
 //       std::cin >> action2;
 //       switch (action2) {
 //       case 'Y':
 //           std::cout << "Then let's go get your order!" << std::endl;
 //           two.menuCard();
 //           two.restaurantDec();
 //           two.itemDec(two.getTempRes());
 //           two.setRestaurant(two.getTempRes());
 //           //deliveryMen
 //           //TrackDelivery
 //           break;
 //       case 'N':
 //           std::cout << "Thanks for visiting the system, goodbye!" << std::endl;
 //           break;
 //       default:
 //           std::cout << "This is not an option..." << std::endl;
 //       }
 //       break;
 //   case 'Y':
 //       std::cout << "Then let's go get your order!" << std::endl;
 //       two.menuCard();
 //       two.restaurantDec();
 //       two.itemDec(two.getTempRes());
 //       two.setRestaurant(two.getTempRes());
 //       //deliveryMen
 //       //trackDelivery
 //       break;
 //   default:
 //       std::cout << "This is not an option..." << std::endl;
 //   }



	///		TRACKING PROCESS BEGING HERE 
	/// 
	
	std::cout << "Let us initiate the delivery process : " << std::endl;
	// Calling trackDelivery object to initialize delivery process to pick up from restuarant
	trackDelivery DM2Restaurant(0, 1, 1);

	// Calling trackDelivery object to conclude delivery process to delivery at customer address
	trackDelivery Restaurant2Customer(1, 2, 4);

	return 0;
    
}

