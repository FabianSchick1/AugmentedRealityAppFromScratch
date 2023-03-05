#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
#include "VersionFromScratch.h"
#include "VersionOpenCV.h"
#include "Log.h"

using namespace std;
using namespace Application;


int main(int argc, char** argv)
{
    Application::Log::Init();
    AR_CORE_WARN("Initialized Log!");
    AR_CORE_INFO("Initialized Log!");
    AR_INFO("Hello! Var={0}", 5);

    string videoFile = "./Assets/video_desk.mp4";

    cv::VideoCapture videoCapture(videoFile);
    videoCapture.set(cv::CAP_PROP_BUFFERSIZE, 60);
    
    if (!videoCapture.isOpened()) {
        std::cout << "Error opening video stream or file" << std::endl;
        return -1;
    }

    cv::Mat frame;
    while (videoCapture.read(frame))
    {
        
        int down_width = 720;
        int down_height = 1280;
        resize(frame, frame, cv::Size(down_width, down_height), cv::INTER_LINEAR);
        
        // TODO: Fixing low fps video
        imshow("Video", frame);
       
        if (cv::waitKey(25) >= 0)
        {
            break;
        }
    }
    
    cv::destroyWindow("Video");
    videoCapture.release();

    return 0;

    
}