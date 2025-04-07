#!/bin/bash
set -e

EXIT_CODE=0

for test_bin in $(find build/test -type f -perm /111); do
  echo "Running valgrind on $test_bin"
  valgrind --leak-check=full --error-exitcode=1 "$test_bin" || EXIT_CODE=1
done

exit $EXIT_CODE

