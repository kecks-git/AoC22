add_executable(6 Part1.cpp)

target_link_libraries(6 PUBLIC lib)
target_include_directories(6 PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/lib"
                          )