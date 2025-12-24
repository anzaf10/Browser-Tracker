#ifndef STACK_H
#define STACK_H

#define MAX 100
#define URL_LENGTH 100

typedef struct {
    char urls[MAX][URL_LENGTH];
    int top;
} Stack;

void initStack(Stack *s);
int isFull(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, char *url);
void pop(Stack *s, char *destination);
void clearStack(Stack *s);

#endif