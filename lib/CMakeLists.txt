cmake_minimum_required(VERSION 3.0)
project(godll)

set(CMAKE_CXX_STANDARD 14)

if (UNIX)
    add_library(godll SHARED linux/linux_library.cpp)
    target_include_directories(godll PUBLIC ${CMAKE_SOURCE_DIR}/shared)
    add_executable(test linux/linux_library_test.cpp)
    target_link_libraries(test dl)
    target_include_directories(test PUBLIC ${CMAKE_SOURCE_DIR}/shared)
else()
    add_library(godll SHARED win/win_library.cpp)
    add_executable(test win/win_library_test.cpp)
endif()

