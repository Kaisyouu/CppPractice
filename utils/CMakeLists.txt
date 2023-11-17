# 查找 utils 模块的所有头文件
file(GLOB UTILS_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")

# 创建 utils 库
add_library(utils ${UTILS_HEADERS})

# 设置 utils 库的链接语言
set_target_properties(utils PROPERTIES LINKER_LANGUAGE CXX)

# 设置 utils 库的包含目录
target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})