#include <opencv2/opencv.hpp>

int main() {
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open camera." << std::endl;
        return -1;
    }

    cv::Mat frame, roi, gray, thresholded;
    cv::Rect roiRect(100, 100, 200, 200);

    while (true) {
        cap >> frame;
        roi = frame(roiRect);
        cv::cvtColor(roi, gray, cv::COLOR_BGR2GRAY);
        cv::threshold(gray, thresholded, 127, 255, cv::THRESH_BINARY_INV + cv::THRESH_OTSU);
        
        std::vector<std::vector<cv::Point>> contours;
        cv::findContours(thresholded, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

        cv::rectangle(frame, roiRect, cv::Scalar(0, 255, 0), 2);
        cv::imshow("Gesture-Based Control", frame);

        if (cv::waitKey(1) == 'q') {
            break;
        }
    }

    cap.release();
    cv::destroyAllWindows();

    return 0;
}
