#include "trackDelivery.h"

trackDelivery::trackDelivery()
{
	std::cout << "Hello World!\n";
	cv::Mat image = cv::imread("city_map.png");
	imshow("Map of City", image);
	cv::waitKey(0);
}

trackDelivery::~trackDelivery()
{

}
