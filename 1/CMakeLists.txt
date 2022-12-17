add_executable(1 Part2.cpp)

target_link_libraries(1 PUBLIC lib)
target_include_directories(1 PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/lib"
                          )