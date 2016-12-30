#ifndef _BASE_H_
#define _BASE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <string.h>

typedef struct dist dist_t;
struct dist{
    int e1;
    int e2;
    float dist;
    dist_t* next;
};

typedef struct sol sol_t;
struct sol{
    int e;
    sol_t* next_elem;
};

int rand_in_n(dist_t* head, sol_t * sol);
int get_max(dist_t* head);
void init_sol(sol_t** sol, dist_t* head);
sol_t * add_rand_elem(dist_t* head, sol_t * sol);
void crt_node(sol_t ** sol, dist_t* head);

#endif //!_BASE_H_
