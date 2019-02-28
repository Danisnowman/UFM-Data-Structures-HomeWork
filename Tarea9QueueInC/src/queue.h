//
// Created by Daniel Hernández on 2019-02-26.
//

#ifndef UNTITLED_QUEUE_H
#define UNTITLED_QUEUE_H

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "worker.h"

int peek(struct Worker *array);

bool isEmpty(struct Worker *array);

bool isFull(struct Worker *array);

int size(struct Worker *array);

void insert(int SSN, char name[30], char entidad[30], int diasTrabajado, struct Worker *array);

int removeData(struct Worker *array);

void printIsEmpty(bool isEmpty);

void printQueue(struct Worker *array, int arrayEnd);

#endif //UNTITLED_QUEUE_H
