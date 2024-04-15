#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("C:/Users/prash/Learning/c++/Learn_OpenCV_CPP/images/my_pic.jpeg");
    imshow("Original image", img);

    int actual_width = img.cols;
    int actual_height = img.rows;

    int down_width = actual_width / 2;
    int down_height = actual_height / 2;
    Mat down_img;
    resize(img, down_img, Size(down_width, down_height), INTER_LINEAR);
    imshow("Downscaled image", down_img);

    int up_width = actual_width * 2;
    int up_height = actual_height * 2;
    Mat up_img;
    resize(img, up_img, Size(up_width, up_height), INTER_LINEAR);
    imshow("Upscaled image", up_img);

    /*
    We can also resize the image using scaling factor as mentioned in the docs.
    */

    waitKey();

    destroyAllWindows();

    return 0;
}