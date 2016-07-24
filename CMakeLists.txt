cmake_minimum_required(VERSION 2.6)
project(InverseScale)


set(CMAKE_INCLUDE_CURRENT_DIR ON)



set(SOURCE_FILES
        InverseScale/InverseScale.cpp
        InverseScale/InverseScale.h
        InverseScale/pluginMain.cpp)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Sorry, this is hardcoded
set(CMAKE_MODULE_PATH /media/miller/BAGHEERA/cadaver/CMAKE)


find_package(Maya REQUIRED)

include_directories(${MAYA_INCLUDE_DIR})
link_directories(${MAYA_LIBRARY_DIR})

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${MAYA_LIBRARIES})

MAYA_PLUGIN(${PROJECT_NAME})

