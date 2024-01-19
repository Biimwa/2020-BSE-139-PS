#ifndef VIDEOSLIM_H
#define VIDEOSLIM_H

#ifdef __cplusplus
extern "C" {
#endif

// Function declarations for C interface
void* create_video_slim();
void release_video_slim(void* videoslim);
void record_and_compress_video(void* videoslim, const char* input_location, const char* output_location, double compression_ratio);
void decompress_and_save_video(void* videoslim, const char* compressed_location, const char* output_location);

#ifdef __cplusplus
}
#endif

#endif // VIDEOSLIM_H
