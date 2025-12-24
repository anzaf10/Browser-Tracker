#include <stdio.h>
#include <string.h>
#include "../include/stack.h"

void initStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char *url) {
    if (isFull(s)) {
        return;
    }
    s->top++;
    strcpy(s->urls[s->top], url);
}

void pop(Stack *s, char *destination) {
    if (isEmpty(s)) {
        return;
    }
    strcpy(destination, s->urls[s->top]);
    s->top--;
}

void clearStack(Stack *s) {
    s->top = -1;
}