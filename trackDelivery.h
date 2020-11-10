#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

class trackDelivery
{
private:

    cv::Point                                               source, destination;
    cv::Mat                                                 mapToProcess, mapOfCity, trajectoryMap, binaryMask;
    std::vector<cv::Point>                                  deliveryPerson, restaurantLocations, customerLocations, historyDM;
    int                                                     neighborOfDM[3][3] = { 0,0,0,0,0,0,0,0,0 };                 // stores a 3x3 matrix around a given point
    int                                                     availPosOfDM[3][3] = { 0,0,0,0,0,0,0,0,0 };                 // provides a 3x3 matrix around a point where available directions are to move
    int                                                     flag{ 0 };                                                  // flag to switch direction - can be 0,1 or 2
    bool                                                    journeyFlag{ 0 };                                           // boolean flag to select whether DM goes to restaurant or customer address

public:

    trackDelivery(int journey, int src, int dst);
    ~trackDelivery();

    void                                                    preprocessingCityMap();
    void                                                    initializeDeliveryPerson();
    void                                                    initializeRestaurants();
    void                                                    initializeCustomer();
    void                                                    binarizeImage();
    void                                                    deliveryManProgress();
    void                                                    searchNeighbourhood(cv::Point);
    void                                                    desiredDirection(cv::Point, cv::Point);
    cv::Point                                               computeDirection(cv::Point, cv::Point);

};

