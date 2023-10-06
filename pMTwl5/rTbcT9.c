#Here's a simple C program that captures video from your camera and attempts to recognize a 
#hand gesture using OpenCV. We'll look for a hand's color and track it as it moves


#include <stdio.h>
#include <opencv2/opencv.hpp>

int main() {
    // Open the camera
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        printf("Could not open camera\n");
        return -1;
    }

    cv::namedWindow("Gesture Recognition", cv::WINDOW_AUTOSIZE);

    cv::Mat frame;
    cv::Mat hsv;
    cv::Scalar lowerBound(0, 20, 70);
    cv::Scalar upperBound(20, 255, 255);

    while (1) {
        cap >> frame;
        if (frame.empty()) {
            printf("Could not read frame\n");
            break;
        }

        cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV);
        cv::inRange(hsv, lowerBound, upperBound, frame);

        cv::GaussianBlur(frame, frame, cv::Size(15, 15), 2, 2);
        std::vector<std::vector<cv::Point> > contours;
        cv::findContours(frame, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

        for (size_t i = 0; i < contours.size(); i++) {
            double area = cv::contourArea(contours[i]);
            if (area > 10000) {
                cv::drawContours(frame, contours, static_cast<int>(i), cv::Scalar(0, 0, 255), 2);
            }
        }

        cv::imshow("Gesture Recognition", frame);

        if (cv::waitKey(10) == 27) { // Exit on 'ESC' key press
            break;
        }
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}
