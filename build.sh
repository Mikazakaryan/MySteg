#!/bin/bash

# Build the project
echo "Building the project..."

# Run qmake to generate the Makefile
qmake MySteg.pro

# Run make to compile the project
make

echo "Build complete."
