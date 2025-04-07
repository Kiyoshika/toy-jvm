file(GLOB_RECURSE SOURCES "*.c")

add_library(jvm ${SOURCES})
target_include_directories(jvm PUBLIC ${CMAKE_SOURCE_DIR}/include)
