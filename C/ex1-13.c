#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_LENGTH 20

int main(){
    int state = OUT;
    int c;
    int length[MAX_LENGTH] = {};
    int index = 0;
    while ((c = getchar()) != EOF){
        if(c == ' ' || c == '\t' || c == '\n'){
            if(state == OUT){
                state = IN;
                if (length[0] != 0){
                    index++;
                }
                if (index > MAX_LENGTH){
                    break;
                }
            }
        } else {
            state = OUT;
            length[index]++;
        }
    }
    for (int i = 0; i<index; i++){
        printf("%d ", length[i]);
        for (int j = 0; j< length[i]; j++){
            putchar('*');
        }
        printf("\n");
    }
    return 0;
}