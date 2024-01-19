cmake_minimum_required(VERSION 3.10)
project(VideoSlim)

# Set the path to your OpenCV installation
set(OpenCV_DIR "C:\\Users\\KITECH Inc\\Desktop\\videoslim\\src\\opencv\\build")

# Include the CMake module path for finding OpenCV
list(APPEND CMAKE_MODULE_PATH "${OpenCV_DIR}")

# Find OpenCV
find_package(OpenCV REQUIRED)

# Add VideoSlim library target
add_library(videoslim_c SHARED
    videoslim.cpp  
    videoslim_internal.cpp
)

# Link OpenCV to the VideoSlim library
target_link_libraries(videoslim_c PRIVATE ${OpenCV_LIBS})

# Set installation directory (adjust as needed)
install(TARGETS videoslim_c LIBRARY DESTINATION lib)

# Export include directories
target_include_directories(videoslim_c PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include  # Include directory for header files
    ${OpenCV_INCLUDE_DIRS}  # Include OpenCV headers
)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
