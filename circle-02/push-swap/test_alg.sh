#!/bin/bash

test_cases=("100" "500")
test_n="10"

i=0

for test_case in "${test_cases[@]}"
do
    echo -n "n=$test_case "
    i=0
    while [ $i -lt $test_n ]
    do
        
        echo -n "$(./push_swap $(shuf -i 1-$test_case -n $test_case | tr '\n' ' ') | wc -l) "
        ((i++))
    done
    echo ""
done
