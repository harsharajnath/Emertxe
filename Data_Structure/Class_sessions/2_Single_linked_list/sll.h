#ifndef SLL_H
#define SLL_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

#define LIST_EMPTY 1
#define DATA_NOT_FOUND 2

typedef int data_t;
typedef struct node
{
    data_t data;
    struct node *link;
}Slist;


int select_operation();
int insert_at_last(Slist **head, data_t data);
int insert_after(Slist **head, data_t g_data, data_t n_data);
int insert_at_first(Slist **head, data_t data);
int insert_before(Slist **head, data_t g_data, data_t n_data);
int delete_at_first(Slist **head);
int delete_at_last(Slist **head);
int delete_list(Slist **head);
void print_list(Slist *head);

#endif
