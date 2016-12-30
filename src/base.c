#include "base.h"

int rand_in_n(dist_t* head, sol_t * sol){
    int/* max,*/ tmp, allow = 0;
    //sol_t* aux = sol;

    //FIND MAX WITH head !!!!!!!!!!!!!!!


    do {

        //FIX THE  20 !!!!!!!!!!!!!!!!!!!
        tmp =  1 + rand() % 20;

        if (tmp == 0)
            allow = 0;
        else
            allow = 1;

    } while(!allow);


    return tmp;
}

void init_sol(sol_t** sol, dist_t* head){
    *sol = add_rand_elem(head, *sol);
    (*sol)->next_elem = add_rand_elem(head, *sol);
}

void crt_node(sol_t ** sol, dist_t* head){
    while ( *sol )
        sol = &(*sol)->next_elem;
    *sol= add_rand_elem(head, *sol);
}

sol_t * add_rand_elem(dist_t* head, sol_t * sol){
    sol_t* tmp;

    if (!(tmp = malloc(sizeof(sol_t)))) {
        perror("[MEMORY_ERROR]Can't alocate new node");
        return NULL;
    }

    tmp->e = rand_in_n(head, sol);
    tmp->next_elem = NULL;

    return tmp;
}
