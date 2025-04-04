add_executable(heap_test heap_test.c)
target_include_directories(heap_test PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(heap_test jvm)
add_test(NAME heap_test COMMAND heap_test)