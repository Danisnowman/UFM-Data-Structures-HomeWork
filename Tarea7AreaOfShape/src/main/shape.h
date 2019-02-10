//
// Created by Daniel Hernández on 2019-02-09.
//

#ifndef TAREA7AREAOFSHAPE_SHAPE_H
#define TAREA7AREAOFSHAPE_SHAPE_H

typedef union Shape{
    double area;
}Shape;

typedef struct Triangle{
    union Shape base;
    double catetoA;
    double catetoB;
    double catetoC;
}Triangle;

double calcularArea(Triangle *triangle);


#endif //TAREA7AREAOFSHAPE_SHAPE_H
