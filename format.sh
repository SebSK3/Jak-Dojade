#!/bin/bash

# Find all .cpp and .hpp files recursively in the src directory
files=$(find src -type f \( -name "*.cpp" -o -name "*.hpp" \))

# Loop through each file and run clang-format on it
for file in $files
do
    clang-format -i -style=file "$file"
done
