#include <cstdio>

int main(){
    //for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i) s[i] = c;
    int lim = 10;
    char s[lim];
    int i;
	for (i=0; i < lim-1; i++){
		int c=getchar();
		if (c == '\n'){
			break;
		} else if (c == EOF){
			break;
		}

		s[i] = c;
	}
	s[i] = '\0';
	return 0;
}