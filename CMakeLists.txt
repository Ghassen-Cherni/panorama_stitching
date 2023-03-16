CMAKE_MINIMUM_REQUIRED (VERSION 3.16.0)
project( opencv_tutorial)

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR})
add_executable( opencv_tut main.cpp sift_extractor.cpp)
target_link_libraries(opencv_tut ${OpenCV_LIBS})