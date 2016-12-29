#include "algorithm.h"

float get_dist(int a, int b, dist_t *head){
    float dist = 0;

    while (head != NULL) {
        if ( (a == head->e1 && b == head->e2) || (a == head->e2 && b == head->e1) ){
            dist = head->dist;
            break;
        }
        head = head->next;
    }
    return dist;
}
float f_diversity(int n_objects, int *test_objects, dist_t *head){
    float total = 0;

    for (size_t i = 0; i < n_objects - 1; i++) {
        for (size_t o = 1; o < n_objects ; o++) {
            if (i == o || o < i)
                continue;
            total += get_dist(test_objects[i],  test_objects[o], head);
        }
    }

    return  total * 1/n_objects;
}
void crt_neighbour(dist_t* head, int** new_sol, int *sol){
    int *tmp;

    if ( ! (tmp = malloc( sizeof(*sol) + sizeof(int) )) ) {
        perror("[MEMORY_ERROR]Can't alocate new node");
        return;
    }


    tmp = sol;
    tmp[2] = rand_in_n(head);

    *new_sol = tmp;
}
float hill_climbing(dist_t* head, int ** sol){
    float cost, new_cost;
    int *new_sol;

    //CHECKS COST OF INITIAL SOLUTION
    cost = f_diversity(2, *sol, head);

    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //SOL[1] MUDA AO ENTRAR  SÒ PRINTF WTF
    printf("[INIT SOL] (%d-%d) -> %.3f\n",*sol[0], *sol[1], cost );
    //MUDA PARA O VALOR CERTO DEPOIS WTF !!!!!!!!!!
  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    //CREATES NEIGHBOUR
    crt_neighbour(head, &new_sol, *sol);

    //CHECKS COST OF NEW NEIGHBOUR
    new_cost = f_diversity(3, new_sol, head);
    printf("[NEW SOL] (%d-%d-%d) -> %.3f\n",new_sol[0], new_sol[1], new_sol[2], new_cost );

    //COST = QUALITY
    //+QUALITY = BETTER SOLUTION
    if (new_cost > cost) {
        *sol = new_sol;
        cost = new_cost;
    }

    //FREES ALLOCATED MEMORY
    free(new_sol);
    return cost;
}
