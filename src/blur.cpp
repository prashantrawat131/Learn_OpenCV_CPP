#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("C:/Users/prash/Learning/c++/Learn_OpenCV_CPP/images/my_pic.jpeg");
    imshow("Original image", img);

    Mat blurred_img;

    Mat kernel1 = Mat::ones(5, 5, CV_64F);
    kernel1 = kernel1 / 25;
    filter2D(img, blurred_img, -1, kernel1, Point(-1, -1), 0, 4);
    imshow("Blurred image 1", blurred_img);

    blur(img, blurred_img, Size(5, 5));
    imshow("Blurred image 2", blurred_img);

    GaussianBlur(img, blurred_img, Size(5, 5), 0, 0);
    imshow("Gaussian blur", blurred_img);

    medianBlur(img, blurred_img, (5, 5));
    imshow("Median blur", blurred_img);

    bilateralFilter(img, blurred_img, 40, 75, 75);
    imshow("Bilateral blur", blurred_img);

    waitKey(0);

    destroyAllWindows();

    return 0;
}