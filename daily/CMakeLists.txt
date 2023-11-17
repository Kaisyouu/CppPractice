set(DAILY_SOURCES
    daily_test.cpp
)

add_executable(daily_test ${DAILY_SOURCES})

target_include_directories(daily_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ../utils)

# 设置可执行文件输出路径
set_target_properties(daily_test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)