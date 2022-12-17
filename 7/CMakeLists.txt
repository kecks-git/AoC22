add_executable(7 Part1.cpp)

target_link_libraries(7 PUBLIC lib)
target_include_directories(7 PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/lib"
                          )