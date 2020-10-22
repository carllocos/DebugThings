cmake_minimum_required( VERSION 3.0 )

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
add_library(serialib STATIC ./libs/serialib/src/serialib.cpp)
target_include_directories(serialib
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/serialib/include/
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/serialib/src
  )


#linking with libs
target_link_libraries(DebugThings
  PRIVATE
    serialib
    )

