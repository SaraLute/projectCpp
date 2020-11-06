#include "trackDelivery.h"

trackDelivery::trackDelivery()
{
	/// PREPROCESSING DELIVERY PROCESS
	/// 
	
	//Here initialize the vector of delivery person and restaurants- Kaiyu's matlab part
	initializeDeliveryPerson();
	initializeRestaurants();

	// Upload the city map for display and preprocessing the binary map
	preprocessingCityMap();
	binarizeImage();

	/// Tracking process
	/// 
	
	deliveryManProgress();

}

trackDelivery::~trackDelivery()
{

}

void trackDelivery::preprocessingCityMap()
{
	
	mapOfCity = cv::imread("city_map.png");
	mapToProcess = cv::imread("sample_map.png");

	// Convert binary map aka mapToProcess into grayscale
	cv::cvtColor(mapToProcess, trajectoryMap, cv::COLOR_BGR2GRAY);
	//std::cout << trajectoryMap.size() << std::endl;

}

void trackDelivery::binarizeImage()
{
	cv::Mat resultMask(trajectoryMap.size(), CV_8UC1);
	for (int i = 0; i < trajectoryMap.rows; i++)
	{
		for (int j = 0; j < trajectoryMap.cols; j++)
		{
			if (trajectoryMap.at<uchar>(i, j) > 100)
				resultMask.at<uchar>(i, j) = 255;	//Make pixel white
			else
				resultMask.at<uchar>(i, j) = 0;		//Make pixel black
		}
	}
	resultMask.copyTo(binaryMask);
}

void trackDelivery::deliveryManProgress()
{
	// Plotting the coordinates of delivery person, restaurant and customer location
	cv::Point DM(43, 54);					//X, Y coordinates of delivery man in terms of cv::Point
	cv::Scalar colorCircle1(0, 0, 255);		//BGR color

	cv::circle(mapToProcess, deliveryPerson.at(3), 5, cv::Scalar(0, 0, 255), 2);
	cv::circle(mapToProcess, restaurantLocations.at(3), 5, cv::Scalar(255, 0, 0), 2);

	//Figure 1 - display the city map
	cv::imshow("Map of City", mapToProcess);
	cv::waitKey(0);

	/// TRACKING PROCESS
	/// 
	searchNeighbourhood(DM, binaryMask);
}


int trackDelivery::searchNeighbourhood(cv::Point A, cv::Mat img)
{
	//neighborOfDM = cv::Rect(A.x - 1, A.y - 1, 3, 3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			//neighborOfDM[i][j] = (int)binaryMask.at<uchar>(A.x-1+i, A.y-1+j);
			
	//cv::Mat R = 
	std::cout << "image neighborhood is " << (int) binaryMask.at<uchar>(A.x - 1 + i, A.y - 1 + j) << std::endl;
	return 1;
}

/// STATIC DATA<summary>
/// 
/// Initialize the vectors of delivery person and restaurant
void trackDelivery::initializeDeliveryPerson()
{
	// Using matlab snippet from setupBook
	deliveryPerson.push_back(cv::Point(42, 53));
	deliveryPerson.push_back(cv::Point(300, 53));
	deliveryPerson.push_back(cv::Point(382, 447));
	deliveryPerson.push_back(cv::Point(40, 389));
	deliveryPerson.push_back(cv::Point(40, 231));
	deliveryPerson.push_back(cv::Point(68, 53));
	deliveryPerson.push_back(cv::Point(85, 53));

}

void trackDelivery::initializeRestaurants()
{
	// Using matlab snippet from setupBook
	restaurantLocations.push_back(cv::Point(640, 523));
	restaurantLocations.push_back(cv::Point(627, 743));
	restaurantLocations.push_back(cv::Point(486, 523));
	restaurantLocations.push_back(cv::Point(751, 545));
	restaurantLocations.push_back(cv::Point(678, 523));

}