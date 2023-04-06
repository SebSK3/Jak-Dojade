#!/bin/bash

VALGRIND="valgrind --leak-check=full"
PROGRAM="./build/Jak_Dojade"

if [ ! -f "$PROGRAM" ]; then
    echo "Error: Program '$PROGRAM' not found."
    exit 1
fi

if [ $# -ne 1 ]; then
    echo "Usage: $0 <test_number>"
    exit 1
fi

test_number=$1
input_file="./tests/${test_number}.in"

$VALGRIND $PROGRAM < "$input_file"