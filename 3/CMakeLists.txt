add_executable(3 Part2.cpp)

target_link_libraries(3 PUBLIC lib)
target_include_directories(3 PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/lib"
                          )