add_library(jvm
        class_file/class_file.c
        class_file/field.c
        class_file/constant_pool/constant_pool.c
        memory/heap.c
        memory/pointer.c
        util/file_util.c
)
target_include_directories(jvm PUBLIC ${CMAKE_SOURCE_DIR}/include)