/**
 * @file main.c
 * @brief This program is meant to create a stack simulation
 * using arrays and not linked lists. *
 * @author Daniel E. Hernández - 20180077 *
 * @date 2019-01-24 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>     /// For INT_MIN
#include "commonFunctions.h"



bool done = false;
/// Create a stack with capacity of 100 items
int stack[INT_MAX];

/// Initially stack is empty
int top = -1;


/**
 * Function push() will be used to push items on the stack.
 * @param item which is itself an item from an stack
 */
void push(int item);
/**
 * Function pop() will delete a specific item from the stack and
 * will move the others to their new position (stack[i-1]).
 * @ param item which is itself an item from the stack.
 */
int pop(void);
/**
 * Function clearArray() will be used to clear all the items from the
 * stack.
 */
int clearArray(void);

void printStack(void);


int main(){
    int choice, data;
    
    while(!done){
        /* Menu */
        printf("\n1. Push\n2. Pop\n3. Clear\n4. Show\n5. Exit\n");
        choice = askInt("\nEnter your option: ", 5);
        
        switch(choice){
                /// Push
            case 1:
                data = askInt("Enter data to push into stack: ", INT_MAX);
                
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



/**
 * Function push() will be used to add an item at the top
 * of the stack.
 * @param item will be the new item on the stack.
 */
void push(int item){
    /// Check for Stack Overflow
    if (top >= INT_MAX){
        printf("Stack Overflow, please clear your stack.\n");
        return;
    }
    
    /// Increase the count of items each time a new item is added.
    top++;
    
    /// Push item to the top of the stack.
    stack[top] = item;
    
    printf("Data pushed to stack.\n");
}


/**
 * Function pop() will be used to clear the top item from the
 * stack.
 *
 */
int pop(){
    /// Check if stack is empty, if so then it is a Stack Underflow. Not quite famous.
    if (top < 0){
        printf("Stack is empty. Please add at least 1 item.\n");
        
        /// Throw empty stack error/exception
        /// Since C does not have concept of exception
        /// Hence return minimum integer value as error value
        /// Later in code check if return value is INT_MIN, then
        /// stack is empty
        return INT_MIN;
    }
    
    
    /// Return the top of the stack and decrease the count of top.
    return stack[top--];
}

int clearArray(){
    if (top < 0){
        printf("Stack is empty. Please add at least 1 item.\n");
        return INT_MIN;
    }
    for (int i = top; i>0; --i) {
        stack[i] = 0;
    }
    top = -1;
    return stack[top];
}

/**
 * Function printStack() will be used to print the whole stack, each element
 * by a pair of "[]" the top item from the
 * stack.
 */
void printStack(){
    printf("\n\nStack size: %d\n", top + 1);
    for (int i = 0; i<top+1; i++) {
        printf("[%d] ",stack[i]);
    }
}
