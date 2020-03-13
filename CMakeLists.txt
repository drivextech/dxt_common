cmake_minimum_required(VERSION 3.1.8)
project(dxt_common VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(${PROJECT_SOURCE_DIR})

add_library(dxt_common
    marshalling/packer.c)
target_include_directories(dxt_common PUBLIC ${PROJECT_SOURCE_DIR})

add_subdirectory(tests)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
