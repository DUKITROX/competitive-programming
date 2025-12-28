#!/bin/bash

# Compile the C++ program
g++ -o my_program 1.cpp

# Iterate over each .in file in the level1 folder
for input_file in level2/*.in; do
  # Extract the base name of the file (without extension)
  base_name=$(basename "$input_file" .in)
  
  # Define the output file name
  output_file="level2/${base_name}.out"
  
  # Run the program with the input file and redirect the output to the output file
  ./my_program < "$input_file" > "$output_file"
done