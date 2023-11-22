cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(utils)
find_package(OpenCV REQUIRED)

# 头文件路径
include_directories(${OpenCV_INCLUDE_DIRS} ./) 

# 库文件路径
link_directories(${OpenCV_LIB_DIR})


SET(UTILS_LIB_SRC math_utils.cpp)

add_library(utils ${UTILS_LIB_SRC})

target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

