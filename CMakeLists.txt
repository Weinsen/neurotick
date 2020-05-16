cmake_minimum_required(VERSION 3.1)

project(neurotick)

set(CMAKE_CXX_STANDARD 11)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/source
)

file(GLOB main_SRCS
    "${PROJECT_SOURCE_DIR}/include/*.h"
    "${PROJECT_SOURCE_DIR}/include/*.hpp"
    "${PROJECT_SOURCE_DIR}/source/*.cpp"
    "${PROJECT_SOURCE_DIR}/source/*.c"
    )

add_library(neurotick ${main_SRCS} )

install(TARGETS neurotick
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)

add_subdirectory(examples/block_race)

#add_executable(ntk ${main_SRCS} main.cpp)
add_executable(ntk main.cpp)
target_link_libraries(ntk neurotick)
