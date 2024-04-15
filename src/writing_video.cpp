/*
In this example, I will write the webcam footage to a video file.
*/

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    VideoCapture vid_cap_obj(0);

    int frame_width = static_cast<int>(vid_cap_obj.get(CAP_PROP_FRAME_WIDTH));
    int frame_height = static_cast<int>(vid_cap_obj.get(CAP_PROP_FRAME_HEIGHT));
    Size frame_size(frame_width, frame_height);
    int fps = 60;

    VideoWriter vid_writer("C:/Users/prash/Learning/c++/Learn_OpenCV_CPP/videos/webcam_footage.avi",
                           VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, frame_size, true);

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

        imshow("Webcam Footage", frame);
        vid_writer.write(frame);

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