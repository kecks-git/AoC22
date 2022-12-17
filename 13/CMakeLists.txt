add_executable(13 Part1.cpp)

target_link_libraries(13 PUBLIC lib)
target_include_directories(13 PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/lib"
                          )