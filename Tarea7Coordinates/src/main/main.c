#include <stdio.h>
#include "commonFunctions.h"
#include "point.h"

int main() {
    GivenPoint point;
    int parameterX = askInt("Enter your number: ");
    int parameterY = askInt("Enter your number: ");
    initPoint(&point, parameterX, parameterY);
    identifyQuadrant(&point);
    printQuadrant(&point);
    return 0;
}