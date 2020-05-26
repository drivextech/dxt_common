cmake_minimum_required(VERSION 3.1.8)
project(dxt_common VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(${PROJECT_SOURCE_DIR})

add_library(dxt_common STATIC
    marshalling/packer.c)
target_include_directories(dxt_common PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>)

add_subdirectory(tests)



set(SUB_INC_DIRS "types" "marshalling")
file(GLOB PUB_HEADER_FILES
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    "types/*.h" "types/*.hpp"
    "marshalling/*.h" "marshalling/*.hpp")
# set_target_properties(tdoa_locator kf_locator dxt_locator
#     PROPERTIES PUBLIC_HEADER "${PUB_HEADER_FILES}"
# )


export(TARGETS dxt_common
    NAMESPACE dxt::
    FILE dxt_common-targets.cmake)


install(TARGETS
    dxt_common
    EXPORT dxt_common
    ARCHIVE DESTINATION lib
    PUBLIC_HEADER DESTINATION include)
foreach(sub_inc_dir ${SUB_INC_DIRS})
install(DIRECTORY ${sub_inc_dir}
    DESTINATION include/${PROJECT_NAME}
    FILES_MATCHING
    PATTERN "*.h"
    PATTERN "*.hpp"
)
endforeach()

install(EXPORT dxt_common NAMESPACE dxt:: DESTINATION lib/cmake/)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
