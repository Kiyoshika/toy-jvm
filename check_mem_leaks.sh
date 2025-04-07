find build/test -type f -perm /u=x,g=x,o=x -exec valgrind --leak-check=full --error-exitcode=-1 {} \;
