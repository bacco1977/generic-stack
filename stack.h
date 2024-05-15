#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct {
    void* elems;
    int length;
    int alloclength;
} Stack;



void StackNew(Stack* s, int elemSize);
void StackDispose(Stack* s);
void StackPush(Stack* s, void* elemAddr);
void StackPop(Stack* s, void* elemAddr);
bool StackEmpty(Stack* s);

#endif // STACK_H
