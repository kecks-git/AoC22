set(DAY 9)

add_library(${DAY}_Impl)
target_sources(${DAY}_Impl PRIVATE rope.h rope.cpp)
target_link_libraries(${DAY}_Impl PUBLIC lib)
target_include_directories(${DAY}_Impl PUBLIC 
"${PROJECT_BINARY_DIR}"
"${PROJECT_SOURCE_DIR}/lib"
)

add_executable(${DAY} main.cpp)
target_link_libraries(${DAY} PRIVATE lib ${DAY}_Impl)
target_include_directories(${DAY} PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/lib"
                          )

add_executable(
    ${DAY}_Tests
  test.cpp
)
target_link_libraries(
    ${DAY}_Tests
  GTest::gtest_main
   ${DAY}_Impl)
  

include(GoogleTest)
gtest_discover_tests(${DAY}_Tests)
