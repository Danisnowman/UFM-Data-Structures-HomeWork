#include <stdio.h>
#include "shape.h"

int main() {
    Triangle triangle;
    double area = calcularArea(&triangle);
    printf("Area: %.2lf", area);
    return 0;
}