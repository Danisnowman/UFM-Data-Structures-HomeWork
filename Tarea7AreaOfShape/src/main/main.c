#include <stdio.h>
#include "shape.h"

int main() {
    Triangle triangle;
    initShape(&triangle);
    calcularArea(pedirLados(&triangle));
    printf("Area: %.2lf", area);
    return 0;
}