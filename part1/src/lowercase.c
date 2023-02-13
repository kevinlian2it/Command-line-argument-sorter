#include <stdio.h>
#include <stdlib.h>
#include "mystring.h"
/**
 * Take an array of char* pointers and print each of the strings to standard
 * out. This function must use only pointer arithmetic and no array
 * subscripting. The output start with "[", ends with "]\n", and prints the
 * strings inside, each separated by a comma and space.
 * Example: [Hi, BYE, AP, COMSW 3157, FunTimes]
 */
void display_strings(char **strings) {
    printf("[");
    if (strings != NULL) {
        char **str_ptr = strings;
        if (*str_ptr != NULL) {
            printf("%s", *str_ptr++);
            while (*str_ptr != NULL) {
                printf(", %s", *str_ptr++);
            }
        }
    }
    printf("]\n");
}

static char **copy_args_lowercase(int argc, char **argv) {
    char **copy = malloc((argc+1)*sizeof(char *));
    if (!copy) return NULL;
    for (int i=1;i!=argc;i++){
	size_t len = my_strlen(argv[i]);
	copy[i] = malloc(len+1);
	if (!copy[i]){ 
	    for(int j=1;j!=i;j++){
		free(copy[j]);
	    }
	    free(copy);
	    return NULL;
	}
	my_strcpy(copy[i],argv[i]);
	my_strlower(copy[i]);
    }
    copy[argc] = NULL;   
    return copy;
}

static void free_copy(char **copy) {
    if (!copy) return;
    int i = 0;
    while (copy[i]){
	free(copy[i]);
	i++;
    }
    free(copy);
}


/**
 * DO NOT MODIFY main()
 */
int main(int argc, char **argv) {
    char **copy;
    copy = copy_args_lowercase(argc, argv);

    printf("Raw arguments       : ");
    display_strings(argv + 1);

    printf("Lowercase arguments : ");
    display_strings(copy);

    free_copy(copy);

    return EXIT_SUCCESS;
}
