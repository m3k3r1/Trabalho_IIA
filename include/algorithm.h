#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include "base.h"
#include <stdio.h>

float get_dist(int a, int b, dist_t *head);
float f_diversity(sol_t* sol, dist_t *head);
void crt_neighbour();
void hill_climbing(dist_t* head, sol_t **sol, float* f_cost, int n_iter);
void simulated_annelling(dist_t* head, sol_t ** sol, float* f_cost, int n_iter);
int accept_worse(float cost, float new_cost, int temp);
void free_mem_sol(sol_t* head);
void delete_last(sol_t** head);

#endif //!_ALGORITHM_H_
