//
//  classAccount.h
//  
//
//  Created by Daniel Hernández on 1/30/19.
//
#include <stdio.h>
#include <stdlib.h>
#include "commonFunctions.h"
#ifndef classAccount_h
#define classAccount_h



// Define a stack type
typedef struct {
    int size;      // slots used so far
    int capacity;  // total available slots
    int *data;     // pointer to the first item
} Entry;

void entryInit(Entry *entry, int capacity);
bool entryCheckIfEmpty(Entry *entry, int positionBeingChcked);
void entryAdd(Entry *entry, int value);
void entryMoveElements(Entry *entry);
void entryRemove(Entry *entry, int position);
void entryFree(Entry *entry);
void entryPrint(Entry *entry);

void entryInit(Entry *entry, int capacity){
    // sets the total cpacity of the array
    entry->capacity = capacity;
    entry->size = 0;
    // sets the pointer to the head
    entry->data = malloc(sizeof(int) * entry->capacity);
}

bool entryCheckIfEmpty(Entry *entry, int positionBeingChecked){
    return entry->data[positionBeingChecked];
}

void entryAdd(Entry *entry, int value){
    if (!entry->data[0]) {
        entry->data[0] = value;
    } else {
        entry->data[entry->size] = value;
        
    }
    entry->size++;
}

void entryMoveElements(Entry *entry){
    for (int currentPosition = 0; currentPosition < entry->size-1; currentPosition++) {
        if (!entry->data[currentPosition]) {
            entry->data[currentPosition] = entry->data[currentPosition+1];
            entry->data[currentPosition+1] = 0;
        }
    }
}

void entryRemove(Entry *entry, int position){
    entry->data[position] = 0;
}

void entryFree(Entry *entry){
    free(entry->data);
}

void entryPrint(Entry *entry){
    for (int i = 0; i<entry->size; i++) {
        printf("%d. { %d }\n",i+1,entry->data[i]);
        
    }
    printf("\n");
}






#endif /* classAccount_h */
