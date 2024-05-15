#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include <stdio.h>

void StackNew(Stack* s, int elemSize) {
    s->length = 0;
    s->alloclength = 4;
    s->elems = malloc(4 * elemSize);
}

void StackDispose(Stack* s) {
    free(s->elems);
}

void StackPush(Stack* s, void* elemAddr) {
    if (s->length == s->alloclength) {
        s->alloclength *= 2;
        s->elems = realloc(s->elems, s->alloclength);
    }
    void* target = (char*)s->elems + s->length * sizeof(elemAddr);
    memcpy(target, elemAddr, sizeof(elemAddr));
    s->length++;
}

void StackPop(Stack* s, void* elemAddr) {
    s->length--;
    void* source = (char*)s->elems + s->length * sizeof(elemAddr);
    memcpy(elemAddr, source, sizeof(elemAddr));
}

bool StackEmpty(Stack* s) {
    return s->length == 0;
}

//create a main function to test the stack
int main() {
    Stack intStack;
    StackNew(&intStack, sizeof(int));
    for (int i = 0; i < 10; i++) {
        StackPush(&intStack, &i);
    }
    while (!StackEmpty(&intStack)) {
        int value;
        StackPop(&intStack, &value);
        printf("%d\n", value);
    }
    StackDispose(&intStack);
    return 0;
}

