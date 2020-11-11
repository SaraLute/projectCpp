#include "trackDelivery.h"

// constructor that takes coordinates for source and destination on the map, and a flag to set color of DM
trackDelivery::trackDelivery(int journey, int src_x, int src_y, int dst_x, int dst_y)
{
	/// PREPROCESSING DELIVERY PROCESS
	/// 
	/// 

	// Choose source and destination for the DeliveryMan based on user input 
	if (journey == 0)
	{
		//Choose the journey from delivery person (DM) 's location to restaurant
		source = cv::Point(src_x, src_y);
		destination = cv::Point(dst_x, dst_y);
		journeyFlag = journey;
	}
	else
	{
		//Choose the journey from delivery person (DM) 's location i.e. restuarant to customer address
		source = cv::Point(src_x, src_y);
		destination = cv::Point(dst_x, dst_y);
		journeyFlag = journey;
	}

	// Upload the city map for display and preprocessing of the binary map
	preprocessingCityMap();
	binarizeImage();

	/// Tracking process : PRIMARY function to perform tracking of delivery man (DM) coordinates
	/// 
	deliveryManProgress();

}

trackDelivery::~trackDelivery()
{

}

// Basic processing of the map to read, display and binary threshold the map
void trackDelivery::preprocessingCityMap()
{
	
	mapOfCity = cv::imread("city_map.png");
	mapToProcess = cv::imread("sample_map.png");

	// Convert binary map aka mapToProcess into grayscale
	cv::cvtColor(mapToProcess, trajectoryMap, cv::COLOR_BGR2GRAY);
	
}

// Create a binary segment image of cit showing path as white (1) and black (0) pixels
void trackDelivery::binarizeImage()
{
	cv::Mat resultMask(trajectoryMap.size(), CV_8UC1);
	for (int i = 0; i < trajectoryMap.rows; i++)
	{
		for (int j = 0; j < trajectoryMap.cols; j++)
		{
			if (trajectoryMap.at<uchar>(i, j) > 100)
				resultMask.at<uchar>(i, j) = 255;																							//Make pixel white
			else
				resultMask.at<uchar>(i, j) = 0;																								//Make pixel black
		}
	}
	resultMask.copyTo(binaryMask);
}

// PRIMARY function to perform tracking of delivery man (DM) coordinates
void trackDelivery::deliveryManProgress()
{
	// Plotting the coordinates of delivery person, restaurant and customer location
	cv::Scalar colorCircle1(0, 0, 0);

	if (journeyFlag == 0)
	{
		colorCircle1 = cv::Scalar(0, 0, 255);																							//BGR color for DM when going towards restaurant
	}
	else
	{
		colorCircle1 = cv::Scalar(255, 0, 0);																							//BGR color for DM when going towards restaurant
	}

	// Pass the user fed coordinates to source and destination containers 
	cv::Point DM = source;
	cv::Point des = destination; 

	//Figure 1 - display the city map
	cv::circle(mapOfCity, DM, 5, colorCircle1, 5);
	cv::circle(mapOfCity, des, 5, cv::Scalar(0, 0, 0), 5);

	/// TRACKING PROCESS
	/// 
	
	//Temporary variables used for calculation
	int count = 0;																														// Counting number of steps i.e. time taken by DM to pick up/complete delivery
	cv::Point updatedDM = DM;																											// Storing history of DM positions
	historyDM.push_back(updatedDM);

	// Inside a while loop compute the next positions of DM till it reaches from a source coordinate to a destination
	while ( ((updatedDM.x!=des.x) || (updatedDM.y!=des.y)) && (count < 1500))
	{
		desiredDirection(updatedDM, des);
		searchNeighbourhood(updatedDM);

		if (count==0)
			updatedDM = computeDirection(updatedDM, historyDM[0]);
		else
			updatedDM = computeDirection(updatedDM, historyDM[count]);

		if (count % 20 == 0)
		{
			// Display DM position of map every 20 steps/counts taken i.e. 1 minute in our time scale 
			cv::circle(mapOfCity, updatedDM, 3, colorCircle1, 3);
			cv::imshow("Map of City", mapOfCity);
			cv::waitKey(100);
		}

		count++;
		historyDM.push_back(updatedDM);
	}


	std::cout << "Delivery man reached destination " << " restaurant "<< " in time : " << count/20 << "minutes"<<std::endl;

	cv::imshow("Map of City", mapOfCity);
	cv::waitKey(0);
	

}
// function returns a matrix of 3x3 in neighborhood of given coordinate, it is comprised of logicals 1s and 0s
void trackDelivery::searchNeighbourhood(cv::Point A)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			//scaling by 255 to make it 1s and 0s
			neighborOfDM[j][i] = (int)binaryMask.at<uchar>(A.y - 1 + j, A.x - 1 + i)/255;			//here y,x  = col, row format is required to access pixels
		}
}

// function that genreates a 3x3 matrix with 1s only in the direction pointing from source towards destination
void trackDelivery::desiredDirection(cv::Point src, cv::Point des)
{
	// Checking available Y spots
	if (des.y > src.y)
		availPosOfDM[2][1] = 1;
	else if (des.y < src.y)
		availPosOfDM[0][1] = 1;

	// Checking available X spots
	if (des.x > src.x)
		availPosOfDM[1][2] = 1;
	else if (des.x < src.x)
		availPosOfDM[1][0] = 1;

}

/// Function to compute direction using desired direction matrixand
/* neighborhood matrix, takes currentand previous coordinates of delivery
 person, both the 3x3 matrix output of searchNeighborhood and
 desiredDirection and a flag

 -flag == 0 when one of the available positions is the desired position to take
 -flag == 2 when both the available position are desired positions to take, mostly occurs at corners so here we force a turn
 -flag == 1 when none of the available positions are desired positions to take, mostly occurs when sourceand edstination are on paralle lines
 Here, we force the DP to go along the direction its going till it encounters a turnand then turn the flag to 2.	*/
cv::Point trackDelivery::computeDirection(cv::Point dm, cv::Point dm_prev)
{
	// First compute a prodMat - product of available positions and neighbourhood pixels of a DM

	int ProdMat[3][3] = {0,0,0,0,0,0,0,0,0};
	int sumProdMat = 0;
	cv::Point newDM = dm;

	/// Compute the sum of elements in ProdMat which is sum of output of searchNeighborhood X desiredDirection
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ProdMat[i][j] = neighborOfDM[i][j] * availPosOfDM[i][j];
			sumProdMat += ProdMat[i][j];
		}
	}

	 ///Case flag == 0, when only one of available directions are desired direction for DM i.e.only one element of ProdMat is 1
	if ((sumProdMat == 1) & (flag == 0))
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{	
				if (ProdMat[i][j] == 1)
				{
					newDM.x = dm.x + j - 1;
					newDM.y = dm.y + i - 1;
				}	
			}
		}
	}
	/// Case flag == 2, when both of available directions can be desired direction for DM i.e.only two elements of ProdMat are 1, typically at turnings
	else if ((sumProdMat == 2) | (flag == 2))
	{
		// now we brute force to only go in the direction it was not traveling previously, by invoking hisotry

			flag = 0;																						// after taking turn force flag == 0 to go back to previous case
			if (dm_prev.x == dm.x) 
			{
				// if DM was going along constant X, then it should switch to y direction
				if (ProdMat[0][1] == 1)
				{
					newDM.y = dm.y - 1;
					newDM.x = dm.x;
				}
				else if (ProdMat[2][1] == 1)
				{
					newDM.y = dm.y + 1;
					newDM.x = dm.x;
				}
			}
				
			else if (dm_prev.y == dm.y)
			{
				// if DM was going along constant Y, then it should switch to x direction
				if (ProdMat[1][0] == 1)
				{
					newDM.x = dm.x - 1;
					newDM.y = dm.y;
				}
				else if (ProdMat[1][2] == 1)
				{
					newDM.x = dm.x + 1;
					newDM.y = dm.y;
				}
			}
			
	
	}
	/// Case flag == 1, when none of available directions can be desired direction for DP i.e.no elements of ProdMat is 1, typically when DM direction is parallel to destination's lane 
	else if ((sumProdMat == 0) | (flag == 1))
	{
		if (sumProdMat == 0)																				// force flag == 0 to stay on this condition till a turn occurs
			flag = 1;
		
		// now we explicitly choose direction that is available to move
		if (dm_prev.x == dm.x)																				// then it should continue along y
		{
			// if the delivery man confronts a turn then turn the flag back to 2
			if ((neighborOfDM[1][0] == 1) | (neighborOfDM[1][2] == 1))
			{
				flag = 2;
				newDM.x = dm.x;
				newDM.y = dm.y;
			}
			else
			{
				if (dm_prev.y == dm.y - 1)
				{
					newDM.y = dm.y + 1;
					newDM.x = dm.x;
				}
				else if (dm_prev.y == dm.y + 1)
				{
					newDM.y = dm.y - 1;
					newDM.x = dm.x;
				}
			}
		}
		else if (dm_prev.y == dm.y)																			// then it should continue along x
		{
			// if the delivery man confronts a turn then turn the flag back to 2
			if ((neighborOfDM[0][1] == 1) | (neighborOfDM[2][1] == 1))
			{
				flag = 2;
				newDM.x = dm.x;
				newDM.y = dm.y;
			}
			else
			{
				if (dm_prev.x == dm.x - 1)
				{
					newDM.y = dm.y;
					newDM.x = dm.x + 1;
				}
				else if (dm_prev.x == dm.x - 1)
				{
					newDM.y = dm.y;
					newDM.x = dm.x - 1;
				}

			}				
		}

	}

	// return the new position of DM
	return newDM;
}


