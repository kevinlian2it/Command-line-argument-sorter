#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "linked_list.h"

// Define a comparison function for integer values
int cmp_int(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

// Define a print function for integer values
void print_int(void *data) {
    printf("%d", *(int *)data);
}

// Define a free function for integer values
void free_int(void *data) {
    free(data);
}

int main() {
    // Test creating a linked list
    linked_list *list = create_linked_list();
    if (list == NULL) {
        fprintf(stderr, "Error creating linked list.\n");
        return 1;
    }

    // Test inserting elements into the linked list in order
    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));
    int *c = malloc(sizeof(int));
    *a = 1;
    *b = 2;
    *c = 3;

    insert_in_order(list, a, cmp_int);
    insert_in_order(list, c, cmp_int);
    insert_in_order(list, b, cmp_int);

    // Test printing the linked list
    print_list(list, print_int);

    // Test freeing the linked list
    free_list(list, free_int);

    return 0;
}
