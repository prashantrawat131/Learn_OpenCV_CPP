#include <opencv2/opencv.hpp>

using namespace cv;

Mat img;
bool drawing = false;
const String windowName("Window");

void handleMouse(int action, int x, int y, int flags, void *userdata)
{
    if (action == EVENT_LBUTTONDOWN)
    {
        drawing = true;
        circle(img, Point(x, y), 3, Scalar(0, 255, 0), FILLED);
        imshow(windowName, img);
    }
    else if (action == EVENT_MOUSEMOVE && drawing)
    {
        circle(img, Point(x, y), 3, Scalar(0, 255, 0), FILLED);
        imshow(windowName, img);
    }
    else if (action == EVENT_LBUTTONUP)
    {
        drawing = false;
    }
}

int main()
{
    img = imread("C:/Users/prash/Learning/c++/Learn_OpenCV_CPP/images/my_pic.jpeg");

    namedWindow(windowName);

    setMouseCallback(windowName, handleMouse);

    imshow(windowName, img);

    waitKey(0);

    destroyAllWindows();

    return 0;
}