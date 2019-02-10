//
// Created by Daniel Hernández on 2019-02-09.
//

#ifndef TAREA7AREAOFSHAPE_SHAPE_H
#define TAREA7AREAOFSHAPE_SHAPE_H

typedef union Shape{
    int shapeSelection;     // 1 == triangle, 2 == rectangle, 3 == circle
    double area;
}Shape;

typedef struct AmorhpusShape{
    union Shape base;
    double ladoUno;
    double ladoDos;
    double ladoTres;
}AmorhpusShape;

void initShape(AmorhpusShape *shape);
void pedirLados(AmorhpusShape *shape);
void calcularArea(AmorhpusShape *shape);
void printArea(AmorhpusShape *shape);

#endif //TAREA7AREAOFSHAPE_SHAPE_H
