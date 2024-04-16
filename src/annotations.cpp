#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat img = imread("C:/Users/prash/Learning/c++/Learn_OpenCV_CPP/images/my_pic.jpeg");
    if (img.empty())
    {
        cout << "Could not read the image" << endl;
        return -1;
    }

    Mat copy = img.clone();
    Point p1(100, img.rows / 2);
    Point p2(img.cols - 100, img.rows / 2);

    line(copy, p1, p2, Scalar(0, 0, 255), 2);
    imshow("Image", copy);

    waitKey(0);

    copy = img.clone();
    Point center = Point(img.cols / 2, img.rows / 2);
    circle(copy, center, 100, Scalar(0, 255, 0), 2);
    imshow("Image", copy);

    waitKey(0);

    copy = img.clone();
    circle(copy, center, 100, Scalar(0, 255, 0), -1);
    imshow("Image", copy);

    waitKey(0);

    copy = img.clone();
    rectangle(copy, Point(100, 100), Point(300, 300), Scalar(255, 0, 0), 2);
    imshow("Image", copy);

    waitKey(0);

    copy = img.clone();
    ellipse(copy, center, Size(100, 50), 0, 0, 360, Scalar(255, 0, 0), 2);
    imshow("Image", copy);

    waitKey(0);

    copy = img.clone();
    putText(copy, "Prashant", Point(100, 100), FONT_HERSHEY_COMPLEX, 2, Scalar(255, 0, 0), 2);
    imshow("Image", copy);

    waitKey(0);



    destroyAllWindows();

    return 0;
}