# include <opencv2/opencv.hpp>
# include <cstdio>
# include <iostream>
# include "math_utils.h"

// #include <opencv2/core.hpp>
// #include <opencv2/highgui.hpp>


int img_test( ) {
    // read images
    cv::Mat color = cv::imread("../img/lena.jpg");
    cv::Mat gray = cv::imread("../img/lena.jpg", cv::IMREAD_GRAYSCALE);

    if (color.data == NULL) {
        std::cout << "Could not open or find the image." << std::endl;
        return -1;
    }

    // write image
    cv::imwrite("../img/lenaGray.jpg", gray);

    // get same pixel 
    int myRow = color.cols - 1;
    int myCol = color.rows - 1;
    cv::Vec3b pixel = color.at<cv::Vec3b>(myRow, myCol);

    std::cout << "Pixel value (B,G,R): (" << (int)pixel[0] <<","<<(int)pixel[1] << "," << (int)pixel[2] <<")" << std::endl;

    // show images
    cv::imshow("lena BGR", color);
    cv::imshow("lena Gray", gray);

    cv::waitKey(0);

    return 0;
}

int main(int argc, char** argv)
{
    img_test();
    return 0;
}