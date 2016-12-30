#include "base.h"
#include "file_mgmt.h"
#include "algorithm.h"

#define  DEFAULT_RUNS 10

int main(int argc, char const *argv[]) {
    char name[20];
    int runs;
    float cost;
    sol_t* sol = NULL;
    dist_t* head = NULL;

    srand(time(0));

    if (argc == 3) {
        runs = atoi(argv[2]);
        strcpy(name, argv[1]);
    } else if ( argc == 2) {
        runs = DEFAULT_RUNS;
        strcpy(name, argv[1]);
    } else if (argc == 1) {
        printf("Name > " );
        scanf("%s", name );
    }

    //PUTS THE FILE INFO IN THE LINKED LIST
    read_from(name, &head);

    for (size_t i = 0; i < 1; i++) {

        //CREATES INTIAL SOLUTION RANDOMLY
        init_sol(&sol, head);

        //RUNS THE HILL CLIMBING METHOD
        cost = hill_climbing(head, &sol);
        printf("COST -> %.3f\n", cost );

    }

    //FREES  ALLOCATED MEMORY
    free_mem(head);
    return 0;
}
