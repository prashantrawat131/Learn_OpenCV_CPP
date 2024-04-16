#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat img = imread("C:/Users/prash/Learning/c++/Learn_OpenCV_CPP/images/my_pic.jpeg");
    imshow("Original Image", img);

    double angle = 1;
    Point2f center(img.cols / 2, img.rows / 2);

    int key = -1;
    while (key < 0)
    {
        Mat rotationMatrix = getRotationMatrix2D(center, angle, 1.0);

        Mat rotatedImg;
        warpAffine(img, rotatedImg, rotationMatrix, img.size(), INTER_LINEAR, BORDER_CONSTANT, Scalar(255, 255, 255));

        imshow("Rotated Image", rotatedImg);

        key = waitKey(100);
        
        angle++;
    }

    destroyAllWindows();

    return 0;
}