cmake_minimum_required(VERSION 2.8.12)

project(CUESDK_WRAPPER LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS Core REQUIRED)

set(CUE_SDK_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/CUESDK/" CACHE PATH "CUESDK path")
set(CUE_SDK_INCLUDE_DIRECTORY "${CUE_SDK_DIRECTORY}/include" CACHE PATH "CUESDK include path")
set(CUE_SDK_REDIST_FILES "${CUESDK_DIRECTORY}/redist/i386/CUESDK_2013.dll" CACHE PATH "CUESDK redist files")

include_directories("${CUE_SDK_DIRECTORY}/include")

find_library(CUE_SDK_LIB CUESDK_2013 "${CUE_SDK_DIRECTORY}/lib/i386")

set(CUESDK_WRAPPER_SOURCES
    src/CueSdkWrapper.cpp
    src/Geometry.cpp
    src/Lighting.cpp
)

set(CCUESDK_WRAPPER_HEADERS
    src/CueSdkWrapper.h
    src/Geometry.h
    src/Lighting.h
)

add_library(${PROJECT_NAME} ${CUESDK_WRAPPER_SOURCES} ${CCUESDK_WRAPPER_HEADERS})

target_link_libraries(${PROJECT_NAME} Qt5::Core ${CUE_SDK_LIB})
