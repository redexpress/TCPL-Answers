#include <stdio.h>
#include <string.h>

void str_cpy(char *s, char *t){
	while ((*s++ = *t++)){
	}
}

void str_cat(char *s, char *t){
	while (*s){
		s++;
	}
	while ((*s++ = *t++)){
	}
}

int main(){
	char *buf;
	char *str = "hello, world!";
	str_cat(buf, str);
	printf("%s\n", buf);
	strcat(buf, str);
	printf("%s\n", buf);
	return 0;
}
