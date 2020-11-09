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

	///// SWITCH FROM SARA'S CODE
 //   std::cout << "Hello, and welcome to this food ordering system." << std::endl;
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


	//std::cout << "Welcome to the tracking delivery part of food delivery app!\n";
	trackDelivery c1;


	return 0;
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
