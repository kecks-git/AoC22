add_executable(2 Part2.cpp)

target_link_libraries(2 PUBLIC lib)
target_include_directories(2 PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/lib"
                          )