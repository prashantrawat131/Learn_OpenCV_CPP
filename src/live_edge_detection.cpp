#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
    Mat frame, edges;

    VideoCapture vid_cap_obj(0);

    if (!vid_cap_obj.isOpened())
    {
        return 0;
    }

    while (vid_cap_obj.isOpened())
    {
        int rc = vid_cap_obj.read(frame);
        if (rc == false)
        {
            break;
        }

        Mat blur_img;
        GaussianBlur(frame, blur_img, Size(3, 3), 0);

        Canny(blur_img, edges, 100, 200, 3, false);
        imshow("Live Edge Detection", edges);

        int key = waitKey(16.67);
        if (key >= 0)
        {
            break;
        }
    }

    return 0;
}