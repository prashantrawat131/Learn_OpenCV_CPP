#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat img = imread("C:/Users/prash/Learning/c++/Learn_OpenCV_CPP/images/my_pic.jpeg");
    imshow("Original image", img);

    Mat sharp_img;

    Mat kernel1 = (Mat_<double>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    filter2D(img, sharp_img, -1, kernel1, Point(-1, -1), 0, BORDER_DEFAULT);
    imshow("Sharpened image 1", sharp_img);

    waitKey(0);

    destroyAllWindows();

    return 0;
}