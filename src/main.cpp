#include "function.h"
#include "sift_extractor.h"
#include "opencv2/opencv.hpp"
#include <iostream>
#include <Eigen/Core>

// c++ course

/*

Always favor initializing with braces 
int x { 5 }; doesn't allow automatic conversion if there's a data loss
int width {}; initializes to zero. If it was another type it could've initialized to empty
*/

using namespace std;
using namespace cv;
int main()
{	
	Mat img1= imread("../image2.jpg");
	Mat img2= imread("../image1.jpg");
	stitch(img1, img2);
	cout << " Eigen version : " << EIGEN_MAJOR_VERSION << " . "<< EIGEN_MINOR_VERSION << endl ;
	//Mat img= imread("../image.jpg");
	//imshow("image", img);
	//waitKey(0);
	//std::cout<<"Hello, World!"<<std::endl;
	return 0;
}