find src/ -iname '*.c' | xargs clang-format --style=Mozilla -i
find include/ -iname '*.h' | xargs clang-format --style=Mozilla -i
