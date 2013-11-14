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

void itob(int n, char s[], int b, int width){
	if (b < 2 || b > 16){
        fprintf(stderr, "ERROR: base should be from 2 to 16\n");
        exit(EXIT_FAILURE);
	}
	static char digits[] = "0123456789ABCDEF";
    int i, sign;
    sign = n;
    i = 0;
    do {
        s[i++] = digits[abs(n % b)];
    } while (n /= b);
    if (sign < 0)
        s[i++] = '-';
    while (i < width){
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}

int main(){
	char buf[50];
	itob(INT_MIN, buf, 2, 40);
	printf("%s\n", buf);
	return 0;
}