#include <stdio.h>

int main(){
	//press control-D in UNIX or control-Z in Windows you get 0
	printf("%d\n", getchar() != EOF);
	return 0;
}
