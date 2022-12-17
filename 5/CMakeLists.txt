add_executable(5 Part1.cpp)

target_link_libraries(5 PUBLIC lib)
target_include_directories(5 PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/lib"
                          )