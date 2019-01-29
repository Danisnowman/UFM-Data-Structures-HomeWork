//
//  Stack.h
//  Tarea3DynamicArrayInC
//
//  Created by Daniel Hernández on 1/28/19.
//  Copyright © 2019 Daniel Hernández. All rights reserved.
//
#include <stdlib.h>
#ifndef Stack_h
#define Stack_h
#define StackInitialCapacity 1


// Define a vector type
typedef struct {
    int size;      // slots used so far
    int capacity;  // total available slots
    int *data;     // pointer to the first item
} Stack;

void stackInit(Stack *stack);

void stackAppend(Stack *stack, int value);

int stackGet(Stack *stack, int index);

void stackSet(Stack *stack, int index, int value);

void stackAddIfFull(Stack *stack);

void stackFree(Stack *stack);



void stackInit(Stack *stack){
    // sets stack's "used space" to 0
    stack->size = 0;
    // sets stack's total slots to the max amount (until it's full)
    stack->capacity = StackInitialCapacity;
    // allocates memory to the size of the array (depends on OS arch: 64 or 32)
    stack->data = malloc(sizeof(int) * stack->capacity);
}

void stackAppend(Stack *stack, int value){
    // make sure there's room to expand into
    stackAddIfFull(stack);
    
    // append the value and increment stack->size
    stack->data[stack->size++] = value;
}

int stackGet(Stack *stack, int index){
    if (index >= stack->size || index < 0) {
        printf("Index %d out of bounds for vector of size %d\n", index, stack->size);
        exit(1);
    }
    return stack->data[index];
}

void stackSet(Stack *stack, int index, int value){
    // zero fill the vector up to the desired index
    while (index >= stack->size) {
        stackAppend(stack, 0);
    }
    
    // set the value at the desired index
    stack->data[index] = value;
}

void stackAddIfFull(Stack *stack){
    if (stack->size >= stack->capacity) {
        // double vector->capacity and resize the allocated memory accordingly
        stack->capacity += 1;
        stack->data = realloc(stack->data, sizeof(int) * stack->capacity);
    }
}

void stackFree(Stack *stack){
    free(stack->data);
}

#endif /* Stack_h */
