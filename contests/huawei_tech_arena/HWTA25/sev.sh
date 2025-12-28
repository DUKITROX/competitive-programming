#!/bin/bash

#build.sh 1.cpp
cat sample1.in > input
./$1 < input >> input
sum=$(./test < input)
printf "Average: %.6f\n" "$sum"

