cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

Project(test)

find_package(OpenCV REQUIRED)

##下面是输出信息
message(STATUS "Opnecv ;ibrary status: ")
message(STATUS ">> version: ${OpenCV_VERSION} ")
message(STATUS ">> libraries: ${OpenCV_LIB_DIR} ")
message(STATUS ">> libraries: ${OpenCV_LIBS} ")
message(STATUS ">> include: ${OpenCV_INCLUDE_DIRS}  ")


# 头文件路径
include_directories(${OpenCV_INCLUDE_DIRS} utils) 

# 库文件路径
link_directories(${OpenCV_LIB_DIR})

add_subdirectory(utils)

# 源文件
SET (SRC main.cpp)

# 创建可执行程序
add_executable(${PROJECT_NAME} ${SRC})

# link
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} utils)