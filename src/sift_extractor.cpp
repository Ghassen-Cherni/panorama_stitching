#include "sift_extractor.h"
#include <opencv2/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>


sift_output key_point_detector(cv::Mat input)
{
    //const cv::Mat input = cv::imread("image.jpg", 0);
    cv::Ptr<cv::SIFT> siftPtr = cv::SIFT::create();
    //std::vector<cv::KeyPoint> keypoints;
    //cv::Mat descriptor;
    sift_output sift;
    siftPtr->detectAndCompute(input, cv::Mat(), sift.keypoints, sift.descriptor);
    cv::Mat output;
    cv::drawKeypoints(input, sift.keypoints, output);
    cv::imwrite("../sift_result.jpg", output);
    return sift;
}

void sort_matcher(std::vector<cv::DMatch>& matches)
{
    for (int i = 0; i<matches.size(); i++)
    {
        for (int j =i; j<matches.size(); j++)
        {
            if ( matches[i].distance > matches[j].distance)
            {
                auto temp {matches[i]};
                matches[i] = matches[j];
                matches[j] = temp;
            }

        }

    }
    return;
}

void stitch(cv::Mat input1,cv::Mat input2)
{   
    sift_output sift1{key_point_detector(input1)};
    sift_output sift2{key_point_detector(input2)};
    cv::BFMatcher matcher;
    std::vector<cv::DMatch > matches;
    matcher.match(sift1.descriptor, sift2.descriptor, matches);
    sort_matcher(matches);
    matches.resize(10);
    cv::Mat output_image;
    cv::drawMatches(
			        input1, sift1.keypoints,
					input2, sift2.keypoints,
					matches,
					output_image);

    cv::imwrite("../stitched_image.jpg",output_image);
    std::vector<cv::Point2f> points_img1;
    std::vector<cv::Point2f> points_img2;
    for (int i=0; i<matches.size(); i++)
    {
        points_img1.push_back(sift1.keypoints[matches[i].queryIdx].pt);
        points_img2.push_back(sift2.keypoints[matches[i].trainIdx].pt);
    }
    cv::Mat H{cv::findHomography(points_img1, points_img2)}; 
    cv::Mat result;
    cv::warpPerspective(input1, result, H, cv::Size(input1.cols+input2.cols, input1.rows));
    
    cv::Mat half(result,cv::Rect(0,0,input2.cols,input2.rows));
    input2.copyTo(half);
    cv::imwrite("../warp_test.jpg", result);

    return;
} 