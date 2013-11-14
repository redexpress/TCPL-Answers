#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itoa_recur(int n, char s[]){
    if (abs(n) < 10){
        if (n < 0){
            s[0] = '-';
            s[1] = '0' - n;
            s[2] = '\0';
        } else {
            s[0] = '0' + n;
            s[1] = '\0';
        }
    } else {
        int i = (n<0 ? -n : n) % 10;
        char s1[20] = {'0'+i, '\0'};
        char num[20] = "";
        itoa_recur(n/10, s);
        strcat(s,s1);
    }
}

int main(){
    char buf[50];
    itoa_recur(-123457642, buf);
    printf("%s\n", buf);
    return 0;
}