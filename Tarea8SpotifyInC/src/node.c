//
// Created by Daniel Hernández on 2019-02-19.
//

#include "node.h"

void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d: %s \n",current->indexNumber,current->songName);
        current = current->next;
    }
}

void addToTheEnd(node_t * head, char inputSongName[40], int inputIndexNumber) {
    node_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = malloc(sizeof(node_t));
    strcpy(current->next->songName, inputSongName);
    current->next->next = NULL;
}

void push(node_t * head, char inputSongName[40], int inputIndexNumber) {
    node_t * current = head;        // Defines head as the first node
    while (current->next != NULL) { // Checks if it is on the last node
        current = current->next;    // Moves to the last node to then
    }
    if (!head->indexNumber) {        // Checks if idCard is 0 to see if node head is empty. a student can have 0 on a grade but not on idCard
        strcpy(head->songName, inputSongName);
        head->indexNumber = inputIndexNumber;
    }else{                    // If head is not empty, it moves to the nex node
        current->next = malloc(sizeof(node_t));
        strcpy(current->next->songName, inputSongName);
        current->next->indexNumber = inputIndexNumber;
        current->next->next = NULL;
    }
}

int pop(node_t ** head) {
    int returnCode = -1;
    node_t * next_node = NULL;

    if (!*head) {
        return -1;
    }

    next_node = (*head)->next;
    returnCode = (*head)->indexNumber;
    free(*head);
    *head = next_node;

    return returnCode;
}

int remove_last(node_t * head) {
    int returnCode = 0;
    /* if there is only one item in the list, remove it */
    if (head->next == NULL) {
        returnCode = head->indexNumber;
        free(head);
        return returnCode;
    }

    /* get to the second to last node in the list */
    node_t * current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    /* now current points to the second to last item of the list, so let's remove current->next */
    returnCode = current->next->indexNumber;
    free(current->next);
    current->next = NULL;
    return returnCode;

}

int remove_by_index(node_t ** head, int index) {
    int i = 0;
    int returnCode = -1;
    node_t * current = *head;
    node_t * temp_node = NULL;
    if (!index) {
        return pop(head);
    }

    for (i = 0; i < index-1; i++) {
        if (current->next == NULL) {
            return -1;
        }
        current = current->next;
    }
    temp_node = current->next;
    returnCode = temp_node->indexNumber;
    current->next = temp_node->next;
    free(temp_node);
    return returnCode;
}