cmake_minimum_required(VERSION 3.29.0)

project(LearnOpenCv)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(LearnOpenCv annotations.cpp)

target_link_libraries(LearnOpenCv ${OpenCV_LIBS})

