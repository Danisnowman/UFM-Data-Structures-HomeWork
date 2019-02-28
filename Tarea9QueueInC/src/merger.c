//
// Created by Daniel Hernández on 2019-02-27.
//

#include "merger.h"

void mergeSort(int i, int j, struct Worker *trabajadores, struct Worker *aux){
    if (j <= i) {
        return;     // the subsection is empty or trabajadores single element
    }
    int mid = (i + j) / 2;

    // left sub-array is trabajadores[i .. mid]
    // right sub-array is trabajadores[mid + 1 .. j]

    mergeSort(i, mid, trabajadores, aux);     // sort the left sub-array recursively
    mergeSort(mid + 1, j, trabajadores, aux);     // sort the right sub-array recursively

    int pointer_left = i;       // pointer_left points to the beginning of the left sub-array
    int pointer_right = mid + 1;        // pointer_right points to the beginning of the right sub-array
    int k;      // k is the loop counter

    // we loop from i to j to fill each element of the final merged array
    for (k = i; k <= j; k++) {
        if (pointer_left == mid + 1) {      // left pointer has reached the limit
            aux[k] = trabajadores[pointer_right];
            pointer_right++;
        } else if (pointer_right == j + 1) {        // right pointer has reached the limit
            aux[k] = trabajadores[pointer_left];
            pointer_left++;
        } else if (trabajadores[pointer_left].socialSecNum < trabajadores[pointer_right].socialSecNum) {        // pointer left points to smaller element
            aux[k] = trabajadores[pointer_left];
            pointer_left++;
        } else {        // pointer right points to smaller element
            aux[k] = trabajadores[pointer_right];
            pointer_right++;
        }
    }

    for (k = i; k <= j; k++) {      // copy the elements from aux[] to trabajadores[]
        trabajadores[k] = aux[k];
    }
}