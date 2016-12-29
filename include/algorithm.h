#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include "base.h"
#include <stdio.h>


float get_dist(int a, int b, dist_t *head);
float f_diversity(int n_objects, int *test_objects, dist_t *head);
void crt_neighbour();
float hill_climbing(dist_t* head, int **sol);

#endif //!_ALGORITHM_H_
