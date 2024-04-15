#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat img = imread("C:/Users/prash/Learning/c++/Learn_OpenCV_CPP/images/my_pic.jpeg");
    imshow("Original Image", img);

    Mat croppedImage1 = img(Range(0, img.rows / 2), Range(0, img.cols / 2));
    imshow("Cropped Image", croppedImage1);

    Mat croppedImage2 = img(Range(img.rows / 2, img.rows), Range(img.cols / 2, img.cols));
    imshow("Cropped Image 2", croppedImage2);

    Mat croppedImage3 = img(Range(img.rows / 2, img.rows), Range(0, img.cols / 2));
    imshow("Cropped Image 3", croppedImage3);

    Mat croppedImage4 = img(Range(0, img.rows / 2), Range(img.cols / 2, img.cols));
    imshow("Cropped Image 4", croppedImage4);

    waitKey(0);

    destroyAllWindows();

    return 0;
}