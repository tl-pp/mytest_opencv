#include <math.h>
# include <opencv2/opencv.hpp>


static float GetGradientAngle(cv::Point2f pt1, cv::Point2f pt2) {
  // 0- 180
  float angle = 0;
  if (std::fabs(pt1.x - pt2.x) < 1e-6) {
    angle = 90;
  } else if (std::fabs(pt1.y - pt2.y) > 1e-6) {
    float grad = (pt1.y - pt2.y) / (pt1.x - pt2.x);
    angle = atan(grad) * 57.29578;
    if (angle < 0) {
      angle = angle + 180;
    }
  }
  return angle;
}

static float CalcuVectorYaw(cv::Point2f p1, cv::Point2f p2) {
  p1.y = -p1.y;
  p2.y = -p2.y;
  float angle_line =
      (p1.x * p2.x + p1.y * p2.y) /
      (std::sqrt((p1.x * p1.x + p1.y * p1.y) * (p2.x * p2.x + p2.y * p2.y)) +
       1e-6);
  float disAngle = std::acos(angle_line);
  if (p1.x > 0) {
    return disAngle;
  } else {
    return -disAngle;
  }
}

static float getAngelOfTwoVector(cv::Point2f &pt1, cv::Point2f &pt2, cv::Point2f &c)
{
	float theta = atan2(pt1.x - c.x, pt1.y - c.y) - atan2(pt2.x - c.x, pt2.y - c.y);
	if (theta > CV_PI)
		theta -= 2 * CV_PI;
	if (theta < -CV_PI)
		theta += 2 * CV_PI;
 
	theta = theta * 180.0 / CV_PI;
	return theta;
}