#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define BUFSIZE 100
char buf[BUFSIZE];    /* buffer for ungetch */
int bufp = 0;         /* next free position in buf */

int getch(void){  /* get a (possibly pushed-back) character */
   return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){   /* push character back on input */
   if (bufp >= BUFSIZE)
	   printf("ungetch: too many characters\n");
   else
	   buf[bufp++] = c;
}

int getint(int *pn){
    int c, sign;
    while (isspace(c = getch()))   /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);  /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    bool sign_showed = false;
    if ((sign_showed = (c == '+' || c == '-')))
        c = getch();
    if(!isdigit(c)){
    	ungetch(c);
    	if(sign_showed)
    		ungetch((sign == -1) ? '-' : '+');
    	return 0;
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int main(){
	return 0;
}
