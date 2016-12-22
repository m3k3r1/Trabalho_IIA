#include <stdio.h>
#include "file_mgmt.h"

int main(int argc, char const *argv[]) {
    char name[20];
    dist_t* head = NULL;

    printf("Name > " );
    scanf("%s", name );

    read_from(name, &head);

    free_mem(head);
    return 0;
}
