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

int main() {
    Entry debits, credits;
    entryInit(&debits, debitMax);
    srand(time(NULL)%14);
    for (int i = 0; i<debitMax; i++) {
        entryAdd(&debits, (1+(rand()%9)));
    
    }
    entryPrint(&debits);
    
    entryRemove(&debits, 2);
    entryPrint(&debits);
    
    entryMoveElements(&debits);
    entryPrint(&debits);
    
    
    
    entryFree(&debits);
    return 0;
}
