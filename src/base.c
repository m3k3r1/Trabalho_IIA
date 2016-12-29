#include "base.h"


int rand_in_n(dist_t* head){
    int max, tmp;

    while (head != NULL) {
        if(head->e2 > max)
            max = head->e2;
        head = head->next;
    }

    tmp =  rand() % max + 1;

    return tmp;
}

void init_sol(int** sol, dist_t* head){
    int *tmp;

    if (!(tmp = malloc( sizeof(int)* 2 ))) {
        perror("[MEMORY_ERROR]Can't alocate new node");
        return;
    }

    tmp[0] = rand_in_n(head);
    tmp[1] = rand_in_n(head);

    *sol = tmp;
}
