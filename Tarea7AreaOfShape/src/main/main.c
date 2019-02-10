#include <stdio.h>
#include "shape.h"

int main() {
    AmorhpusShape triangle;
    initShape(&triangle);
    pedirLados(&triangle);
    calcularArea(&triangle);
    printArea(&triangle);
}