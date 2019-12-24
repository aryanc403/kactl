#!/bin/zsh
file=${1:-a.cpp}
g++ -D ARYANC403=1 ${file} -o ${file}.out -fsanitize=address,undefined,signed-integer-overflow -Wall -std=gnu++17 && time ./${file}.out ${2}
g++ ${file} -o ${file}.out -std=gnu++14 && time ./${file}.out ${2}