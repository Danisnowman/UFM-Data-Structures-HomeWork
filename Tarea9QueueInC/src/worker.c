//
// Created by Daniel Hernández on 2019-02-27.
//
#include "worker.h"
#include "queue.h"

void initWorkers(struct Worker *trabajadores){
    fillWorkersName(trabajadores);
    fillWorkersSSN(trabajadores);
    fillEntidad(trabajadores);
}

void fillWorkersName(struct Worker *trabajadores) {
    for (int i = 0; i <TOTAL_TRABAJADORES; ++i) {
        sprintf(trabajadores[i].name,"Trabajador_%d",i);
        //printf("Nombre: %s\n", trabajadores[i].name);
    }
}

void fillWorkersSSN(struct Worker *trabajadores){
    srandom((unsigned) time(NULL));
    for (int i = 0; i <TOTAL_TRABAJADORES; ++i) {
        trabajadores[i].socialSecNum = ((i+1)*random()%1000);
        //printf("SSN: %d\n", (int) trabajadores[i].socialSecNum);
    }
}

void fillEntidad(struct Worker *trabajadores) {
    srandom((unsigned) time(NULL));
    for (int i = 0; i < TOTAL_TRABAJADORES; ++i) {
        sprintf(trabajadores[i].entidad,"Entidad_%d",(int) ((i+1)*(random()%20)));
        //printf("Entidad: %s\n", trabajadores[i].entidad);
    }
}