//
//  main.cpp
//  Tarea3DynamicArray
//
//  Created by Daniel Hernández on 1/28/19.
//  Copyright © 2019 Daniel Hernández. All rights reserved.
//

#include <iostream>
#include "commonFunctions.h"

int choice, data;

int main(){
while(!done){
    /* Menu */
    printf("\n1. Push\n2. Pop\n3. Clear\n4. Show\n5. Exit\n");
    choice = askInt("\nEnter your option: ", 5);
    
    switch(choice){
            /// Push
        case 1:
            int data = askInt("Enter data to push into stack: ", INT_MAX);
            
            /// Push item to stack
            push(data);
            break;
            /// Pop
        case 2:
            data = pop();
            
            /// If stack is not empty
            if (data != INT_MIN)
                printStack();
                break;
            
            /// Clear
        case 3:
            clearArray();
            break;
            /// Exit
        case 4:
            printStack();
            break;
        case 5:
            printf("\nExiting from app.");
            exit(0);
            break;
            
            /// Size
            
            
        default:
            printf("\nInvalid choice, please try again.\n");
    }
    
    printf("\n\n");
}


return 0;
}
