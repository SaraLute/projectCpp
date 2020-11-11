#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

class trackDelivery
{
private:

    cv::Point                                               source, destination;                                        // container to store coordinates of source and destination point in the map
    cv::Mat                                                 mapToProcess, mapOfCity, trajectoryMap, binaryMask;         // Image containers to store map of the city as matrix
    std::vector<cv::Point>                                  historyDM;                                                  // stores history of positoins of DM
    int                                                     neighborOfDM[3][3] = { 0,0,0,0,0,0,0,0,0 };                 // stores a 3x3 matrix around a given point
    int                                                     availPosOfDM[3][3] = { 0,0,0,0,0,0,0,0,0 };                 // provides a 3x3 matrix around a point where available directions are to move
    int                                                     flag{ 0 };                                                  // flag to switch direction - can be 0,1 or 2
    bool                                                    journeyFlag{ 0 };                                           // boolean flag to select whether DM goes to restaurant or customer address

public:

    trackDelivery(int journey, int src_x, int src_y, int dst_x, int dst_y);
    ~trackDelivery();

    void                                                    preprocessingCityMap();                                     // Basic processing of the map to read, display and binary threshold the map
    void                                                    binarizeImage();                                            // Create a binary segment image of cit showing path as white (1) and black (0) pixels
    void                                                    deliveryManProgress();                                      // PRIMARY function to perform tracking of delivery man (DM) coordinates
    void                                                    searchNeighbourhood(cv::Point);                             // create a 3x3 matrix of pixels around DM's coordinates
    void                                                    desiredDirection(cv::Point, cv::Point);                     // create and store a 3x3 matrix of desired directions to take for DM
    cv::Point                                               computeDirection(cv::Point, cv::Point);                     // Compute the next position DM can occupy on the map based on above two functions

};

