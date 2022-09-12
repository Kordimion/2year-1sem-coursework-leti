cmake_minimum_required(VERSION 3.14)

project(StrategyGame)

find_package(Curses REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})