cmake_minimum_required(VERSION 3.22)
project(EDD-CURIOSITY-2023 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(EDD-CURIOSITY-2023 main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
