cmake_minimum_required(VERSION 3.15...4.4)

project(exoplanet_eda
        VERSION 1.0
        DESCRIPTION "EDA for exoplanets - to silent my schizoid-ness"
        LANGUAGES CXX
)

add_subdirectory(libs/eda-core)
add_executable(eda src/main.cpp)
target_compile_features(eda PRIVATE cxx_std_23)

target_link_libraries(eda PRIVATE eda-core)