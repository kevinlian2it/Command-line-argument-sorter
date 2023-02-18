#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void print_list(linked_list *list, void (*print_function)(void*)) {
    putchar('[');
    node *cur = list->head;
    if (cur != NULL) {
        print_function(cur->data);
        cur = cur->next;
    }
    for ( ; cur != NULL; cur = cur->next) {
        printf(", ");
        print_function(cur->data);
    }
    printf("]\n{length: %lu, head->data: ", list->size);
    list->head != NULL ? print_function(list->head->data) :
                         (void)printf("NULL");
    printf(", tail->data: ");
    list->tail != NULL ? print_function(list->tail->data) :
                         (void)printf("NULL");
    printf("}\n\n");
}

linked_list* create_linked_list() {
	linked_list *list = malloc(sizeof(linked_list));
	if(list == NULL) {
		return NULL;
	}
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;

	return list;
}

bool insert_in_order(linked_list *list, void *data, int (*cmp)(const void*, const void*)) {
	node *new_node = create_node(data);
    	if (list->head == NULL) { // list is empty
        	list->head = new_node;
        	list->tail = new_node;
        	list->size = 1;
        	return true;
    	}

    	node *current = list->head;
    	node *previous = NULL;

    	while(current != NULL && cmp(&new_node->data, &current->data) > 0) {
        	previous = current;
        	current = current->next;
    	}

    	if(previous == NULL) { // new node is the new head of the list
        	new_node->next = list->head;
        	list->head = new_node;
    	} else if(current == NULL) { // new node is the new tail of the list
        	previous->next = new_node;
       	 	list->tail = new_node;
    	} else { // new node is somewhere in the middle of the list
        	previous->next = new_node;
        	new_node->next = current;
    	}
    	list->size++;
	return true;
}
void free_list(linked_list *list, void (*free_data)(void *)) {
    if (list == NULL) {
        return;
    }

    node *current = list->head;
    while(current != NULL) {
        node *next = current->next;
        free_node(current, free_data);
        current = next;
    }
    free(list);
}
