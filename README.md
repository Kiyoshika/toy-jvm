# Toy JVM

This is a toy research project for me to deeply understand the JVM and how it works.

This repo is an attempted implementation of a Java 8 JVM according to the specification (
loosely): https://docs.oracle.com/javase/specs/jvms/se8/html/index.html

This is NOT meant to be a complete implementation, but at least a barebones working JVM that can handle some simple to
intermediate Java applications using at least a subset of the standard library and core Java 8 features.

## Development

This is a C99 CMake project. CLion is used for actual development but can be ran with any typical CMake build (command
line or your own editor.)