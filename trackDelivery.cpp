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
	

	/*cv::Point cen(436, 447);
	int radius = 15;

	//get the Rect containing the circle:
	cv::Rect r(cen.x - radius, cen.y - radius, radius * 2, radius * 2);

	// obtain the image ROI:
	cv::Mat roi(binaryMask, r);
	cv::imshow("Map of City", roi);
	cv::waitKey(0);
	std::cout << roi << std::endl;*/
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
	//cv::Point DM(42, 53);					//X, Y coordinates of delivery man in terms of cv::Point
	cv::Point DM = deliveryPerson.at(3);
	cv::Point res = restaurantLocations.at(4);
	cv::Scalar colorCircle1(0, 0, 255);		//BGR color

	cv::circle(mapOfCity, DM, 5, cv::Scalar(0, 0, 255), 2);
	cv::circle(mapOfCity, res, 5, cv::Scalar(255, 0, 0), 2);

	//Figure 1 - display the city map
	//cv::imshow("Map of City", mapToProcess);
	//cv::waitKey(0);

	

	/// TRACKING PROCESS
	/// 
	
	//Temporary variables
	int count = 0;
	cv::Point updatedDM = DM;
	historyDM.push_back(DM);

	// Inside a while loop
	while ( ((updatedDM.x!=res.x) || (updatedDM.y!=res.y)) && (count < 1500))
	{
		desiredDirection(updatedDM, res);
		searchNeighbourhood(updatedDM);
		updatedDM = computeDirection(updatedDM, updatedDM);

		if (count==0)
			updatedDM = computeDirection(updatedDM, historyDM[0]);
		else
			updatedDM = computeDirection(updatedDM, historyDM[count]);

		if (count % 20 == 0)
		{
			cv::circle(mapOfCity, updatedDM, 3, cv::Scalar(0, 0, 255), 1);
			cv::imshow("Map of City", mapOfCity);
			cv::waitKey(100);
			//std::cout << "updated position of DM is : " << updatedDM << " in time taken : " << count <<std::endl;
			//std::cout << "updated history of DM is : " << historyDM[count] << " in time taken : " << count << std::endl;
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
	//neighborOfDM = cv::Rect(A.x - 1, A.y - 1, 3, 3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			//scaling by 255 to make it 1s and 0s
			neighborOfDM[j][i] = (int)binaryMask.at<uchar>(A.y - 1 + j, A.x - 1 + i)/255;			//here y,x  = col, row format is required to access pixels

			//Some display commands to verify steps
			//std::cout << "image neighborhood at"<< A.x - 1 + i<<","<< A.y - 1 + j<<" is " << (int) binaryMask.at<uchar>(A.y - 1 + j, A.x - 1 + i) << std::endl;
			//std::cout << "image neighborhood at" << A.x - 1 + i << "," << A.y - 1 + j << " is " << neighborOfDM[i][j] << std::endl;
		}

	//Some display commands to verify steps
	//for (int i = 0; i < 3; i++)
	//	{
	//		for (int j = 0; j < 3; j++)
	//		{
	//			std::cout << "desired positions to move at" << i << "," << j << "is" << neighborOfDM[i][j] << std::endl;
	//		}
	//	}
}

// function that genreates a 3x3 matric with 1s only in the direction pointing from source towards destination
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

	//Some display commands to verify steps
	//for (int i = 0; i < 3; i++)
	//{
	//	for (int j = 0; j < 3; j++)
	//	{
	//		std::cout << "available positions to move at" << i << "," << j << "is" << availPosOfDM[i][j] << std::endl;
	//	}
	//}
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

	// Compute the sum of elements in ProdMat
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ProdMat[i][j] = neighborOfDM[i][j] * availPosOfDM[i][j];
			sumProdMat += ProdMat[i][j];
			/*if (ProdMat[i][j] == 1) 
			{
			newDM.x = dm.x + j - 1;
			newDM.y = dm.y + i - 1;
			}*/
			//std::cout << "available positions to move at" << i << "," << j << "is" <<ProdMat[i][j] << std::endl;
		}
	}

	 //Case flag == 0, when only one of available directions are desired direction for DP i.e.only one element of ProdMat is 1
	if ((sumProdMat == 1) && (flag == 0))
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				//ProdMat[i][j] = neighborOfDM[i][j] * availPosOfDM[i][j];
				//sumProdMat += ProdMat[i][j];
				if (ProdMat[i][j] == 1)
				{
					newDM.x = dm.x + j - 1;
					newDM.y = dm.y + i - 1;
				}
				//std::cout << "available positions to move at" << i << "," << j << "is" <<ProdMat[i][j] << std::endl;
			}
		}
	}
	// Case flag == 2, when both of available directions can be desired direction for DP i.e.only two elements of ProdMat are 1, typically at turnings
	else if ((sumProdMat == 2) || (flag == 2))
	{
		// now we brute force to only go in the direction it was not traveling previously, by invoking hisotry

			flag = 0;																						// after taking turn force flag == 0 to go back to previous case
			if (dm_prev.x == dm.x) 
			{
				// if Dp was going along constant X, then it should switch to y direction
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
				// if Dp was going along constant Y, then it should switch to x direction
			{
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
	// Case flag == 1, when none of available directions can be desired direction for DP i.e.no elements of ProdMat is 1, typically when DP direction is parallel to destination's lane 
	else if ((sumProdMat == 0) || (flag == 1))
	{
		if (sumProdMat == 0)																				// force flag == 0 to stay on this condition till a turn occurs
			flag = 1;
		
		// now we explicitly choose direction that is available to move
		if (dm_prev.x == dm.x) // then it should continue along y
		{
			// if the delivery man confronts a turn then turn the flag back to 2
			if (neighborOfDM[1][0] == 1 || neighborOfDM[1][2] == 1)
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
		else if (dm_prev.y == dm.y) // then it should continue along x
		{
			// if the delivery man confronts a turn then turn the flag back to 2
			if (neighborOfDM[0][1] == 1 || neighborOfDM[2][1] == 1)
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

	
	//std::cout << "updated position of DM is : " <<newDM << " and flag is : "<<flag<<std::endl;
	return newDM;
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