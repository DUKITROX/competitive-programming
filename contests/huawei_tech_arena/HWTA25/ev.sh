#!/bin/bash


# Uncomment to build (if needed)
# build.sh $1

sum=0
for ((i=0; i < $2; i++)); do
  ./gen > input
  ./$1 < input >> input 
  score=$(./test < input)
  sum=$(echo "$sum + $score" | bc -l)
done

avg=$(echo "$sum / $2" | bc -l)
printf "Average: %.6f\n" "$avg"

