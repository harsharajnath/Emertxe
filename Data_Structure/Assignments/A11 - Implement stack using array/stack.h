#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

#define TRUE    0
#define FALSE   -1

typedef struct stack
{
    unsigned int capacity;
    int top;
    int *stack;
}Stack_t;

int create_stack(Stack_t *, int );
int Push(Stack_t *, int);
int Pop(Stack_t *);
int Peek(Stack_t *);
void Peep(Stack_t);

#endif
