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

/**
 * Definitions
 */

#define UNUSED \
       	__attribute__((unused))


/**
 * Global variables for handling errors
 */

extern int error_code[];
extern char *error_type[];

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

void error_handler(int, const char *);
int ifmontyfile(char *filename);
int isInteger(char *str);

/**
 * prototypes for functions in string_utilities.c
 */

char *_strdup(char *);

/**
 * prototypes for functions in memalloc_free.c
 */

void freedoubleptr(char **, int);

/**
 * prototypes for functions in file_handline.c
 */
int readfile_exec(int);
char **tokenize_opcode(char *str, size_t *);

#endif /* MONTY_H */
