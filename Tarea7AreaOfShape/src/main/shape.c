//
// Created by Daniel Hernández on 2019-02-09.
//

#include "shape.h"
#include "commonFunctions.h"
#include <math.h>

double calcularArea(Triangle *triangle){
    triangle->catetoA = fabs(askDouble("\nCateto A: ",maxLength));
    triangle->catetoB = fabs(askDouble("Cateto B: ",maxLength));
    triangle->catetoC = fabs(askDouble("Cateto C: ",maxLength));
    double p = (triangle->catetoA + triangle->catetoB + triangle->catetoC)/2;
    if (p < triangle->catetoC || p < triangle->catetoB || p < triangle->catetoA){
        printf("\nError, impossible triangle!");
        calcularArea(triangle);
    }else{
        triangle->base.area = sqrt(p * (p-triangle->catetoA) * (p - triangle->catetoB) * (p - triangle->catetoC));
    }
    return triangle->base.area;
}