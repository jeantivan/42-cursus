#!/bin/bash

test_cases=("5" "10" "100" "500" "1000")
test_n="20"

BACKGROUND="\033[44;37m"
GREEN="\033[0;32m"
RED="\033[0;31m"
NC="\033[0m" 

printf "\n        push_swap_tester      \n"

i=0
for test_case in "${test_cases[@]}"
do
    printf "\n${BACKGROUND}      Testing with $test_case args          ${NC}\n"
    printf "\n"
    i=0
    while [ $i -lt $test_n ]
    do
        args=$(shuf -i 0-$test_case -n $test_case | tr '\n' ' ')
        checker=$(./push_swap $args | ./checker_linux $args)
        res="Checker: $checker | Mov: [$(./push_swap $args | wc -l)]"
        if [ "$checker" == "OK" ]; then
            echo -n -e "${GREEN}${res}${NC}"
        else
            echo -n -e "${RED}${res}${NC}"
        fi
        echo ""
        ((i++))
    done
done
