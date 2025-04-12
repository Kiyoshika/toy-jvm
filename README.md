# Toy JVM

This is a toy research project for me to deeply understand the JVM and how it works.

This repo is an attempted implementation of a Java 8 JVM according to the specification (
loosely): https://docs.oracle.com/javase/specs/jvms/se8/html/index.html

This is NOT meant to be a complete implementation, but at least a barebones working JVM that can handle some simple to
intermediate Java applications using at least a subset of the standard library and core Java 8 features.

## Development
This is a C99 CMake project. 

* `mkdir build && cd build`
* `cmake -DCMAKE_BUILD_TYPE=Debug ..`
* `make`
* (optional) `make test` to run tests

This creates a `libjvm.a` library that contains the core JVM code and a `toy-jvm` executable (that is currently just a placeholder)

## Code Style
This repo uses the Mozilla style from `clang-format` (install with `sudo apt-get install clang-format`)

Use `style_code.sh` to run the formatter manually (there is also a github action that runs when merging into main to commit formatting changes)

## What's Being Worked On?
Parsing field attributes (`src/class_file/field.c`) which needs to implement all parse methods for each attribute (`src/class_file/attribute/attributes/`)

Code needs a little bit of restructuring (`src/` folder has slightly fallen out of order with `include/`)
