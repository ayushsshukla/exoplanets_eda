find_package(Catch2 REQUIRED)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(eda-tests test_main.cpp)

find_package(rapidcsv REQUIRED)

target_link_libraries(eda-tests
    PRIVATE
        eda-core
        Catch2::Catch2WithMain
        rapidcsv::rapidcsv
)

include(CTest)
include(Catch)
catch_discover_tests(eda-tests)