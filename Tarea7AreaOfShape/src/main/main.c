#include <stdio.h>
#include "shape.h"

int main() {
    AmorhpusShape shape;
    printf("select 3 for unit test");
    initShape(&shape);
    if(shape.base.shapeSelection || shape.base.shapeSelection == 2 || shape.base.shapeSelection == 3) {
        printf("No error: Expected 1, 2 or 3 and got: %d", shape.base.shapeSelection);
    }else{
        printf("Error: Expected 1, 2 or 3 and got: %d", shape.base.shapeSelection);
    }
    pedirLados(&shape);
    if(shape.ladoUno > 0 && shape.ladoDos > 0 && shape.ladoTres > 0){
        printf("No error: Expected a number > 0 and got: %lf", shape.ladoUno);
    }else{
        printf("Error: Expected a number > 0 and got: %lf", shape.ladoUno);
        printf("Error: Expected a number > 0 and got: %lf", shape.ladoDos);
        printf("Error: Expected a number > 0 and got: %lf", shape.ladoTres);
    }
    calcularArea(&shape);

    printArea(&shape);
}