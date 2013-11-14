#include <stdio.h>

void escape(char s[], char t[]){
	int j = 0;
	for (int i=0; t[i] != '\0'; i++, j++){
		switch(t[i]){
			case '\n':
				s[j++] = '\\';
				s[j] = 'n';
				break;
			case '\t':
				s[j++] = '\\';
				s[j] = 't';
				break;
			case '\\':
				s[j++] = '\\';
				s[j] = '\\';
				break;
			default:
				s[j] = t[i];
				break;
		}
	}
	s[j] = '\0';
}


int main(){
	char source[] = "one\ttwo\nthree\\four";
	char target[100];
	escape(target, source);
	printf("%s\n", target);
	return 0;
}