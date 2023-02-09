#include "mystring.h"
#include <stddef.h>

// return the length as a size_t
size_t my_strlen(char *src){
	if (!src) return 0;
	size_t len = 0;
	while (*src++)
		len++;
	return len;
}

// return a pointer to dst.
char *my_strcpy(char *dst, char *src){
	if (!src) return NULL;
	char *ptr = dst;
	while (*src) {
		*ptr = *src;
		ptr++;
		src++;	
	}
	*ptr = '\0';
	return dst;
}

// convert to lower
void my_strlower(char *src){
	if (!src) return;
	for (int i=0;src[i];i++){
		src[i]=tolower(src[i]);
	}
}
