cmake_minimum_required(VERSION 3.8)

project(google_test_example_project VERSION 1.0.0)

enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Threads REQUIRED)

if (WIN32)
  foreach (MODE "_DEBUG" "_MINSIZEREL" "_RELEASE" "_RELWITHDEBINFO")
    string(REPLACE "/MD" "/MT" TMP "${CMAKE_C_FLAGS${MODE}}")
    set(CMAKE_C_FLAGS${MODE} "${TMP}" CACHE STRING "" FORCE)
    string(REPLACE "/MD" "/MT" TMP "${CMAKE_CXX_FLAGS${MODE}}")
    set(CMAKE_CXX_FLAGS${MODE} "${TMP}" CACHE STRING "" FORCE)
  endforeach()
endif()

add_subdirectory(external/googletest)

add_subdirectory(library)
add_subdirectory(application)
add_subdirectory(test)
