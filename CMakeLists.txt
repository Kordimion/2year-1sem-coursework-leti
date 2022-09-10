cmake_minimum_required(VERSION 3.22)

project(StragegyGame)

find_package(Curses REQUIRED)

set (FLUX flux_cpp)
add_library(${FLUX} SHARED external/flux_cpp/include/flux_cpp.h)
set_target_properties(${FLUX} PROPERTIES LINKER_LANGUAGE CXX)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES} ${FLUX})