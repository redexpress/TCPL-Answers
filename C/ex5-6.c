#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE 1000
#define MIN_LINE 5
#define BUFSIZE 100

static char buf[BUFSIZE];  /* buffer for ungetch */
static int bufp = 0;       /* next free position in buf */

int get_line(char *s, int lim);
void itoa_recur(int n, char *s);
char * itoa(int n, char *s);
void swap(char *a, char *b);
char * reverse(char *s);
int getch();
void ungetch(int c);
double atof_ne(const char *s);
double my_atof(char *s); //TODO: change to const
int my_atoi(const char *s);
int getop(char *s);

int main(){

	//test my_atoi
	char *num = "33";
	printf("test atoi: %d\n", my_atoi(num));

	//test my_atof
	char str[] = "31.4e2";
    printf("test atof: %lf\n", atof(str));

    //test reverse
    printf("test reverse: %s, %s\n", str, reverse(str));

    //test itoa
    char numstr[10];
    printf("test itoa: %s, %s\n", numstr, itoa(123456789, numstr));
    itoa_recur(123456789, numstr);
    printf("test itoa_recur: %s\n", numstr);

	//test get_line
	char line[MAX_LINE];
	char copyline[MAX_LINE];
	int len;
	while ((len = get_line(line, MAX_LINE)) > 0){
		if (len > MIN_LINE){
			strcpy(copyline, line);
			printf("test getline: %s", copyline);
		}
	}
	return 0;
}

int get_line(char *s, int lim){
	int c;
	char *p = s;
    int i;
	while (--lim > 0 && (c=getchar())!=EOF && c!='\n'){
		*p++ = c;
	}
	if (c == '\n') {
        *p++ = c;
	}
    *p = '\0';
    return p - s;
}

void itoa_recur(int n, char *s){
    if (abs(n) < 10){
        if (n < 0){
            *s++ = '-';
            *s++ = '0' - n;
            *s = '\0';
        } else {
            *s++ = '0' + n;
            *s = '\0';
        }
    } else {
        int i = (n<0 ? -n : n) % 10;
        char s1[20] = {'0'+i, '\0'};
        char num[20] = "";
        itoa_recur(n/10, s);
        strcat(s,s1);
    }
}

char * itoa(int n, char *s)
{
    int sign;
    char *save = s;
    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    do {      /* generate digits in reverse order */
        *s++ = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        *s++ = '-';
    *s = '\0';
    reverse(s);
    return save;
}

void swap(char *a, char *b){
	int t = *a;
	*a = *b;
	*b = t;
}

char * reverse(char *s) {
	char *save = s;
	char *p = s;
	char *q = s += (strlen(s)-1);
    for (; p < q; p++, q--) {
        swap(p, q);
    }
    return save;
}

#define NUMBER  '0'  /* signal that a number was found */

int getop(char s[])
{
    int c;
    while ((*s = c = getch()) == ' ' || c == '\t')
        ;
    *(s+1) = '\0';
    if (!isdigit(c) && c != '.')
        return c;      /* not a number */
    if (isdigit(c))    /* collect integer part */
        while (isdigit(*++s = c = getch()))
            ;
    if (c == '.')      /* collect fraction part */
        while (isdigit(*++s = c = getch())){
        }
    *s = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

int getch(){  /* get a (possibly pushed-back) character */
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){   /* push character back on input */
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

double atof_ne(const char *s){
    double val, power;
    int sign;
    while (isspace(*s))
    	s++;
    sign = (*s == '-') ? -1 : 1;
	if (*s == '+' || *s == '-')
		s++;
    for (val = 0.0; isdigit(*s); s++)
        val = 10.0 * val + (*s - '0');
    if (*s == '.')
        s++;
    for (power = 1.0; isdigit(*s); s++) {
        val = 10.0 * val + (*s - '0');
        power *= 10; 
    }
    return sign * val / power;
}

double my_atof(char *s){
    char *seps = "eE"; 
    char *token;
    char *token1;
    char *token2;

    token = strtok( s, seps );
    int i = 0;
    while( token != NULL ){
        if(i==0 && token != NULL){
            token1 = token;
        }
        token = strtok(NULL, seps);
        i++;
        if(i==1 && token != NULL){
            token2 = token;
        }
    }

    double d = atof_ne(token1);
    double d2 = 1.0;

    if (token2 != NULL){
        d2 = pow(10, atof_ne(token2));
    }
    return d * d2;
}

int my_atoi(const char *s){
	int n, sign;
	while(isspace(*s))
		s++;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '+' || *s == '-')
		s++;
	for (n = 0; isdigit(*s); s++)
		n = 10 * n + (*s - '0');
	return sign * n;
}

