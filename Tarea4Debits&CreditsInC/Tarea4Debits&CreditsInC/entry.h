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
int entryAddUp(Entry *entry, int entrySize);


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

// recibe un array
void entryMoveElements(Entry *entry){
    // este for va a iterar en el array que recibe la cantidad de veces el tamaño del array
    for (int i = 0; i < entry->capacity-1; i++) {
        if (!entry->data[i]) {
            entry->data[i] = entry->data[i+1];
            entry->data[i+1] = 0;
        }
    }
}

void entryRemove(Entry *entry, int position){
    entry->data[position-1] = 0;
    //entryMoveElements(entry);
}

int entryAddUp(Entry *entry,int entrySize){
    int total = 0;
    for (int i = 0; i<entrySize; i++) {
        total += entry->data[i];
    }
    return total;
}





void entryFree(Entry *entry){
    free(entry->data);
}

void entryPrint(Entry *entry){
    for (int i = 0; i<entry->size; i++) {
        printf("%d.{ %d }\n",i+1,entry->data[i]);
        
    }
    printf("\n");
}






#endif /* classAccount_h */
