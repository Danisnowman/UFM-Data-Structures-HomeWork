//
//  main.c
//  Tarea1EstructuraDeDatos
//
//  Created by Daniel Hernández on 1/21/19.
//  Copyright © 2019 Daniel Hernández. All rights reserved.
//

#include <stdio.h>
#include <limits.h>
#include "commonFunctions.h"

int main(int argc, const char * argv[]) {
    int userNumber = askInt("Please enter an integer: ", 30000);
    int addedNumber = 0;
    for (int i = userNumber; i > 0; i--) {
        addedNumber +=i;
    }
    printf("Your number: %d \nAdded Number: %d\n\n", userNumber,addedNumber);
    return 0;
}
