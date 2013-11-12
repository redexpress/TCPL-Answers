#include <stdio.h>

#define IN 1
#define OUT 0

int main(){
	int state = OUT;
	int c;
	while ((c = getchar()) != EOF){
		if(c == ' '){
			if(state == OUT){
				state = IN;
				putchar(c);
			}
		} else {
			state = OUT;
			putchar(c);
		}
	}
	return 0;
}