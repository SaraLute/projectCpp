#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

class trackDelivery
{
private:

    cv::Mat                                                 mapToProcess, mapOfCity, trajectoryMap, binaryMask;
    std::vector<cv::Point>                                  deliveryPerson, restaurantLocations;
    int                                                     neighborOfDM[3][3] = { 0,0,0,0,0,0,0,0,0 };

public:

    void                                                    preprocessingCityMap();
    void                                                    initializeDeliveryPerson();
    void                                                    initializeRestaurants();
    void                                                    binarizeImage();
    void                                                    deliveryManProgress();
    int                                                     searchNeighbourhood(cv::Point, cv::Mat);
    trackDelivery();
    ~trackDelivery();
};

