add_library(jvm
    memory/heap.c
    memory/pointer.c
    class/class_file.c
)
target_include_directories(jvm PUBLIC ${CMAKE_SOURCE_DIR}/include)