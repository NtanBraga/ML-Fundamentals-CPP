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
)
FetchContent_Declare(
    xtl
    GIT_REPOSITORY https://github.com/xtensor-stack/xtl.git
    GIT_TAG 0.8.2
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)
FetchContent_Declare(
    xtensor
    GIT_REPOSITORY https://github.com/xtensor-stack/xtensor.git
    GIT_TAG 0.27.1
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)
FetchContent_Declare(
    xtensor-blas
    GIT_REPOSITORY https://github.com/xtensor-stack/xtensor-blas.git
    GIT_TAG 0.23.0
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)
FetchContent_Declare(
    blaze
    GIT_REPOSITORY https://bitbucket.org/blaze-lib/blaze.git
    GIT_TAG v3.8.2
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)
FetchContent_Declare(
    dlib
    GIT_REPOSITORY https://github.com/davisking/dlib.git
    GIT_TAG v20.0.1
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)

set(BUILD_TESTING OFF)
set(EIGEN_BUILD_TESTING OFF)
set(EIGEN_MPL2_ONLY ON)
set(EIGEN_BUILD_PKGCONFIG OFF)
set(EIGEN_BUILD_DOC OFF)

set(USE_AVX_INSTRUCTIONS ON)
set(DLIB_BUILD_WITH_TESTS OFF)
set(DLIB_NO_GUI_SUPPORT ON)
set(DLIB_USE_CUDA OFF)
set(DLIB_JPEG_SUPPORT OFF)   
set(DLIB_PNG_SUPPORT OFF)    
set(DLIB_GIF_SUPPORT OFF) 

list(POP_BACK CMAKE_MESSAGE_INDENT)
message(CHECK_PASS "FETCHED")

FetchContent_MakeAvailable(Eigen3 xtl xtensor xtensor-blas blaze dlib)

#https://github.com/arrayfire/arrayfire/wiki/Build-Instructions-for-Linux#installing-arrayfire

#ArrayFire muito pesado para ser usado fetchcontent
find_package(ArrayFire REQUIRED)


add_executable(EigenMatrizes src/matrizes/EigenMatrizes.cpp)
target_link_libraries(EigenMatrizes PRIVATE Eigen3::Eigen)

add_executable(XTensorMatrizes src/matrizes/XTensorMatrizes.cpp)
target_link_libraries(XTensorMatrizes PRIVATE xtensor xtensor-blas)

add_executable(BlazeMatrizes src/matrizes/BlazeMatrizes.cpp)
target_link_libraries(BlazeMatrizes PRIVATE blaze)

add_executable(ArrayFireMatrizes src/matrizes/ArrayFireMatrizes.cpp)
target_link_libraries(ArrayFireMatrizes PRIVATE ArrayFire::af)

add_executable(DlibMatrizes src/matrizes/DlibMatrizes.cpp)
target_link_libraries(DlibMatrizes PRIVATE dlib)