#include <stdio.h>

int strrindex(char s[], char t){
    int result = -1;
    for (int i = 0; s[i] != '\0'; i++){
        if (s[i] == t){
            result = i;
        }
    }
    return result;
}

int main(){
    char str[] = "foobar";
	printf("%d %d\n", strrindex(str, 'y'), strrindex(str, 'b'));
	return 0;
}