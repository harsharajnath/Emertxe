#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include<stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct Que
{
    int data;
    struct Que *link;
}Queue_t;

int enqueue(Queue_t **, Queue_t **, int);
int dequeue(Queue_t **, Queue_t **);
int print_queue(Queue_t *, Queue_t *);

#endif
