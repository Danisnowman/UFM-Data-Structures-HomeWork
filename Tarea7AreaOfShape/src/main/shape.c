//
// Created by Daniel Hernández on 2019-02-09.
//

#include "shape.h"
#include "commonFunctions.h"
#include <math.h>


void initShape(Triangle *shape){
    shape->base.shapeSelection = askInt("Select a shape:\n1.Triangle\n2.Rectangle\n3.Rectangle",3);
}

Triangle pedirLados(Triangle *triangle){
    switch (triangle->base.shapeSelection){
        case 1: // triangle
            triangle->catetoA = fabs(askDouble("\nCateto A: ",maxLength));
            triangle->catetoB = fabs(askDouble("Cateto B: ",maxLength));
            triangle->catetoC = fabs(askDouble("Cateto C: ",maxLength));
            break;
        case 2: // rectangle
            break;
        case 3: // circle
            break;
        default:
            printf("Error, invalid selection.");
            break;
    }
    return *triangle;
}

void calcularArea(Triangle *triangle){
    double p = (triangle->catetoA + triangle->catetoB + triangle->catetoC)/2;
    if (p < triangle->catetoC || p < triangle->catetoB || p < triangle->catetoA){
        printf("\nError, impossible triangle!");
    }else{
        triangle->base.area = sqrt(p * (p-triangle->catetoA) * (p - triangle->catetoB) * (p - triangle->catetoC));
    }
}