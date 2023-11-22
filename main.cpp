# include <opencv2/opencv.hpp>
# include <cstdio>
# include <iostream>
# include "math_utils.h"

// 计算斜率
//根据直线起始点计算直线斜率 k=(y2-y1) / (x2-x1)
double gradient(cv::Point2f& pt1, cv::Point2f& pt2)
{
	if (pt1.x == pt2.x)
	{	
		return 9999999.9;	//斜率不存在
	}
	else
	{
		return (pt2.y - pt1.y) / (pt2.x - pt1.x);
	}	
}

//计算角度 注意：两直线的夹角是两直线缩成的小于90°的角
// tanθ=|（k1-k2）/ (1+k1*k2) |
double getAngle(cv::Point2f &ArcCenter, cv::Point2f &StartPoint, cv::Point2f &EndPoint)
{
	//两直线斜率
    double k1 = gradient(StartPoint, ArcCenter);
	double k2 = gradient(EndPoint, ArcCenter);
    std::cout<< "k1 = "<< k1 <<std::endl;
    std::cout<< "k2 = "<< k2 <<std::endl;
	//弧度
	// double theta = atan(abs((k2 - k1) / (1 + k1 * k2)));
    double theta = atan(abs((k2 - k1) / (1 + k1 * k2)));
    std::cout<< "theta = "<< theta<<std::endl;

	//角度
	double Angle = theta * 180 / CV_PI;
	std::cout<< "Angle = "<< Angle<<std::endl;
	return Angle;
}

// 测试点是否在轮廓内
int pointTest( )
{
    const int r = 100;
    cv::Mat src = cv::Mat::zeros(r * 4, r * 4, CV_8UC1);

    std::vector<cv::Point2f> slot(4);
    slot[0] = cv::Point2f(2*r,2*r);
    slot[1] = cv::Point2f(2*r,3*r);
    slot[2] = cv::Point2f(3*r,3*r);
    slot[3] = cv::Point2f(3*r,2*r);

    cv::Point2f fsd = cv::Point2f(250,230.5);

    double dist = cv::pointPolygonTest(slot, fsd, true);
    

    std::cout<< "dist = "<< dist<<std::endl;
    return 0;
}


int main( )
{

    cv::Point2f ArcCenter(0,0);
    cv::Point2f StartPoint(1,0);
    cv::Point2f EndPoint(-1,1);

    // double Angle = getAngle(ArcCenter,StartPoint,EndPoint);

    // getAngelOfTwoVector(EndPoint,StartPoint,ArcCenter);
    float yaw = CalcuVectorYaw(EndPoint,StartPoint);
    double Angle = yaw * 180 / CV_PI;
	  std::cout<< "Angle = "<< Angle<<std::endl;

   
    return 0;
}