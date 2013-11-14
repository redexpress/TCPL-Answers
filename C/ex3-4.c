#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

void swap(char *a, char *b){
	int t = *a;
	*a = *b;
	*b = t;
}

void reverse(char s[]) {
	int i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        swap(&s[i], &s[j]);
    }
}

void itob(int n, char s[]){
    int i, sign;
    sign = n;
    i = 0;
    do {
        s[i++] = abs(n % 10)+ '0';
    } while (n /= 10);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}



int main(){
	char buf[20];
	itob(INT_MIN, buf);
	printf("%s\n", buf);
	return 0;
}