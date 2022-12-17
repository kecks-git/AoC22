add_executable(8 Part1.cpp)

target_link_libraries(8 PUBLIC lib)
target_include_directories(8 PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/lib"
                          )