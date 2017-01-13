#include "base.h"

int get_max(dist_t* head){
    int max = 0;

    while (head) {
        if (head->e2 > max) {
            max = head->e2;
        }
        head = head->next;
    }

    return max;
}


int rand_in_n(dist_t* head, sol_t * sol){
    int max= 0, tmp, allow = 0;
    sol_t* aux = sol;

    while (head) {
        if (head->e2 > max) {
            max = head->e2;
        }
        head = head->next;
    }

    do {
        tmp =  1 + rand() % max;

            if ( aux == NULL) {
                if (tmp == 0)
                    allow = 0;
                else
                    allow = 1;

            }else{
                while (aux) {
                        if (aux->e == tmp || tmp == 0) {
                            allow = 0;
                            break;
                        }
                        else
                            allow = 1;
                        aux =  aux->next_elem;
                }
                aux = sol;
            }

    } while(!allow);


    return tmp;
}

void init_sol(sol_t** sol, dist_t* head){
    *sol = add_rand_elem(head, *sol);
    (*sol)->next_elem = add_rand_elem(head, *sol);
}

void crt_node(sol_t ** sol, dist_t* head){
    sol_t *tmp = *sol;

    while ( *sol )
        sol = &(*sol)->next_elem;
    *sol= add_rand_elem(head, tmp);
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
