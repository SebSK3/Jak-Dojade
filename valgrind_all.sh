#!/bin/bash

VALGRIND="valgrind --leak-check=full --error-exitcode=1"
PROGRAM="./build/Jak_Dojade"
RETVAL=0

if [ ! -f "$PROGRAM" ]; then
    echo "Error: Program '$PROGRAM' not found."
    exit 1
fi

if [ $# -ne 0 ]; then
    echo "Usage: $0"
    exit 1
fi

for input_file in tests/*.in; do
    $VALGRIND $PROGRAM < "$input_file"
    if [ $? -eq 1 ]; then
        RETVAL=1
        break
    fi
done

exit $RETVAL
