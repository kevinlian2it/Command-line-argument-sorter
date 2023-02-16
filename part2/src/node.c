#include <stdlib.h>
#include "node.h"

node* create_node(void *data) {
    node *n = (node *)malloc(sizeof(node));
    if (n != NULL) {
        n->data = data;
        n->next = NULL;
        n->prev = NULL;
    }
    return n;
}

<<<<<<< HEAD
void free_node(node *n, void(*free_data)(void *)){
	free_data(n->data);
	free(n);
=======
void free_node(node *n, void (*free_data)(void *)) {
    if(n == NULL) return;
	free_data(n->data);
    	free(n);
>>>>>>> ca9b22bb86dc14fb54609e2e6103b1a98f85876b
}
