#include "base.h"
#include "file_mgmt.h"
#include "algorithm.h"

#define  DEFAULT_RUNS 10

int main(int argc, char const *argv[]) {
    char name[20];
    int runs;
    float cost, best_cost = 0;;
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

    for (size_t i = 0; i < runs; i++) {

        //CREATES INTIAL SOLUTION RANDOMLY
        init_sol(&sol, head);

        //RUNS THE HILL CLIMBING METHOD
        cost = hill_climbing(head, &sol);
        printf("COST -> %.3f\n\n", cost );

        if (best_cost < cost) {
            best_cost = cost;
        }

    }

    printf("[BEST] %.3f\n", best_cost );
    //FREES  ALLOCATED MEMORY
    free_mem(head);
    return 0;
}
