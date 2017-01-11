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
    sol_t *new_sol, *tmp;
    int flag = 1;

    srand ( time(NULL) );

    n_iter = get_max(head);

    tmp = *sol;

    printf("[INI SOL] -> ");
    while (tmp) {
        printf(" %d ", tmp->e );
        tmp = tmp->next_elem;
    }

    //CHECKS COST OF INITIAL SOLUTION
    cost = f_diversity(*sol, head);
    printf(" [QUALITY] -> %.3f\n", cost );

    while (temp > TMIN) {
        for (size_t i = 0; i < n_iter; i++) {
            //CREATES NEIGHBOUR
            crt_neighbour(head, &new_sol, *sol);
            //CHECKS COST OF NEW NEIGHBOUR
            new_cost = f_diversity(*sol, head);
            //COST = QUALITY
            //+QUALITY = BETTER SOLUTION
            if (new_cost > cost) {
                flag++;
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
                if ( accept_worse(cost, new_cost, temp) ) {
                    flag++;
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
            printf("%d\n", flag );
            if (flag  == 19 )
                break;

        }

        temp *= 0.8;
    }

    *f_cost = cost;
}
int accept_worse(float cost, float new_cost, int temp){
    int a = 0;
    int n_rand;
    float a_tmp;

    n_rand = rand() %2;

    a_tmp = expf( (cost - new_cost) / temp);

    if (a_tmp >= n_rand) {
        a = 1;
    }

    return a;
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
