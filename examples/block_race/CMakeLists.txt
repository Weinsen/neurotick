include_directories(
    ${PROJECT_SOURCE_DIR}/examples/block_race/include
    ${PROJECT_SOURCE_DIR}/examples/block_race/source
)

file(GLOB block_race_SRCS
    "${PROJECT_SOURCE_DIR}/examples/block_race/include/*.h"
    "${PROJECT_SOURCE_DIR}/examples/block_race/include/*.hpp"
    "${PROJECT_SOURCE_DIR}/examples/block_race/source/*.cpp"
    "${PROJECT_SOURCE_DIR}/examples/block_race/source/*.c"
    )

add_executable(block_race ${block_race_SRCS} main.cpp)
include_directories(${CMAKE_SOURCE_DIR}/include)
target_link_libraries(block_race neurotick)