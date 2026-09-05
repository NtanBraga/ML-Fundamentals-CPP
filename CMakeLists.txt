cmake_minimum_required(VERSION 4.3.4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(ML-C++)

message(CHECK_START "Fetching Packages")
list(APPEND CMAKE_MESSAGE_INDENT "  ")

include(FetchContent)
FetchContent_Declare(
    Eigen3
    GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
    GIT_TAG 5.0.1
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
    FIND_PACKAGE_ARGS NAMES Eigen3 CONFIG
)
FetchContent_Declare(
    xtl
    GIT_REPOSITORY https://github.com/xtensor-stack/xtl.git
    GIT_TAG 0.8.2
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
    FIND_PACKAGE_ARGS NAMES xtl CONFIG
)
FetchContent_Declare(
    xtensor
    GIT_REPOSITORY https://github.com/xtensor-stack/xtensor.git
    GIT_TAG 0.27.1
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
    FIND_PACKAGE_ARGS NAMES xtensor CONFIG
)

set(BUILD_TESTING OFF)
set(EIGEN_BUILD_TESTING OFF)
set(EIGEN_MPL2_ONLY ON)
set(EIGEN_BUILD_PKGCONFIG OFF)
set(EIGEN_BUILD_DOC OFF)

list(POP_BACK CMAKE_MESSAGE_INDENT)
message(CHECK_PASS "FETCHED")

FetchContent_MakeAvailable(Eigen3 xtl xtensor)

add_executable(EigenMatrizes src/EigenMatrizes.cpp)
target_link_libraries(EigenMatrizes PRIVATE Eigen3::Eigen)

add_executable(XTensorMatrizes src/XTensorMatrizes.cpp)
target_link_libraries(XTensorMatrizes PRIVATE xtensor)
