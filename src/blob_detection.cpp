#include <opencv2/opencv.hpp>
// #include<opencv2/features2d.hpp>
#include <vector>

using namespace cv;
using namespace std;

int main()
{
    Mat img = imread("C:/Users/prash/Learning/c++/Learn_OpenCV_CPP/images/blob_detection_img.png", IMREAD_GRAYSCALE);
    imshow("Original image", img);

    SimpleBlobDetector::Params params;

    params.minThreshold = 50;
    params.maxThreshold = 255;


// Found this one more helpful when finding objects on a same color background.
    params.filterByArea = true;
    params.minArea = 100;

    params.filterByCircularity = true;
    params.minCircularity = 0.1;

    params.filterByConvexity = true;
    params.minConvexity = 0.3;

    params.filterByInertia = true;
    params.minInertiaRatio = 0.075;

    Ptr<SimpleBlobDetector> sbd = SimpleBlobDetector::create(params);
    vector<KeyPoint> keyPoints;

    sbd->detect(img, keyPoints);

    Mat final_img;
    drawKeypoints(img, keyPoints, final_img, Scalar(0, 0, 255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
    imshow("Blob Detection", final_img);

    waitKey(0);

    destroyAllWindows();

    return 0;
}