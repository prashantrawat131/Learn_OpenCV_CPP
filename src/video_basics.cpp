#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    VideoCapture vid_cap_obj("C:/Users/prash/Learning/c++/Learn_OpenCV_CPP/videos/video.mp4");

    if (!vid_cap_obj.isOpened())
    {
        cout << "Error: Video file not found" << endl;
        return -1;
    }

    int fps = vid_cap_obj.get(CAP_PROP_FPS);
    cout << "Frames per second: " << fps << endl;

    int frame_count = vid_cap_obj.get(CAP_PROP_FRAME_COUNT);
    cout << "Total number of frames: " << frame_count << endl;

    while (vid_cap_obj.isOpened())
    {
        Mat frame;

        bool rc = vid_cap_obj.read(frame);
        if (rc == true)
        {
            imshow("Video", frame);
        }

        if (rc == false)
        {
            cout << "Error\n";
            break;
        }

        // Waiting few ms for a keystroke between each frame
        int key = waitKey(16.67); // 1000ms / 24fps = 16.67ms
        if (key == 'q')
        {
            cout << "Quitting\n";
            break;
        }
    }

    vid_cap_obj.release();
    destroyAllWindows();
    return 0;
}