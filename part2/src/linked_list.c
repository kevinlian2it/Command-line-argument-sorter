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

	if(list == NULL) {
		return false;
	}
	node *new_node = create_node(data);
	if(new_node == NULL) {
		return false;
	}
	if (list->head == NULL) {
		list->head = new_node;
		list->tail = new_node;
		list->size++;
		return true;
	}
	node *current = list->head;
	if (cmp(data, current->data) < 0) {
                new_node->next = list->head;
                list->head = new_node;
                list->size++;
                return true;
        }
	while (current->next != NULL && cmp(data, current->next->data) > 0) {
		current = current->next;
	}

	new_node->next = current->next;
	current->next = new_node;
	if(new_node->next == NULL) {
		list->tail = new_node;
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
<<<<<<< HEAD
=======

>>>>>>> ca9b22bb86dc14fb54609e2e6103b1a98f85876b
