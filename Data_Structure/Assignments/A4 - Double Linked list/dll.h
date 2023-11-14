#ifndef DLL_H
#define DLL_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1
#define LIST_EMPTY -2
#define DATA_NOT_FOUND -3

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}Dlist;

int dl_insert_last(Dlist **head, Dlist **tail, int data);
int dl_insert_after(Dlist **head, Dlist **tail, int gdata, int ndata);
int dl_insert_before(Dlist **head, Dlist **tail, int gdata, int ndata);
int dl_delete_element(Dlist **head, Dlist **tail, int data);
void print_list(Dlist *head);

#endif
