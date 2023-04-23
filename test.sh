#!/bin/bash
PROGRAM="./build/Jak_Dojade"

if [ ! -f "$PROGRAM" ]; then
    echo "Error: Program '$PROGRAM' not found."
    exit 1
fi

test_folder="tests"

exit_status=0
for input_file in "$test_folder"/*.in; do
    # Check if corresponding output file exists
    output_file="${input_file%.in}.out"
    if [ ! -f "$output_file" ]; then
        echo "Error: Output file '$output_file' not found."
        continue
    fi

    # Run the test and compare the output with the expected output
    exec 3< "$output_file"
    count=1
    while IFS= read -r line; do
        IFS= read -r expected <&3
        line="${line%"${line##*[![:space:]]}"}"
        expected="${expected%"${expected##*[![:space:]]}"}"
        if [[ "$line" != "$expected" ]]; then
            echo "Difference found in test $input_file, line $count:"
            echo "Expected: $expected"
            echo "Actual  : $line"
            exit_status=1
            break
        fi
        count=$((count + 1))
    done < <($PROGRAM < "$input_file")
    exec 3<&-
done

exit $exit_status