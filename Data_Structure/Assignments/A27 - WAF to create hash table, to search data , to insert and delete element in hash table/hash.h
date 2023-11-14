#ifndef HASH_H
#define HASH_H

#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 0
#define FAILURE -1
#define LIST_EMPTY -2
#define DATA_NOT_FOUND -3

typedef struct node
{
    int index;
    int value;
    struct node *link;
}hash_t;

void create_HT(hash_t *, int);
int insert_HT(hash_t *arr, int element, int size);
int search_HT(hash_t *arr, int element, int size);
int delete_element(hash_t *arr, int element, int size);
int destroy_HT(hash_t *arr, int size);
void display_HT(hash_t *arr, int size);

#endif
