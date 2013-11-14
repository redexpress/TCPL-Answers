#include <stdio.h>

#define swap(t, x, y) do { t tmp; tmp = x; x=y; y=tmp;} while(0)

int main(){
    int a = 3;
    int b = 6;
    swap(int, a, b);
    printf("%d %d\n", a, b);
    return 0;
}