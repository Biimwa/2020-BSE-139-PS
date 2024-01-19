#ifndef VIDEOSLIM_INTERNAL_H
#define VIDEOSLIM_INTERNAL_H

#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

class VideoSlim {
public:
    void recordAndCompressVideo(const std::string& inputLocation, const std::string& outputLocation, double compressionRatio);
    void decompressAndSaveVideo(const std::string& compressedLocation, const std::string& outputLocation);
};

#endif // VIDEOSLIM_INTERNAL_H
