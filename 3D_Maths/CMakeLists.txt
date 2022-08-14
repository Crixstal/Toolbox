cmake_minimum_required(VERSION 3.9...3.23)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

set(CMAKE_CXX_STANDARD 20 CACHE STRING "Language standard" FORCE)
set(CMAKE_CXX_STANDARD_REQUIRED ON CACHE BOOL "Use the C++ standard" FORCE)
set(CMAKE_CXX_EXTENSIONS OFF CACHE BOOL "" FORCE)

project(3D_Maths
        LANGUAGES CXX C
        VERSION 1.0
        DESCRIPTION "3D maths tools"
)

add_library(3D_Lib INTERFACE)
target_include_directories(3D_Lib
                           INTERFACE include
                           INTERFACE inline
)

add_executable(${PROJECT_NAME} 3D_unit_test.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE 3D_Lib)