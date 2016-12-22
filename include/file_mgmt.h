#ifndef _FILE_MGMT_H_
#define  _FILE_MGMT_H_

#include "base.h"

#define FILE_LOC "res/%s.txt"

void read_from(char* file_name, dist_t** head);
void free_mem(dist_t* head);
void crt_neighbour();
int hill_climbing();

#endif //!_FILE_MGMT_H_
