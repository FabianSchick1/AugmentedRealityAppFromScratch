#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
#include "VersionFromScratch.h"
#include "VersionOpenCV.h"
#include "Log.h"

using namespace std;
using namespace cv;
using namespace Application;


int main()
{
    Application::Log::Init();
    AR_CORE_WARN("Initialized Log!");
    AR_CORE_INFO("Initialized Log!");
    AR_INFO("Hello! Var={0}", 5);


    string videoFile = "./Assets/video_desk.mp4";

    VideoCapture cap(videoFile);
    cap.set(CAP_PROP_BUFFERSIZE, 60);
    
    if (!cap.isOpened()) {
        std::cout << "Error opening video stream or file" << std::endl;
        return -1;
    }
    while (true) {
        cv::Mat frame;

        cap.read(frame);

        if (frame.empty())
            break;

        int down_width = 720;
        int down_height = 1280;
        resize(frame, frame, Size(down_width, down_height), INTER_LINEAR);

        imshow("Frame", frame);

        if (waitKey(1) == 27)
            break;
    }
    
    cap.release();

    cv::destroyAllWindows();

    return 0;

    
}