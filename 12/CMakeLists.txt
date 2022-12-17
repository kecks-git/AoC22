add_executable(12 Part1.cpp)

target_link_libraries(12 PUBLIC lib)
target_include_directories(12 PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/lib"
                          )