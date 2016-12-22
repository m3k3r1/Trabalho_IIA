#ifndef _FILE_MGMT_H_
#define  _FILE_MGMT_H_

#include <stdio.h>
#include <stdlib.h>

#define FILE_LOC "res/%s"

typedef struct dist dist_t;
struct dist{
    int e1;
    int e2;
    float dist;
    dist_t* next;
};

void read_from(char* file_name, dist_t** head);
void free_mem(dist_t* head);

#endif //!_FILE_MGMT_H_
