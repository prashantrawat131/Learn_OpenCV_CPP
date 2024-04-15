#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    VideoCapture vid_cap_obj(0);

    if (!vid_cap_obj.isOpened())
    {
        return -1;
    }

    while (vid_cap_obj.isOpened())
    {
        Mat frame;
        bool rc = vid_cap_obj.read(frame);
        if (rc == false)
        {
            cout << "Error\n";
            break;
        }

        imshow("Webcame footage", frame);

        int key = waitKey(16.67);
        if (key >= 0)
        {
            cout << "Quitting\n";
            break;
        }
    }

    vid_cap_obj.release();
    destroyAllWindows();

    return 0;
}