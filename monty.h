#ifndef MONTY_H
#define MONTY_H

/**
 * system library header files
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * Definitions
 */

#define UNUSED \
       	__attribute__((unused))

#define _POSIX_C_SOURCE 200809L

/**
 * Global variables for handling errors
 */

extern int stack_number;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * prototypes for functions in error_handler0.c
 */

void error_handler(int, const char *, int);
int ifmontyfile(char *filename);
int isInteger(char *str);


/**
 * prototypes for functions in string_utilities.c
 */
char *_strdup(char *);
ssize_t _getline(char **, size_t *, FILE *);

/**
 * prototypes for functions in memalloc_free.c
 */

void freedoubleptr(char **, int);

/**
 * prototypes for functions in file_handline.c
 */
int readfile_exec(char *);
char **tokenize_opcode(char *str, size_t *);
void opcode_exec(char **, int, stack_t **);

/**
 * function in error type
 */
char *error_type(int);


/**
 * functions for operators
 */

void push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);


#endif /* MONTY_H */
