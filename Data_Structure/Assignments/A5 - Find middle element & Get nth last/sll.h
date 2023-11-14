#ifndef SLL_H
#define SLL_L

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1
#define LIST_EMPTY -2

typedef int data_t;
typedef struct node
{
    data_t data;
    struct node *link;
}Slist;

int insert_at_last(Slist **head, data_t data);
int find_mid(Slist *head, int *mid);
int find_nth_last(Slist *head, int , int *);
void print_list(Slist *head);
#endif
