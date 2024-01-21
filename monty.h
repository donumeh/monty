#ifndef MONTY_H
#define MONTY_H


#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

extern char *stackNumber;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: the integer
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
 * struct bytecode_s - singly linked list to store the bytecode
 * @opcode: the operation code
 * @arg: the arg that follows
 * @lineNumber: line number of command
 * @next: pointer to the next node
 *
 * Description: stores the command in the file
 */

typedef struct bytecode_s
{
	char *opcode;
	char *arg;
	int lineNumber;
	struct bytecode_s *next;
} bytecode_t;


void noFileError(void);
char *getFileName(char *);
int checkIfMontyFile(char *fileName);
void notMontyError(char *);
char *_strdup(char *);
void cannotMalloc(void);
int readFile(bytecode_t **, char *);
ssize_t _getline(char **, size_t *,  FILE *);
int storeLineInBytes(bytecode_t **, char *, int);
int byteAdd(bytecode_t **, char *, char *, int);
int executeByteCode(bytecode_t **, stack_t **);

#endif /* MONTY_H */

