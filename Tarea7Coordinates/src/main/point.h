//
// Created by Daniel Hernández on 2019-02-10.
//

#ifndef TAREA7COORDINATES_POINT_H
#define TAREA7COORDINATES_POINT_H

typedef struct GivenPoint{
    int x;
    int y;
    int cuadrant;
}GivenPoint;

void initPoint(GivenPoint *point, int inputX, int inputY);
void identifyQuadrant(GivenPoint *point);
void printQuadrant(GivenPoint *point);

#endif //TAREA7COORDINATES_POINT_H
