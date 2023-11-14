#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef int data_t;
typedef struct node
{
    data_t data;
    struct node *link;
}Stack_t;

int Push(Stack_t **top, data_t data);
int Pop(Stack_t **top);
int Peek(Stack_t **top);
int Peep(Stack_t *top);
int destroystack(Stack_t **top);

int is_stack_full(Stack_t *);
int is_stack_empty(Stack_t *);
#endif

