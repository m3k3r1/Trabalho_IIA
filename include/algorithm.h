#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "base.h"

float get_dist(int a, int b, dist_t *head);
float f_diversity(int n_subjects, int *test_objects, dist_t *head);

#endif //!_ALGORITHM_H_
