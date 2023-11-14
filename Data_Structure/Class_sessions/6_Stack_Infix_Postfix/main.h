#ifndef MAIN_H
#define MAIN_H

#define SIZE_STACK 50

#include <stdio.h> 
#include <ctype.h>

typedef struct{
    int top;
    int stack[SIZE_STACK];
}Stack_t;

int Infix_Postfix_conversion(char *Postfix_exp, char *Infix_exp, Stack_t *stk);
int Postfix_Eval(char *Postfix_exp, Stack_t *stk);
int priority(char opr);
void push(Stack_t *stk, int data);
int peek(Stack_t *stk);
void pop(Stack_t *stk);

int my_strlen(char *str);
int isOperator(char sym);
int expressionEvaluation(int valueA, int valueB, char sym);

#endif
