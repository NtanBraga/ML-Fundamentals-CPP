cmake_minimum_required(VERSION 4.3.4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
set(CMAKE_DOWNLOAD_DEPENDENCIES ON)

project(ML-C++)

set(BUILD_TESTING OFF)
set(BUILD_TESTS OFF)
set(BUILD_CLI_EXECUTABLES OFF)
set(BUILD_PYTHON_BINDINGS OFF)
set(BUILD_FLASHLIGHT OFF)
set(USE_AVX_INSTRUCTIONS ON)
set(ENABLE_CUDA OFF FORCE)

set(EIGEN_BUILD_TESTING OFF)
set(EIGEN_MPL2_ONLY ON)
set(EIGEN_BUILD_PKGCONFIG OFF)
set(EIGEN_BUILD_DOC OFF)

set(DLIB_BUILD_WITH_TESTS OFF)
set(DLIB_NO_GUI_SUPPORT ON)
set(DLIB_USE_CUDA OFF)
set(DLIB_JPEG_SUPPORT OFF)   
set(DLIB_PNG_SUPPORT OFF)    
set(DLIB_GIF_SUPPORT OFF) 

set(HDF5_USE_STATIC_LIBRARIES ON)
set(HDF5_BUILD_EXAMPLES OFF)
set(HDF5_BUILD_HL_LIB ON)
set(HDF5_BUILD_FORTRAN OFF)
set(HDF5_BUILD_JAVA OFF)
set(HDF5_BUILD_CPP_LIB ON)

set(HIGHFIVE_USE_EIGEN ON)
set(HIGHFIVE_USE_OPENCV ON)
set(HIGHFIVE_BUILD_DOCS OFF)

set(JUST_INSTALL_CEREAL ON) 
set(SKIP_PORTABILITY_TEST ON)

set(FL_BUILD_DISTRIBUTED OFF CACHE BOOL "Disable distributed training" FORCE)
set(FL_USE_CPU ON FORCE)
set(FL_USE_CUDA OFF CACHE BOOL "" FORCE)
set(FL_BUILD_CUDA OFF FORCE)
set(FL_SEQUENCE_USE_CUDA OFF)
set(FL_BACKEND "CPU" CACHE BOOL "" FORCE)
set(FL_LIBRARIES_USE_CUDA OFF)
set(FL_BUILD_TESTS OFF)
set(FL_BUILD_EXAMPLES OFF)
set(FL_BUILD_CONTRIB OFF)

set(DNNL_BUILD_TESTS OFF)
set(DNNL_BUILD_EXAMPLES OFF)
set(DNNL_FOUND TRUE CACHE BOOL "" FORCE)
set(DNNL_VERSION "2.0.0" CACHE STRING "" FORCE)
set(DNNL_DIR "${dnnl_BINARY_DIR}" CACHE PATH "" FORCE)

file(WRITE "${CMAKE_BINARY_DIR}/DNNLConfig.cmake" "
    set(DNNL_FOUND TRUE)
    set(DNNL_VERSION \"2.0.0\")
    set(DNNL_VERSION_STRING \"2.0.0\")
")

file(WRITE "${CMAKE_BINARY_DIR}/DNNLConfigVersion.cmake" "
    set(PACKAGE_VERSION \"2.0.0\")
    set(PACKAGE_VERSION_COMPATIBLE TRUE)
    set(PACKAGE_VERSION_EXACT TRUE)
")

if(NOT TARGET MPI::MPI_C)
    add_library(MPI::MPI_C INTERFACE IMPORTED)
endif()
if(NOT TARGET MPI::MPI_CXX)
    add_library(MPI::MPI_CXX INTERFACE IMPORTED)
endif()

set(MPI_C_FOUND TRUE CACHE BOOL "" FORCE)
set(MPI_CXX_FOUND TRUE CACHE BOOL "" FORCE)
set(MPI_FOUND TRUE CACHE BOOL "" FORCE)
set(MPI_C_INCLUDE_PATH "" CACHE STRING "" FORCE)
set(MPI_CXX_INCLUDE_PATH "" CACHE STRING "" FORCE)
set(MPI_C_LIBRARIES "MPI::MPI_C" CACHE STRING "" FORCE)
set(MPI_CXX_LIBRARIES "MPI::MPI_CXX" CACHE STRING "" FORCE)

list(INSERT CMAKE_PREFIX_PATH 0 "${CMAKE_BINARY_DIR}")


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
FetchContent_Declare(
    armadillo
    GIT_REPOSITORY https://gitlab.com/armadillo-lib/armadillo-code.git
    GIT_TAG 15.6.0
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)
FetchContent_Declare(
    ensmallen
    GIT_REPOSITORY https://github.com/mlpack/ensmallen.git
    GIT_TAG 3.11.1
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)
FetchContent_Declare(
    cereal
    GIT_REPOSITORY https://github.com/USCiLab/cereal.git
    GIT_TAG v1.3.2
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)
FetchContent_Declare(
    mlpack
    GIT_REPOSITORY https://github.com/mlpack/mlpack.git
    GIT_TAG 4.8.0
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)
FetchContent_Declare(
    dnnl
    GIT_REPOSITORY https://github.com/uxlfoundation/oneDNN.git
    GIT_TAG v2.0
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)
FetchContent_Declare(
    flashlight
    GIT_REPOSITORY https://github.com/flashlight/flashlight.git
    GIT_TAG v0.3.2
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)
FetchContent_Declare(
    hdf5
    GIT_REPOSITORY https://github.com/HDFGroup/hdf5.git
    GIT_TAG 2.2.0
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)
FetchContent_Declare(
    highfive
    GIT_REPOSITORY https://github.com/highfive-devs/highfive.git
    GIT_TAG v3.3.0
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)
FetchContent_Declare(
    nlohmann
    GIT_REPOSITORY https://github.com/nlohmann/json
    GIT_TAG v3.12.0
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)
FetchContent_Declare(
    fast_csv_parser
    GIT_REPOSITORY https://github.com/ben-strasser/fast-cpp-csv-parser.git
    GIT_TAG master
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)

list(POP_BACK CMAKE_MESSAGE_INDENT)
message(CHECK_PASS "FETCHED")

#DEPENDENCIES
FetchContent_MakeAvailable(xtl armadillo cereal dnnl hdf5)

if(TARGET armadillo)
    install(TARGETS armadillo EXPORT ensmallenTargets)
    export(TARGETS armadillo FILE "${CMAKE_CURRENT_BINARY_DIR}/armadilloTargets.cmake")
endif()

set(ARMADILLO_INCLUDE_DIR ${armadillo_SOURCE_DIR}/include)
set(ARMADILLO_LIBRARY armadillo)
set(Armadillo_Found TRUE)

if(TARGET armadillo AND NOT TARGET Armadillo::Armadillo)
    add_library(Armadillo::Armadillo ALIAS armadillo)
endif()

set(CEREAL_INCLUDE_DIR ${cereal_SOURCE_DIR}/include)
set(CEREAL_LIBRARY cereal)
set(Cereal_Found TRUE)

set(HDF5_INCLUDE_DIR ${hdf5_SOURCE_DIR}/include)
set(HDF5_LIBRARY hdf5)
set(HDF5_Found TRUE)

if(TARGET hdf5-static AND NOT TARGET HDF5::HDF5)
    add_library(HDF5::HDF5 ALIAS hdf5-static)
elseif(TARGET hdf5-shared AND NOT TARGET HDF5::HDF5)
    add_library(HDF5::HDF5 ALIAS hdf5-shared)
elseif(TARGET hdf5 AND NOT TARGET HDF5::HDF5)
    add_library(HDF5::HDF5 ALIAS hdf5)
endif()

set(HIGHFIVE_FIND_HDF5 OFF CACHE BOOL "Prevent HighFive from searching system HDF5" FORCE)


if(TARGET dnnl AND NOT TARGET DNNL::dnnl)
    add_library(DNNL::dnnl ALIAS dnnl)
endif()

FetchContent_MakeAvailable(ensmallen)
set(ENSMALLEN_INCLUDE_DIR ${ensmallen_SOURCE_DIR}/include)
set(ENSMALLEN_LIBRARY ensmallen)
set(Ensmallen_Found TRUE)

#LIBRARIES
FetchContent_MakeAvailable(Eigen3 xtensor xtensor-blas blaze dlib
                        mlpack flashlight highfive nlohmann fast_csv_parser)

#https://github.com/arrayfire/arrayfire/wiki/Build-Instructions-for-Linux#installing-arrayfire

#ArrayFire muito pesado para ser usado fetchcontent
find_package(ArrayFire REQUIRED)


#MATRIZES

add_executable(EigenMatrizes src/chapter1/matrizes/EigenMatrizes.cpp)
target_link_libraries(EigenMatrizes PRIVATE Eigen3::Eigen)

add_executable(XTensorMatrizes src/chapter1/matrizes/XTensorMatrizes.cpp)
target_link_libraries(XTensorMatrizes PRIVATE xtensor xtensor-blas)

add_executable(BlazeMatrizes src/chapter1/matrizes/BlazeMatrizes.cpp)
target_link_libraries(BlazeMatrizes PRIVATE blaze)

add_executable(ArrayFireMatrizes src/chapter1/matrizes/ArrayFireMatrizes.cpp)
target_link_libraries(ArrayFireMatrizes PRIVATE ArrayFire::af)

add_executable(DlibMatrizes src/chapter1/matrizes/DlibMatrizes.cpp)
target_link_libraries(DlibMatrizes PRIVATE dlib)


#REGRESSÃO LINEAR

add_executable(EigenRegression src/chapter1/linear_regression/EigenRegression.cpp)
target_link_libraries(EigenRegression PRIVATE Eigen3::Eigen)

add_executable(BlazeRegression src/chapter1/linear_regression/BlazeRegression.cpp)
target_link_libraries(BlazeRegression PRIVATE blaze)

add_executable(ArrayFireRegression src/chapter1/linear_regression/ArrayFireRegression.cpp)
target_link_libraries(ArrayFireRegression PRIVATE ArrayFire::af)

add_executable(DlibRegression src/chapter1/linear_regression/DlibRegression.cpp)
target_link_libraries(DlibRegression PRIVATE dlib)
