cmake_minimum_required(VERSION 3.10)
project(toy_jvm)

set(CMAKE_C_STANDARD 99)

add_subdirectory(src)

add_executable(toyjvm main.c)
target_link_libraries(toyjvm jvm)

include(CTest)
enable_testing()
add_subdirectory(test)

configure_file(
        test/resources/compiled_class_files/EmptyMain.class
        ${CMAKE_BINARY_DIR}/resources/compiled_class_files/EmptyMain.class
        COPYONLY)