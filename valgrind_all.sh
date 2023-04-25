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

for input_file in $(ls tests/*.in | sort -n -t / -k 2); do
    echo -n "Testing $input_file"
    $VALGRIND $PROGRAM < "$input_file" >/dev/null 2>&1
    if [ $? -eq 0 ]; then
        echo " == PASSED"
    else
        RETVAL=1
        echo " == FAILED"
        break
    fi
done
exit $RETVAL
