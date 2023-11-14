#ifndef TREE_H
#define TREE_H

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
int findmin(Tree_t *root);
Tree_t* delete_BST(Tree_t * root, int data);

#endif
