#include "base.h"
#include "file_mgmt.h"
#include "algorithm.h"

#define  DEFAULT_RUNS 10

int main(int argc, char const *argv[]) {
    char name[20];
    int runs, n_iter;
    float best_cost = 0, avg = 0;
    float cost;
    sol_t* sol = NULL;
    sol_t* tmp;
    dist_t* head = NULL;
    //pthread_t* divide_to_conquer;
    time_t start, end, duration;
    start = time (0);

    srand(time(0));

    if (argc == 3) {
        runs = atoi(argv[2]);
        strcpy(name, argv[1]);
    } else if ( argc == 2) {
        runs = DEFAULT_RUNS;
        strcpy(name, argv[1]);
    } else if (argc == 1) {
        runs = DEFAULT_RUNS;
        printf("Name > " );
        fgets(name, sizeof(name), stdin);
        strtok (name, "\n");
    }

    //PUTS THE FILE INFO IN THE LINKED LIST
    read_from(name, &head);
    n_iter = runs;
    //divide_to_conquer = malloc(sizeof(pthread_t) * runs);
    //cost = malloc(sizeof(cost) * runs);

    int max = get_max(head);

    gen_mutation(head, &sol, &cost, max);
/*
    for (size_t i = 0; i < runs; i++) {
        //CREATES INTIAL SOLUTION RANDOMLY
        init_sol(&sol, head);

        //TO DO divide work load in threads
        //pthread_create(divide_to_conquer[i], NULL, hill_climbing(head, &sol, &cost), NULL)

        //RUNS THE HILL CLIMBING METHOD
        hill_climbing(head, &sol, &cost, n_iter);
        //RUNS THE simulated_annelling
        //simulated_annelling(head, &sol, &cost, n_iter);
        avg += cost;
        printf("QUALITY -> %.3f\n\n", cost );

        if (best_cost < cost)
            best_cost = cost;
    }

    printf("==============================================================================================\n" );
    printf(" [BEST] >> %.3f\n", best_cost );
    printf(" [AVERAGE] >> %.3f\n",avg/runs);
    printf(" [BEST SOL] >> ");
    tmp = sol;
    while (tmp) {
        printf(" %d ", tmp->e );
        tmp = tmp->next_elem;
    }

    end = time (0);
    duration = end - start;
    printf("\n [ELAPSED TIME]  >> %lus\n", duration );
    printf("==============================================================================================\n" );

    //FREES  ALLOCATED MEMORY
    free_mem_sol(sol);*/
    free_mem(head);
    return 0;
}
