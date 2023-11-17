cmake_minimum_required(VERSION 3.21)
project(CppPractice)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 创建bin目录
file(MAKE_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# 添加子目录
add_subdirectory(daily)
add_subdirectory(utils)
