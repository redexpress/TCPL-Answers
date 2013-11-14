#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int strend(char *s, char *t){
	int result = 0;
	int s_length = strlen(s);
	int t_length = strlen(t);
	if(t_length <= s_length){
		s += s_length - t_length;
		if(strcmp(s, t) == 0){
			return 1;
		}
	}
	return 0;
}

int endWith(char *s, char *t){
	return strend(s, t) == 1;
}

int main(){
	char *foo = "foo";
	char *bar = "bar";
	char *foobar = "foobar";
	printf("%d\n", endWith(foobar, foo));
	printf("%d\n", endWith(foobar, bar));

 	return 0;
}
