// Include Libraries
#include <opencv2/opencv.hpp>
#include <iostream>

// Namespace nullifies the use of cv::function();
using namespace std;
using namespace cv;

int main()
{
    // Read an image
    Mat img_grayscale = imread("C:/Users/prash/Learning/c++/Learn_OpenCV_CPP/images/my_pic.jpeg", IMREAD_GRAYSCALE);

    // Display the image in a window
    imshow("grayscale image", img_grayscale);

    // Wait for a keystroke.
    waitKey(0);

    // Destroys all the windows created
    destroyAllWindows();

    // Write the image in the same directory
    imwrite("C:/Users/prash/Learning/c++/Learn_OpenCV_CPP/images/gray_scale.jpeg", img_grayscale);
    return 0;
}