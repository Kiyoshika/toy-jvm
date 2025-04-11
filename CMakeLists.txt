cmake_minimum_required(VERSION 3.10)
project(toy_jvm C)

set(CMAKE_C_STANDARD 99)
add_subdirectory(src)

if(MSVC)
  # Force to always compile with W4
  if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  # Update if necessary
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")
endif()

add_executable(toyjvm main.c)
target_link_libraries(toyjvm jvm)

include(CTest)
enable_testing()
add_subdirectory(test)

configure_file(
        test/resources/compiled_class_files/EmptyMain.class
        ${CMAKE_BINARY_DIR}/resources/compiled_class_files/EmptyMain.class
        COPYONLY)
