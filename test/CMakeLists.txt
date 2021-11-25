include(GoogleTest)

add_executable(
  google_test_example_test
  src/assertions.cpp
  src/fibonacci_test.cpp
  src/insertion_sort_test.cpp
  src/main.cpp)

target_link_libraries(
  google_test_example_test
  PRIVATE
  google_test_example_library
  gtest)

gtest_discover_tests(
  google_test_example_test
  WORKING_DIRECTORY
  ${google_test_example_project_SOURCE_DIR})
