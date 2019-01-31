//
//  main.c
//  Tarea4Debits&CreditsInC
//
//  Created by Daniel Hernández on 1/30/19.
//  Copyright © 2019 Daniel Hernández. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include "entry.h"
int debitMax = 10;

void debitPrintAddUp(Entry *debit);

int main() {
    Entry debits, credits;
    entryInit(&debits, debitMax);
    srand(time(NULL)%14);
    for (int i = 0; i<debitMax; i++) {
        entryAdd(&debits, (1+(rand()%9)));
       // printf("%d: %d\n",i,debits.data[i]);

    }
    entryPrint(&debits);
    debitPrintAddUp(&debits);
    entryRemove(&debits, 3);
    entryRemove(&debits, 5);
    entryRemove(&debits, 7);
    
    entryMoveElements(&debits);
    printf("Primer move\n");
    entryPrint(&debits);
    
    entryMoveElements(&debits);
    printf("Segundo move^\n");
    entryPrint(&debits);
    
    entryMoveElements(&debits);
    printf("Segundo move^\n");
    entryPrint(&debits);
    
   // debitPrintAddUp(&debits);
   // entryRemove(&debits, 2);
   // entryPrint(&debits);
   // debitPrintAddUp(&debits);
    
    
   
    
    entryFree(&debits);
    
    return 0;
}

void debitPrintAddUp(Entry *debit){
    printf("Total de Debits: %d\n", entryAddUp(debit, debitMax));
}
