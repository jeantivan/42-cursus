#!/bin/bash

test_cases=("3")
test_n="10"

i=0

for test_case in "${test_cases[@]}"
do
    echo "n=$test_case "
    i=0
    while [ $i -lt $test_n ]
    do
        args=$(shuf -i 0-50 -n $test_case | tr '\n' ' ')
        echo "Args $args Checker: $(./push_swap $args | ./checker_linux $args)"
        echo "$(./push_swap $args |  tr '\n' ' ')"
        echo "Tot_mov $(./push_swap $args | wc -l)"
        echo ""
        ((i++))
    done
    echo ""
done
