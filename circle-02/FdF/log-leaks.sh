#!/bin/bash

if [ -n "$1" ]; then
  map="$1"
else
  map="./test_maps/42.fdf"
fi

valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./maps map2.ber > valgrind_output.txt 2>&1

grep -A 5 -B 5 "definitely lost" valgrind_output.txt > filtered_leaks.txt

rm -rf valgrind_output.txt
echo -e "\e[42;97m DONE \e[0m"