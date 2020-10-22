cmake_minimum_required( VERSION 3.4 )

project( DebugThings VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(DebugThings ./src/main.cpp)


# seting the include directories
target_include_directories(DebugThings 
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
  )

# 3th party libraries


#serialib
add_subdirectory(./libs/serialib/)

target_link_libraries(DebugThings
  PRIVATE
    serialib
    )

