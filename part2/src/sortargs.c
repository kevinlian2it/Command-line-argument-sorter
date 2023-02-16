#include <stdio.h>
#include <string.h>
#include "linked_list.h"

int cmp(const void *a, const void *b) {
	int result = strcmp(*(const char**)a, *(const char**)b);
        if (result < 0) {
                return -1;
        } else if (result == 0) {
                return 0;
        } else {
                return 1;
        }
}

void print_string(void *data) {
	printf("\"");
	printf("%s", (char*)data);
	printf("\"");
}

void free_string(void *data) {
	free(data);
}

int main(int argc, char **argv) {
        linked_list *list = create_linked_list();
	print_list(list,print_string);
	for(int i = 1;i < argc;i++) {
                size_t length = strlen(argv[i])+1;
                char *data = (char*)malloc(length);
                memcpy(data,argv[i],length);
                insert_in_order(list,data,cmp);
                print_list(list,print_string);
	}
	free_list(list,free_string);
    return EXIT_SUCCESS;
}
<<<<<<< HEAD
=======


>>>>>>> ca9b22bb86dc14fb54609e2e6103b1a98f85876b
