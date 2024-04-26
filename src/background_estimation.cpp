#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

int computeMedian(vector<int> elements)
{
    nth_element(elements.begin(), elements.begin() + elements.size() / 2, elements.end());

    // sort(elements.begin(),elements.end());
    return elements[elements.size() / 2];
}

Mat compute_median(vector<Mat> vec)
{
    // Note: Expects the image to be CV_8UC3
    Mat medianImg(vec[0].rows, vec[0].cols, CV_8UC3, Scalar(0, 0, 0));

    for (int row = 0; row < vec[0].rows; row++)
    {
        for (int col = 0; col < vec[0].cols; col++)
        {
            vector<int> elements_B;
            vector<int> elements_G;
            vector<int> elements_R;

            for (int imgNumber = 0; imgNumber < vec.size(); imgNumber++)
            {
                int B = vec[imgNumber].at<Vec3b>(row, col)[0];
                int G = vec[imgNumber].at<Vec3b>(row, col)[1];
                int R = vec[imgNumber].at<Vec3b>(row, col)[2];

                elements_B.push_back(B);
                elements_G.push_back(G);
                elements_R.push_back(R);
            }

            medianImg.at<Vec3b>(row, col)[0] = computeMedian(elements_B);
            medianImg.at<Vec3b>(row, col)[1] = computeMedian(elements_G);
            medianImg.at<Vec3b>(row, col)[2] = computeMedian(elements_R);
        }
    }
    return medianImg;
}

int main()
{
    VideoCapture cap("C:/Users/prash/Learning/c++/Learn_OpenCV_CPP/images/testing_video.mp4");
    if (!cap.isOpened())
        cerr << "Error opening video file\n";

    vector<Mat> frames;
    Mat frame;

    for (int i = 0; i < 25; i++)
    {
        cap.set(CAP_PROP_POS_FRAMES, i);
        Mat frame;
        cap >> frame;
        if (frame.empty())
            continue;
        frames.push_back(frame);
    }
    // Calculate the median along the time axis
    Mat medianFrame = compute_median(frames);

    // Display median frame
    imshow("frame", medianFrame);
    waitKey(0);

    destroyAllWindows();
}