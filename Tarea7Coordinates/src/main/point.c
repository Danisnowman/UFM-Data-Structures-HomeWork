//
// Created by Daniel Hernández on 2019-02-10.
//

#include <MacTypes.h>
#include "point.h"
#include <stdio.h>

void initPoint(GivenPoint *point, int inputX, int inputY){
    point->x = inputX;
    point->y = inputY;
}
void identifyQuadrant(GivenPoint *point){
    if (point->x > 0 && point->y > 0){
        point->cuadrant = 1;
    } else if (point->x < 0 && point->y > 0){
        point->cuadrant = 2;
    } else if (point->x < 0 && point->y < 0){
        point->cuadrant = 3;
    } else if (point->x > 0 && point->y <0){
        point->cuadrant =4;
    } else if (!point->x && !point->y) {
        point->cuadrant = 0;
    }
}

void printQuadrant(GivenPoint *point){
    if (!point->x && !point->y){
        printf("Your point (%d,%d) is in the origin.",point->x,point->y);
    }else if (!point->x || !point->y){
        printf("Your point (%d,%d) is not in any quadrant.",point->x,point->y);
    }else {
        printf("Your point (%d,%d) is in the quadrant %d.",point->x,point->y,point->cuadrant);
    }
}
