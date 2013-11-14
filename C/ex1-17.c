#include <stdio.h>
#define MAX_LINE 1000
#define MIN_LINE 81

int get_line(char s[], int lim);
void copy(char to[], char from[]);

int main(){
	char line[MAX_LINE];
	char copyline[MAX_LINE];
	int max = 0;
	int len;
	while ((len = get_line(line, MAX_LINE)) > 0){
		if (len > MIN_LINE){
			copy(copyline, line);
			printf("%s", copyline);
		}
	}
	return 0;
}

int get_line(char s[], int lim){
	int c;
	int i;
	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++){
		s[i] = c;
	}
	if (c == '\n') {
        s[i] = c;
        i++;
	}
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]){
	int i = 0;
	while ((to[i] = from[i]) != '\0'){
		i++;
	}
}