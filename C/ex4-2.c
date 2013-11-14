#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <signal.h>
#include <string.h>


//atof no scientific notation 
double atof_ne(char s[]){
    double val, power;
    int i, sign;
    for (i = 0; isspace(s[i]); i++){
        //skip white space
    }

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10; 
    }
    return sign * val / power;
}

double atof(char s[]){
    char seps[] = "eE"; 
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


int main(){
    char str[] = "31.4e2";
    printf("%lf\n", atof(str));
	return 0;
}