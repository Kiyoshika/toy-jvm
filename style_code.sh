echo "Running code formatter..."
find src/ -iname '*.c' | xargs clang-format --style=Mozilla -i
find include/ -iname '*.h' | xargs clang-format --style=Mozilla -i
echo "Finished formatting."
