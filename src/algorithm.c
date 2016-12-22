#include "algorithm.h"

float get_dist(int a, int b, dist_t *head){
    float quality = 0;

    while (head != NULL) {
        if ( (a == head->e1 && b == head->e2) || (a == head->e2 && b == head->e1) ){
            quality = head->dist;
            break;
        }
        head = head->next;
    }
    return quality;
}

float f_diversity(int n_subjects, int *test_objects, dist_t *head){
    float total = 0;

    for (size_t i = 0; i < n_subjects - 1; i++) {
        for (size_t o = 1; o < n_subjects ; o++) {
            if (i == o || o < i)
                continue;

            total += get_dist(test_objects[i],  test_objects[o], head);
        }
    }

    return  total * 1/n_subjects;
}
