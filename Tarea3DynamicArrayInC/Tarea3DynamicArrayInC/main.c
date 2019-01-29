//
//  main.c
//  Tarea3DynamicArrayInC
//
//  Created by Daniel Hernández on 1/28/19.
//  Copyright © 2019 Daniel Hernández. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "commonFunctions.h"
#include "Stack.h"




int main(){
    Stack stack;
    stackInit(&stack);
    for (int i = -5; i<100; i++) {
        stackAppend(&stack, rand() % 53);
    }
    for (int j = 0; j < stack.capacity; j++) {
        printf("Heres the value at %d: %d\n",j , stackGet(&stack, j));
    }
    printf(<#const char *restrict, ...#>)
    stackFree(&stack);
    exit(0);
}
