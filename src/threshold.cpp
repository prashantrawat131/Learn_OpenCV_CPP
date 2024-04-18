#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
    Mat src = imread("C:/Users/prash/Learning/c++/Learn_OpenCV_CPP/images/my_pic.jpeg");
    imshow("Original image", src);

    Mat new_img;

    threshold(src, new_img, 127, 255, THRESH_BINARY);
    imshow("Binary Threshold", new_img);

    threshold(src, new_img, 127, 255, THRESH_BINARY_INV);
    imshow("Inverse Binary Threshold", new_img);

    threshold(src, new_img, 127, 255, THRESH_TRUNC);
    imshow("Trunc Threshold", new_img);

    threshold(src, new_img, 127, 255, THRESH_TOZERO);
    imshow("ZERO Threshold", new_img);

    waitKey(0);

    destroyAllWindows();

    return 0;
}