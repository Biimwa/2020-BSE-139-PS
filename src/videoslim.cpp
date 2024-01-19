#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

#include "videoslim.h"


class VideoSlim {
public:
    void VideoSlim::recordAndCompressVideo(const std::string& inputLocation, const std::string& outputLocation, double compressionRatio) {
        cv::VideoCapture cap;

        if (inputLocation == "camera") {
            cap.open(0); // Open the default camera
        } else {
            cap.open(inputLocation); // Open the video file
        }

        if (!cap.isOpened()) {
            std::cerr << "Error: Could not open the camera or video file." << std::endl;
            return;
        }

        int frameWidth = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH));
        int frameHeight = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT));
        cv::VideoWriter compressedVideoWriter(outputLocation, cv::VideoWriter::fourcc('H', '2', '6', '4'), 30, cv::Size(frameWidth * compressionRatio, frameHeight * compressionRatio));

        while (true) {
            cv::Mat frame;
            cap >> frame; // Capture frame-by-frame

            if (frame.empty()) {
                std::cerr << "Error: Video capture ended unexpectedly." << std::endl;
                break;
            }

            // Compress the video frame using H.264 compression
            cv::resize(frame, frame, cv::Size(), compressionRatio, compressionRatio);

            // Write the compressed frame to the video file
            compressedVideoWriter.write(frame);

            // Break the loop if the user presses 'Esc'
            if (cv::waitKey(1) == 27) {
                break;
            }
        }

        // Release the VideoCapture and VideoWriter
        cap.release();
        compressedVideoWriter.release();
        cv::destroyAllWindows();

        std::cout << "Video recording and compression complete. Compressed video saved to: " << outputLocation << std::endl;
    }

    void VideoSlim::decompressAndSaveVideo(const std::string& compressedVideoLocation, const std::string& outputLocation) {
        cv::VideoCapture compressedCap(compressedVideoLocation);
        if (!compressedCap.isOpened()) {
            std::cerr << "Error: Could not open the compressed video file." << std::endl;
            return;
        }

        int frameWidth = static_cast<int>(compressedCap.get(cv::CAP_PROP_FRAME_WIDTH));
        int frameHeight = static_cast<int>(compressedCap.get(cv::CAP_PROP_FRAME_HEIGHT));
        cv::VideoWriter decompressedVideoWriter(outputLocation, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, cv::Size(frameWidth, frameHeight));

        while (true) {
            cv::Mat compressedFrame;
            compressedCap >> compressedFrame; // Capture frame-by-frame from the compressed video

            if (compressedFrame.empty()) {
                std::cerr << "Error: Compressed video capture ended unexpectedly." << std::endl;
                break;
            }

            // Decompress the video frame (resize to its original size)
            cv::resize(compressedFrame, compressedFrame, cv::Size(frameWidth, frameHeight));

            // Write the decompressed frame to the video file
            decompressedVideoWriter.write(compressedFrame);

            // Break the loop if the user presses 'Esc'
            if (cv::waitKey(1) == 27) {
                break;
            }
        }

        // Release the VideoCapture and VideoWriter
        compressedCap.release();
        decompressedVideoWriter.release();
        cv::destroyAllWindows();

        std::cout << "Video decompression and saving complete. Decompressed video saved to: " << outputLocation << std::endl;
    }
};