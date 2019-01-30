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

int main() {
    Entry debits;
    entryInit(&debits, 4);
    srand(time(NULL)%14);
    for (int i = 0; i<4; i++) {
        entryAdd(&debits, (rand()%10));
    }
    entryPrint(&debits);
    
    
    
    entryFree(&debits);
    return 0;
}
