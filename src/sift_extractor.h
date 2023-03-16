#ifndef SIFT_EXTRACTOR_H
#define SIFT_EXTRACTOR_H
#include <vector> 
#include "opencv2/opencv.hpp"

struct sift_output{
    std::vector<cv::KeyPoint> keypoints;
    cv::Mat descriptor;
};
sift_output key_point_detector(cv::Mat);
void stitch(const cv::Mat, const cv::Mat);
void sort_matcher(std::vector<cv::DMatch>&);
#endif  