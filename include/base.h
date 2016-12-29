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

int rand_in_n(dist_t* head);
void init_sol(int** sol, dist_t* head);

#endif //!_BASE_H_
