#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    // By defualt imread reads images in BGR color format
    Mat img = imread("C:/Users/prash/Learning/c++/Learn_OpenCV_CPP/images/my_pic.jpeg");
    imshow("Original image", img);

    Mat lab_img;
    cvtColor(img, lab_img, COLOR_BGR2Lab);
    imshow("LAB Image", lab_img);

    Mat yCrCb_img;
    cvtColor(img, yCrCb_img, COLOR_BGR2YCrCb);
    imshow("YCrCb Image", yCrCb_img);

    Mat hsv_img;
    cvtColor(img, hsv_img, COLOR_BGR2HSV);
    imshow("HSV Image", hsv_img);

    waitKey(0);

    destroyAllWindows();

    return 0;
}