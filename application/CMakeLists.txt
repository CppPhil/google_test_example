add_executable(google_test_example_app src/main.cpp)

target_link_libraries(
  google_test_example_app
  PRIVATE
  google_test_example_library)
