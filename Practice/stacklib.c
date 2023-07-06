#include "lllib.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct stackType{
    node * top;
}stack;

void push(stack ** inputStack, elementType inputElement){
    insertAtHead(inputElement, inputStack);
}

