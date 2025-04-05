add_library(jvm
    class_file/class_file.c
    constant_pool/constant_pool.c
    memory/heap.c
    memory/pointer.c
    util/file_util.c
)
target_include_directories(jvm PUBLIC ${CMAKE_SOURCE_DIR}/include)