#include "videoslim_internal.h"
#include <cassert>

int main() {
    // Test cases for internal C++ functionality
    VideoSlim videoslim;

    // Test Case 1: Record and compress video from camera, decompress, and save
    videoslim.recordAndCompressVideo("camera", "output_camera.mp4", 0.7);
    videoslim.decompressAndSaveVideo("output_camera.mp4", "decompressed_camera.avi");

    // Test Case 2: Record and compress video from file, decompress, and save
    videoslim.recordAndCompressVideo("input_file.mp4", "output_file.mp4", 0.8);
    videoslim.decompressAndSaveVideo("output_file.mp4", "decompressed_file.avi");

    // Add more test cases as needed

    return 0;
}
