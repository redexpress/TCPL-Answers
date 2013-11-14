#include <iostream>

int main(){
	int blanks = 0;
	int tabs = 0;
	int newlines = 0;
	int c;
	while ((c = getchar()) != EOF){
		if(c == ' '){
			blanks++;
		} else if (c == '\t'){
			tabs++;
		} else if (c == '\n'){
			newlines++;
		}
	}
	std::cout << blanks << " " << tabs << " " << newlines << std::endl;
	return 0;
}