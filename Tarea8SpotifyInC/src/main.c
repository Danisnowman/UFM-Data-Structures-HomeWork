#include <stdio.h>
#include  "commonFunctions.h"
#include "node.h"

int main() {
    struct node song;
    char songNameAndNumber[10];
    for (int i = 1; i <10 ; ++i) {
        sprintf(songNameAndNumber, "Song %d", i);
        push(&song,songNameAndNumber,i);
    }
    print_list(&song);
    return 0;
}