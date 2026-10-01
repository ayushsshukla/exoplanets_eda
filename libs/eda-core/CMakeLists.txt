add_library(eda-core STATIC src/core.cpp)

target_include_directories(eda-core
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)