/*
Contour detection works well on grayscaled images on which binary threshold has been done.

I am using blur by my own to just smooth the image. Offical tutorial do not use blur image.
*/

#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("C:/Users/prash/Learning/c++/Learn_OpenCV_CPP/images/my_pic.jpeg");

    Mat blur_img;
    GaussianBlur(img, blur_img, Size(15, 15), 0, 0);

    imshow("Blur image", blur_img);

    Mat grayscale_img;
    cvtColor(blur_img, grayscale_img, COLOR_BGR2GRAY);

    Mat threshold_img;
    threshold(grayscale_img, threshold_img, 100, 255, THRESH_BINARY);

    imshow("Binary threshold", threshold_img);

    // Chain Approx none starts here
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(threshold_img, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);

    Mat img_copy = img.clone();
    drawContours(img_copy, contours, -1, Scalar(0, 255, 0), 2);
    imshow("None approximation", img_copy);

    // Chain Approx simple starts here
    vector<vector<Point>> contours1;
    vector<Vec4i> hierarchy1;
    findContours(threshold_img, contours1, hierarchy1, RETR_TREE, CHAIN_APPROX_SIMPLE);

    Mat img_copy1 = img.clone();
    drawContours(img_copy1, contours1, -1, Scalar(0, 255, 0), 2);
    imshow("Simple Approximation", img_copy1);

    waitKey(0);

    destroyAllWindows();

    return 0;
}