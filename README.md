### Introduction
From project's Subject:
"Introduction: The Push swap project is a very simple and a highly straightforward algorithm project: data must be sorted.
You have at your disposal a set of integer values, 2 stacks, and a set of instructions to manipulate both stacks.
Your goal? Write a program in C called push_swap which calculates and displays on the standard output the smallest program, made of Push swap language instructions, that sorts the integers received as arguments.
Easy? We’ll see... Objectives: Writing a sorting algorithm is always a very important step in a developer’s journey. It is often the first encounter with the concept of complexity.
Sorting algorithms and their complexity are part of the classic questions discussed during job interviews. It’s probably a good time to look at these concepts since you’ll have to face them at some point.
The learning objectives of this project are rigor, use of C, and use of basic algorithms. Especially focusing on their complexity.
Sorting values is simple. To sort them the fastest way possible is less simple. Especially because from one integers configuration to another, the most efficient sorting solution... "
## Authors

Group project by [Ani Mema](https://github.com/amema42) and [Jacopo Cardinaux](https://github.com/raviolotto).

# Push Swap

## Overview

The Push Swap project is a sorting algorithm challenge designed for the 42 school. The goal is to sort a list of integers using a limited set of operations and two stacks. This project involves creating an efficient sorting algorithm, often used in competitive programming to optimize sorting operations.


## Table of Contents
- [Introduction](#introduction)
- [authors](#authors)
- [Files and Directories](#files-and-directories)
- [Compilation and Execution](#compilation-and-execution)
- [Program Logic](#program-logic)
- [Usage](#usage)
- [Operations](#operations)
- [Algorithm Explanation](#algorithm-explanation)
- [Managing Stacks `a` and `b`](#managing-stacks-a-and-b)
- [Bonus](#bonus)
- [Testing and Debugging](#testing-and-debugging)
- [Conclusion](#conclusion)

## Files and Directories

- **Makefile**: Script for compiling the project.
- **push_swap.c**: Main entry point for the push_swap program.
- **push_swap.h**: Header file containing declarations and macros.
- **init_b.c, list_init.c, listutils.c, ok_input.c**: Initialization and utility functions.
- **order_3n5.c**: Logic for sorting small sets of numbers.
- **workutils.c**: Additional utility functions.
- **algoritm/**: Directory containing the main algorithm implementation.
  - **best_move.c, inst_reader.c**: Functions to calculate the best moves and read instructions.
- **bonus/**: Directory containing the bonus checker program.
  - **checker.c, checker.h**: Source code and header for the checker.
- **ft_printf/**: Directory containing a custom printf implementation.
  - **Makefile, ft_printf.c, ft_printf.h**: Source and header files for ft_printf.
- **gnl/**: Directory containing the get_next_line implementation.
  - **get_next_line.c, get_next_line.h**: Source and header files for get_next_line.
- **libft/**: Directory containing standard library functions.
  - **Makefile, *.c, *.h**: Source and header files for libft.
- **moves/**: Directory containing the push_swap operations.
  - **moves_p.c, moves_r.c, moves_rr.c, moves_s.c**: Push, rotate, reverse rotate, and swap operations.

## Compilation and Execution

### Compilation

To compile the project, simply run the following command in the root directory:

```bash
make
```

This will generate an executable named `push_swap`.

### Execution

To run the `push_swap` program with a list of integers:

```bash
./push_swap [list_of_integers]
```

Example:

```bash
./push_swap 3 2 1
```

## Program Logic

### Initialization

1. **Input Validation**: The program first validates the input to ensure all arguments are integers and within the valid range.
2. **List Initialization**: Initializes the stacks `a` and `b` using the provided list of integers.

### Main Loop

The core logic involves repeatedly choosing the best operation to move elements from stack `a` to stack `b` and then back to stack `a` in sorted order.

### Cleanup

After sorting, the program frees all allocated memory to avoid memory leaks.

## Usage

The `push_swap` program generates a sequence of operations to sort the stack:

- **sa**: Swap the first two elements at the top of stack `a`.
- **sb**: Swap the first two elements at the top of stack `b`.
- **ss**: `sa` and `sb` at the same time.
- **pa**: Push the top element of `b` onto `a`.
- **pb**: Push the top element of `a` onto `b`.
- **ra**: Rotate stack `a` (shift up all elements by 1).
- **rb**: Rotate stack `b` (shift up all elements by 1).
- **rr**: `ra` and `rb` at the same time.
- **rra**: Reverse rotate stack `a` (shift down all elements by 1).
- **rrb**: Reverse rotate stack `b` (shift down all elements by 1).
- **rrr**: `rra` and `rrb` at the same time.

## Algorithm Explanation

### Small Set Sorting

For sets of 3 to 5 elements, specific predefined sequences are used to sort efficiently.

### Larger Set Sorting

1. **Chunking**: Divide the list into manageable chunks.
2. **Sorting**: Use a combination of operations to push the smallest elements to stack `b` and then push them back to stack `a` in sorted order.
3. **Optimization**: Calculate the best move using cost analysis to minimize the number of operations.

### Best Move Calculation

- **best_move.c**: Implements the logic to determine the most efficient move at each step.
- **inst_reader.c**: Reads and interprets the instructions for operations.

## Managing Stacks `a` and `b`

The `push_swap` algorithm utilizes two stacks, `a` and `b`, to sort a list of integers. The main goal is to move elements between these stacks using a limited set of operations to achieve a sorted order in stack `a`.

#### Initialization

1. **Input Parsing**: The program reads a list of integers from the command line and stores them in stack `a`. Stack `b` is initially empty.
2. **Validation**: The input is validated to ensure all elements are integers and there are no duplicates.

#### Operations

The algorithm uses a series of predefined operations to manipulate the stacks:

- **Push Operations**:
  - `pa`: Push the top element of stack `b` onto stack `a`.
  - `pb`: Push the top element of stack `a` onto stack `b`.

- **Swap Operations**:
  - `sa`: Swap the first two elements at the top of stack `a`.
  - `sb`: Swap the first two elements at the top of stack `b`.
  - `ss`: Perform `sa` and `sb` simultaneously.

- **Rotate Operations**:
  - `ra`: Rotate stack `a` (shift all elements up by 1, the first element becomes the last).
  - `rb`: Rotate stack `b` (shift all elements up by 1, the first element becomes the last).
  - `rr`: Perform `ra` and `rb` simultaneously.

- **Reverse Rotate Operations**:
  - `rra`: Reverse rotate stack `a` (shift all elements down by 1, the last element becomes the first).
  - `rrb`: Reverse rotate stack `b` (shift all elements down by 1, the last element becomes the first).
  - `rrr`: Perform `rra` and `rrb` simultaneously.

### Algorithm Steps

1. **Chunking**: The list in stack `a` is divided into smaller chunks. This helps in managing smaller subsets of the list, making it easier to sort.
2. **Pushing to Stack `b`**: Elements are moved from stack `a` to stack `b` in a way that allows easier sorting. The smallest elements are pushed first.
3. **Sorting Stack `b`**: Once stack `b` has all elements, it is sorted in descending order. This allows the elements to be pushed back to stack `a` in ascending order.
4. **Pushing Back to Stack `a`**: The sorted elements in stack `b` are moved back to stack `a`.

### Visualization

Below is a diagram illustrating the `push_swap` process:

```plaintext
Initial State:
Stack a: [4, 3, 2, 1]
Stack b: []

Step 1: pb (push 4 from a to b)
Stack a: [3, 2, 1]
Stack b: [4]

Step 2: pb (push 3 from a to b)
Stack a: [2, 1]
Stack b: [3, 4]

Step 3: sa (swap the first two elements in a)
Stack a: [1, 2]
Stack b: [3, 4]

Step 4: pb (push 1 from a to b)
Stack a: [2]
Stack b: [1, 3, 4]

Step 5: pb (push 2 from a to b)
Stack a: []
Stack b: [2, 1, 3, 4]

Step 6: pa (push 2 from b to a)
Stack a: [2]
Stack b: [1, 3, 4]

Step 7: pa (push 1 from b to a)
Stack a: [1, 2]
Stack b: [3, 4]

Step 8: ra (rotate stack a)
Stack a: [2, 1]
Stack b: [3, 4]

Step 9: pa (push 3 from b to a)
Stack a: [3, 2, 1]
Stack b: [4]

Step 10: pa (push 4 from b to a)
Stack a: [4, 3, 2, 1]
Stack b: []

Final State:
Stack a: [1, 2, 3, 4]
Stack b: []
```

## Bonus

The `bonus` directory contains a `checker` program that verifies the correctness of the sequence of operations generated by `push_swap`.

### Compilation

To compile the checker program, run:

```bash
make bonus
```

### Conclusion

The `push_swap` algorithm is an intricate process that involves using two stacks to sort a list of integers through a series of push, swap, rotate, and reverse rotate operations. By strategically moving elements between the stacks, the algorithm aims to minimize the number of operations needed to sort the list efficiently.
