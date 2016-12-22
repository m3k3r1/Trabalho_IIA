#include "file_mgmt.h"

void read_from(char* name, dist_t** head){
    char file_name[20];
    dist_t tmp;

    sprintf(file_name, FILE_LOC, name);

    FILE *f = fopen(file_name, "r");

    if ( f == NULL ) {
        perror("[ERROR]Cannot open file");
        return;
    }

    while (fscanf(f, "%d %d %f", &tmp.e1, &tmp.e2, &tmp.dist ) == 3) {
        if ( !( *head = malloc(sizeof(**head)) ) ){
            perror("[ERROR]Cannot alocate new node");
            return;
        }

        tmp.next = NULL;
        **head = tmp;
        head = &(*head)->next;
    }
    fclose(f);
}
