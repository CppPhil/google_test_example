add_library(
  google_test_example_library
  STATIC
  include/fibonacci.hpp
  include/insertion_sort.hpp
  src/fibonacci.cpp)

target_include_directories(
  google_test_example_library
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include)
