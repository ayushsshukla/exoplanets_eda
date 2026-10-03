set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(eda-core STATIC src/core.cpp src/table.cpp)

find_package(rapidcsv REQUIRED)

target_link_libraries(eda-core
        PRIVATE
        rapidcsv::rapidcsv
)

target_include_directories(eda-core
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
)