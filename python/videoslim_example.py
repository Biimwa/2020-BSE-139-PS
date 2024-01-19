import ctypes

# Load the VideoSlim shared library
videoslim_lib = ctypes.CDLL('./libvideoslim_c.so')  # Adjust the path as needed

# Define the VideoSlim class
class VideoSlim:
    def __init__(self):
        # Create a VideoSlim object
        self.obj = videoslim_lib.VideoSlim_new()

    def record_and_compress_video(self, input_location, output_location, compression_ratio=0.5):
        # Call the recordAndCompressVideo function
        videoslim_lib.VideoSlim_recordAndCompressVideo(
            self.obj, input_location.encode('utf-8'), output_location.encode('utf-8'), compression_ratio
        )

    def decompress_and_save_video(self, compressed_video_location, output_location):
        # Call the decompressAndSaveVideo function
        videoslim_lib.VideoSlim_decompressAndSaveVideo(
            self.obj, compressed_video_location.encode('utf-8'), output_location.encode('utf-8')
        )

    def __del__(self):
        # Destroy the VideoSlim object
        videoslim_lib.VideoSlim_delete(self.obj)

# Example usage
if __name__ == "__main__":
    videoslim = VideoSlim()

    # Specify the location to save the compressed video
    compressed_output_location = "compressed_video.mp4"  # Change the extension as needed

    # Record, compress, and save the video
    videoslim.record_and_compress_video("camera", compressed_output_location)

    # Specify the location to save the decompressed video
    decompressed_output_location = "decompressed_video.avi"  # Change the extension as needed

    # Decompress and save the video
    videoslim.decompress_and_save_video(compressed_output_location, decompressed_output_location)
