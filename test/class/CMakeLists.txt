add_executable(class_file_test class_file_test.c)
target_include_directories(class_file_test PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(class_file_test jvm)
add_test(NAME class_file_test COMMAND class_file_test)