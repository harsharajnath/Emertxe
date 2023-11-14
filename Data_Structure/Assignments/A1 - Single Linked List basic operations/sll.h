#ifndef SLL_H
#define SLL_H

#include <stdio.h>
#include <stdlib.h>

//MACROS
#define SUCCESS 0
#define FAILURE -1
#define LIST_EMPTY 1
#define DATA_FOUND 2
#define DATA_NOT_FOUND 3

typedef int data_t;
typedef struct node
{
    data_t data;
    struct node *link;
}Slist;

int find_node(Slist *head, data_t key);     //function prototype for find_node() function
int insert_at_last(Slist **head, data_t );      //function prototype for insert_at_last() function
int insert_at_first(Slist **head, data_t);      //function prototype for insert_at_first() function
int sl_delete_list(Slist **);       //function prototype for sl_delete_list() function
int sl_delete_last(Slist **);       //function prototype for sl_delete_last() function
int sl_delete_first(Slist **);      //function prototype for sl_delete_first() function
void print_list(Slist *head);       //function prototype for print_list() function

#endif
