#ifndef BST_H
#define BST_L

#define SUCCESS 0
#define FAILURE -1
#define NOELEMENT -2
#define DUPLICATE -3

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *left;
    int data;
    struct node *right;
}Tree_t;

int insert_into_BST(Tree_t **root, int data);
int inorder(Tree_t *);
int total_nodes(Tree_t * root);
int find_height(Tree_t * root);

#endif
