//
// Created by Daniel Hernández on 2019-02-19.
//

#ifndef TAREA8SPOTIFYINC_NODE_H
#define TAREA8SPOTIFYINC_NODE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char songName[20];
    int indexNumber;
    struct node * next;
} node_t;


void print_list(node_t * head);
void addToTheEnd(node_t * head, char inputSongName[40], int inputIndexNumber);
void push(node_t * head, char inputSongName[40], int indexNumber);
int pop(node_t ** head);
int remove_last(node_t * head);
int remove_by_index(node_t ** head, int index);



#endif //TAREA8SPOTIFYINC_NODE_H
