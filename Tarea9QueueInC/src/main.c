#include "queue.h"
#include "worker.h"
#include "merger.h"

struct Worker trabajadores[TOTAL_TRABAJADORES];
struct Worker trabajadoresActuales[TOTAL_TRABAJADORES];
struct Worker aux[TOTAL_TRABAJADORES];

int main() {

    initWorkers(trabajadores);

    printf("\n----------UNSORTED----------\n");
    printQueue(trabajadores,TOTAL_TRABAJADORES);
    printf("\n----------UNSORTED----------\n");

    mergeSort(0,TOTAL_TRABAJADORES-1,trabajadores,aux);

    printf("\n-----------SORTED-----------\n");
    printQueue(trabajadores,TOTAL_TRABAJADORES);
    printf("\n-----------SORTED-----------\n");

    srandom((unsigned) time(NULL));
    for (int i = 0; i < TOTAL_TRABAJADORES-1 ; ++i) {
        insert(
                random()%20,
                sprintf(trabajadores[i].entidad,"Entidad_%d",(int) ((i+1)*(random()%20))),
                sprintf(trabajadores[i].name,"Trabajador_%d",(int) ((i+1)*(random()%20))),
                random()%31,trabajadores
                );
    }
    printf("\n----------UNSORTED----------\n");
    printQueue(trabajadores,TOTAL_TRABAJADORES);
    printf("\n----------UNSORTED----------\n");

    mergeSort(0,TOTAL_TRABAJADORES-1,trabajadores,aux);

    printf("\n-----------SORTED-----------\n");
    printQueue(trabajadores,TOTAL_TRABAJADORES);
    printf("\n-----------SORTED-----------\n");

    insert(1000,"TEST","ENTIDA",23,trabajadores);
    insert(1001,"TEST2","ENTIDA2",24,trabajadores);
    printQueue(trabajadores,TOTAL_TRABAJADORES);
//    printf("\n----------DELETING?---------\n");
//        removeData(trabajadores);
//        printQueue(trabajadores,TOTAL_TRABAJADORES);
//    printf("\n----------DELETING?---------\n");

scanf(" ");
}