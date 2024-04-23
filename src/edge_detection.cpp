/*
Blurring an image before performing edge detection can often improve the results.
The reason for this is that edge detection is highly sensitive to noise in the image.

Edge detection works by finding points in an image where the brightness changes
sharply or has discontinuities. These points typically form a set of curved
line segments termed edges.

Noise can create false edges and complicate the edge detection process.
By blurring the image first, you reduce the amount of high-frequency detail like
noise and texture, which can lead to better edge detection.
*/

#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
    Mat img = imread("C:/Users/prash/Learning/c++/Learn_OpenCV_CPP/images/my_pic.jpeg", IMREAD_GRAYSCALE);
    imshow("Original Image", img);

    // Blur image for better edge detection
    Mat blur_img;
    GaussianBlur(img, blur_img, Size(3, 3), 0);

    Mat sobelX, sobelY, sobelXY;
    Sobel(blur_img, sobelX, CV_64F, 1, 0, 5);
    Sobel(blur_img, sobelY, CV_64F, 0, 1, 5);
    Sobel(blur_img, sobelXY, CV_64F, 1, 1, 5);

    imshow("Sobel X", sobelX);
    imshow("Sobel Y", sobelY);
    imshow("Sobel XY", sobelXY);

    Mat edges;
    Canny(blur_img, edges, 100, 200, 3, false);
    imshow("Canny edge detection", edges);

    waitKey(0);

    destroyAllWindows();

    return 0;
}