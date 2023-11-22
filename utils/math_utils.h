#include <math.h>
# include <opencv2/opencv.hpp>


float GetGradientAngle(cv::Point2f pt1, cv::Point2f pt2);
float CalcuVectorYaw(cv::Point2f p1, cv::Point2f p2);
float getAngelOfTwoVector(cv::Point2f &pt1, cv::Point2f &pt2, cv::Point2f &c);