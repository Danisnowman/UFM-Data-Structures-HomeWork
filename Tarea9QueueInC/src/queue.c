//
// Created by Daniel Hernández on 2019-02-26.
//

#include "queue.h"

#define MAX 6

int intArray[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

int peek(struct Worker *array) {
    return array[front].socialSecNum;
}

bool isEmpty(struct Worker *array) {
    return !itemCount;
}

bool isFull(struct Worker *array) {
    return itemCount == MAX;
}

int size(struct Worker *array) {
    return itemCount;
}

void insert(int SSN, char name[30], char entidad[30], int diasTrabajado, struct Worker *array) {

    if (!isFull(NULL)) {

        if (rear == MAX - 1) {
            rear = -1;
        }

        array[++rear].socialSecNum = SSN;
//        strcpy(array[++rear].name, name);
//        strcpy(array[++rear].entidad, entidad);
//        array[++rear].diasTrabajados = diasTrabajado;
        itemCount++;
    }
}

int removeData(struct Worker *array) {
    int data = array[front++].socialSecNum;

    if (front == MAX) {
        front = 0;
    }

    itemCount--;
    return data;
}

void printQueue(struct Worker *array, int arrayEnd){
    for (int i = 0; i < arrayEnd; ++i) {
        printf("\n");
        printf("SSN: %d\n",array[i].socialSecNum);
        printf("NAME: %s\n",array[i].name);
    }
}