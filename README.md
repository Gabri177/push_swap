# Push_Swap Project

## Introduction

`push_swap` is a highly efficient sorting project that forms part of the 42 school curriculum, challenging students to create an algorithm that sorts data with a limited set of operations and the smallest possible number of moves. This project not only emphasizes the efficiency of algorithms but also their implementation in a practical scenario. Using the radix sort algorithm, this version of `push_swap` optimizes the sorting process for large datasets.

## Objective

The objective of the `push_swap` project is to sort a stack of unique integers, using two stacks and a limited set of operations: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, and `rrr`. The challenge is to do this with the least possible number of operations, leveraging the radix sort algorithm for optimal performance.

## Technologies & Languages Used

- **Language:** C
- **Key Concepts:** Stack Sorting, Algorithm Optimization, Radix Sort Algorithm
- **Compilation:** Makefile for compilation and project management
- **Supported OS:** Unix/Linux-based systems

## Features

- Implements radix sort algorithm for efficient sorting.
- Outputs a list of operations that sort the stack of integers.
- Includes a `checker` program to validate the list of operations.
- Optimized for performance and minimizing the number of operations.

## Usage

1. **Compilation**: Use the Makefile to compile both `push_swap` and `checker` programs. Simply run `make` in the project directory.
2. **Sorting**: Execute `./push_swap` with a list of integers as arguments to sort them. The program will output the operations required to sort the list.
3. **Checking**: Run `./checker` with the same list of integers, then input the operations from `push_swap`. `checker` will confirm if the list is sorted.

Example:

```bash
# Compile the programs
make

# Run push_swap to get operations
./push_swap 2 1 3 6 5 8

# Use checker to verify the operations
./checker 2 1 3 6 5 8
```
