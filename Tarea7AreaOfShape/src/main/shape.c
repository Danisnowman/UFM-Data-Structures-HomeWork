//
// Created by Daniel Hernández on 2019-02-09.
//

#include "shape.h"
#include "commonFunctions.h"
#include <math.h>


void initShape(AmorhpusShape *shape){
    shape->base.shapeSelection = askInt("1.Triangle\n2.Rectangle\n3.Circle\n\nSelect a shape: ",3);
}

void pedirLados(AmorhpusShape *shape){
    switch (shape->base.shapeSelection){
        case 1: // triangle
            shape->ladoUno = fabs(askDouble("\nCateto 1: ",maxLength));
            shape->ladoDos = fabs(askDouble("Cateto 2: ",maxLength));
            shape->ladoTres = fabs(askDouble("Cateto 3: ",maxLength));
            break;
        case 2: // rectangle
            shape->ladoUno = fabs(askDouble("\nLado 1: ",maxLength));
            shape->ladoDos = fabs(askDouble("\nLado 2: ",maxLength));
            break;
        case 3: // circle
            shape->ladoUno = fabs(askDouble("\nRadio : ",maxLength));
            break;
        default:
            printf("Error, invalid selection.");
            break;
    }
    // return shape;
}

void calcularArea(AmorhpusShape *shape){
    double p = 0;
    switch (shape->base.shapeSelection){
        case 1: // Calculate triangle's area
            p = (shape->ladoUno + shape->ladoDos + shape->ladoTres)/2;
            if (p < shape->ladoTres || p < shape->ladoDos || p < shape->ladoUno){
                printf("\nError, impossible triangle!");
            }else{
                shape->base.area = sqrt(p * (p-shape->ladoUno) * (p - shape->ladoDos) * (p - shape->ladoTres));
            }
            break;

        case 2: // Calculate rectangle's area
            shape->base.area = (shape->ladoUno * shape->ladoDos);
            break;

        case 3:
            shape->base.area = (M_PI * pow(shape->ladoUno,2));
            break;

        default:
            printf("Error, invalid selection.");
            break;
    }
}

void printArea(AmorhpusShape *shape){
    printf("The area of the geometric figure is %.2lf",shape->base.area);
}