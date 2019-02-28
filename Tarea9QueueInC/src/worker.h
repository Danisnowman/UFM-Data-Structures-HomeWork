//
// Created by Daniel Hernández on 2019-02-27.
//

#ifndef TAREA9QUEUEINC_WORKER_H
#define TAREA9QUEUEINC_WORKER_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TOTAL_TRABAJADORES 5


struct Worker {
    long socialSecNum;
    int diasTrabajados;
    char name[30];
    char entidad[30];
};

void initWorkers(struct Worker *trabajadores);

void fillWorkersName(struct Worker *trabajadores);

//void fillDiasTrabajados(struct Worker *trabajadores);

void fillWorkersSSN(struct Worker *trabajadores);

void fillEntidad(struct Worker *trabajadores);

#endif //TAREA9QUEUEINC_WORKER_H
