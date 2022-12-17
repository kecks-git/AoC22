add_executable(4 Part1.cpp)

target_link_libraries(4 PUBLIC lib)
target_include_directories(4 PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/lib"
                          )