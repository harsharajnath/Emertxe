#ifndef DLL_H
#define DLL_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

#define DATA_NOT_FOUND -2
#define LIST_EMPTY -3

typedef int data_t;
typedef struct node
{
    struct node *prev;
    data_t data;
    struct node *next;
}Dlist;


int insert_at_last(Dlist **head, Dlist **tail, data_t data);
int insert_after(Dlist **head, Dlist **tail, data_t g_data, data_t n_data);
int insert_at_first(Dlist **head, Dlist **tail, data_t data);
int insert_before(Dlist **head, data_t g_data, data_t n_data);
int delete_at_first(Dlist **head, Dlist **tail);
int delete_at_last(Dlist **head, Dlist **tail);
int delete_list(Dlist **head, Dlist **tail);
void print_list(Dlist *head);

#endif
