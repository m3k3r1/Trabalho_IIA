#ifndef _BASE_H_
#define _BASE_H_

#include <stdbool.h>

typedef struct dist dist_t;
struct dist{
    int e1;
    int e2;
    float dist;
    dist_t* next;
};

#endif //!_BASE_H_
