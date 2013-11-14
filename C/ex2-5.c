#include <stdio.h>
#include <stdbool.h>

void squeeze(char s1[], char s2[]){
	int i = 0;
	int j = 0;
	for (; s1[i] != '\0'; i++){
		bool in_s2 = false;
		for (int k =0; s2[k] != '\0' && !in_s2; k++){
			if(s1[i] == s2[k]){
				in_s2 = true;
			}
		}
		if (!in_s2){
			s1[j++] = s1[i];
		}
	}
	s1[j] = '\0';
}

int main(){
	char s1[] = "just4fun";
	char s2[] = "fu4";
	squeeze(s1, s2);
	printf("%s\n", s1);
	return 0;
}