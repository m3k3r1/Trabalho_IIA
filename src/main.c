#include <stdio.h>
#include "file_mgmt.h"
#include "algorithm.h"

int main(int argc, char const *argv[]) {
    char name[20];
    int *sol, *best_sol;
    int cost, best_cost
    dist_t* head = NULL;

    //PUTS THE FILE INFO IN THE LINKED LIST
    printf("Name > " );
    scanf("%s", name );
    read_from(name, &head);

    // _____________________________________
    //CREATE INITIAL SOLUTION

    //RUN THE HILL CLIMBING METHOD

    //WRITE RESULTS
    //______________________________________

    //WRITE BEST END RESULTS


    //FREES THE MEMORY ALLOCATED FOR THE LINKED LIST
    free_mem(head);
    return 0;
}
