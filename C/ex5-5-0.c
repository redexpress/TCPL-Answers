#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char * str_cpy(char *s, const char *t){
	char *save = s;
	while((*s++ = *t++)){
	}
	return save;
}

int str_cmp(const char *s, const char *t){
	for ( ; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}

int str_len(const char *s){
	const char *p = s;
	while (*p != '\0')
		p++;
	return p - s;
}

int main(){
 	return 0;
}
