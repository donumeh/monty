# Project Title: C - Stacks, Queues - LIFO, FIFO

## Overview

This is a group project in C programming focusing on the implementation of stacks and queues using doubly linked lists. The project involves creating a Monty interpreter, a scripting language that relies on a unique stack with specific instructions to manipulate it.

## Team Members
- Donald D
- Peter Ikpe Edidiong

## Learning Objectives

### General
- Understand the concepts of LIFO and FIFO
- Define and use stacks and queues
- Implement common operations for stacks and queues
- Recognize common use cases for stacks and queues
- Understand the proper use of global variables

## Requirements

### General
- Allowed Editors: vi, vim, emacs
- Compilation on Ubuntu 20.04 LTS using gcc with specific options
- File structure: Each file should end with a new line
- Mandatory README.md file at the project's root folder
- Code should follow the Betty style


### Data Structures
- Use provided data structures in the header file (stack_t and instruction_t)

### Compilation & Output
- Code compilation: `gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty`
- Output must be printed on stdout
- Error messages must be printed on stderr

## Monty Language
- Monty 0.98 is a scripting language compiled into Monty byte codes
- Monty byte code files have a .m extension
- Each line contains only one instruction
- Instructions can have leading/trailing spaces
- Blank lines or lines with additional text are ignored
- Monty program runs bytecodes line by line

### Monty Byte Code Files Examples

#### Example 1
```plaintext
push 0
push 1
push 2
pall
push 4
push 5
push 6
pall

