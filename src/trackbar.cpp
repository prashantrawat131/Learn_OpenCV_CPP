#include <opencv2/opencv.hpp>

using namespace cv;

int maxScaleUp = 100;
int scaleFactor = 1;

String windowName("Resize Image");
String trackbarName("Scale");

void scaleImageFunc(int x, void *)
{
    Mat img = imread("C:/Users/prash/Learning/c++/Learn_OpenCV_CPP/images/my_pic.jpeg");

    double scaleFactorDouble = 1 + scaleFactor / 100.0;

    if (scaleFactorDouble == 0)
    {
        scaleFactorDouble = 1;
    }

    Mat scaledImage;
    resize(img, scaledImage, Size(), scaleFactorDouble, scaleFactorDouble, INTER_LINEAR);
    imshow(windowName, scaledImage);
}

int main()
{
    Mat img = imread("C:/Users/prash/Learning/c++/Learn_OpenCV_CPP/images/my_pic.jpeg");

    namedWindow(windowName, WINDOW_AUTOSIZE);

    createTrackbar(trackbarName, windowName, &scaleFactor, maxScaleUp, scaleImageFunc);
    scaleImageFunc(25, 0);

    imshow(windowName, img);

    waitKey(0);

    destroyAllWindows();

    return 0;
}