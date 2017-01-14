#include "algorithm.h"
#include <math.h>

float TMAX = 1.0;
float TMIN  = 0.00001;

float get_dist(int a, int b, dist_t *head){
    float dist = 0;

    while (head != NULL) {
        if ( (a == head->e1 && b == head->e2) || (a == head->e2 && b == head->e1) ){
            dist = head->dist;
            break;
        }
        head = head->next;
    }
    return dist;
}
float f_diversity(sol_t* sol, dist_t *head){
    float total = 0;
    int n_elem = 0;
    sol_t *tmp;

    while (sol != NULL) {
        tmp = sol->next_elem;
        while (tmp) {
            total += get_dist(sol->e,tmp->e, head);
            tmp = tmp->next_elem;
        }
        sol = sol->next_elem;
        n_elem++;
    }

    free_mem_sol(tmp);
    return  total * 1/n_elem;
}
void crt_neighbour(dist_t* head, sol_t** new_sol, sol_t* sol){
    *new_sol = sol;
    crt_node(new_sol, head);
}
void hill_climbing(dist_t* head, sol_t ** sol, float* f_cost, int n_iter){
    float cost, new_cost;
    sol_t *new_sol, *tmp;

    tmp = *sol;

    printf("[INI SOL] -> ");
    while (tmp) {
        printf(" %d ", tmp->e );
        tmp = tmp->next_elem;
    }

    //CHECKS COST OF INITIAL SOLUTION
    cost = f_diversity(*sol, head);
    printf(" [QUALITY] -> %.3f\n", cost );

    for (size_t i = 0; i < n_iter; i++) {

        //CREATES NEIGHBOUR
        crt_neighbour(head, &new_sol, *sol);

        //CHECKS COST OF NEW NEIGHBOUR
        new_cost = f_diversity(*sol, head);

        //COST = QUALITY
        //+QUALITY = BETTER SOLUTION
        if (new_cost > cost) {
            *sol = new_sol;
            cost = new_cost;

            tmp = new_sol;
            printf("[NEW SOL] -> ");
            while (tmp) {
                printf(" %d ", tmp->e );
                tmp = tmp->next_elem;
            }
            printf(" [QUALITY] -> %.3f\n", new_cost );
        }else{
            delete_last(&new_sol);
        }

    }

    //FREES ALLOCATED MEMORY
    //free_mem_sol(new_sol);
    free_mem_sol(tmp);

    *f_cost = cost;
}
void simulated_annelling(dist_t* head, sol_t ** sol, float* f_cost, int n_iter){
    float cost, new_cost, temp = TMAX;
    sol_t *new_sol;
    int flag = 0;

    srand ( time(NULL) );

    cost = f_diversity(*sol, head);

    while (temp > TMIN) {
        for (size_t i = 0; i < 5; i++) {

            crt_neighbour(head, &new_sol, *sol);
            flag++;

            new_cost = f_diversity(*sol, head);

            printf("%d\n",accept_worse(cost, new_cost, temp) );
            int bool_ = accept_worse(cost, new_cost, temp);
            if (new_cost > cost || bool_) {
                *sol = new_sol;
                cost = new_cost;
            }else{
                delete_last(&new_sol);
                flag--;
            }
            if (flag == 19) {
                continue;
            }

        }
            temp = temp * 0.89;
        }
    *f_cost = cost;
}
int accept_worse(float cost, float new_cost, int temp){
    int n_rand;
    float a = 0;

    n_rand = rand() % 2;

    a = expf( (cost - new_cost) / temp);

    if (a >= n_rand && n_rand != 0)
        return 1;
    return 0;
}
void free_mem_sol(sol_t* head) {
    sol_t* tmp = NULL;

    while (head != NULL) {
        tmp = head->next_elem;
        free(head);
        head = tmp;
    }
}
void delete_last(sol_t** head){
    while (*head && (*head)->next_elem)
        head = &(*head)->next_elem;
    free(*head);
    *head = NULL;
}
void gen_mutation(dist_t* head, float* f_cost, int max){
    int pop_size  = 0 ,indicator = 0;
    float sum_quality = 0, quality = 0;
    sol_t** pop = NULL;
    sol_t** best_pop = NULL;

    //ASK POPULTAIONS SIZE
    do {
        printf("Population >  " );
        scanf("%d", &pop_size );
    } while(pop_size >= max);
    //ALLOCATES MEMORY TO HOLD THE POPULATION
    if(!(pop = malloc(sizeof(pop) * max - 1))){
        perror("[MEMORY ERROR] Can't alocate memory");
        return;
    }
    //CREATES RANDOMLY THE  POPULATION
    for (size_t i = 0; i < pop_size; i++){
        pop[i] = NULL;
        for (size_t o = 0; o < 6; o++)
            crt_neighbour(head, &pop[i], pop[i]);
        sum_quality += f_diversity(pop[i], head);
        }

    //ALLOCATES THE MEMORY FOR PARENTS
    if(!(best_pop = malloc(sizeof(best_pop) * pop_size/2))){
        perror("[MEMORY ERROR] Can't alocate memory");
        return;
    }

    for (size_t i = 0; i < pop_size/2; i++) {
        best_pop[i] = pop[i];
    }

        for (size_t i = 0; i < pop_size; i++) {
            printf("%.3f --  ", f_diversity(pop[i], head) );
            while (pop[i]) {
                printf(" %d ", pop[i]->e );
                pop[i] = pop[i]->next_elem;
            }
            printf("\n" );
        }

        printf("\n Parents \n" );
        for (size_t i = 0; i < pop_size / 2; i++) {
            while (best_pop[i]) {
                printf(" %d ", best_pop[i]->e );
                best_pop[i] = best_pop[i]->next_elem;
            }
            printf("\n" );
        }



}
