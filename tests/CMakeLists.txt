find_package(Catch2 REQUIRED)

add_executable(eda-tests test_main.cpp)

target_link_libraries(eda-tests
    PRIVATE
        eda-core
        Catch2::Catch2WithMain
)

include(CTest)
include(Catch)
catch_discover_tests(eda-tests)