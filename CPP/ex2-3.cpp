#include <iostream>

using std::string;

int htoi(string s){
	int i = 0;
	if (s[i] == '0'){
		i++;
		if(s[i] == 'x' || s[i] == 'X'){
			i++;
		} else {
			return 0;
		}
	}
	int result = 0;
	for(; s[i] != '\0'; i++){
		result *= 16;
		if(s[i] >= '0' && s[i] <= '9'){
			result += (s[i] - '0');
		} else if(s[i] >= 'A' && s[i] <= 'F'){
			result += (10 + s[i] - 'A');
		} else if(s[i] >= 'a' && s[i] <= 'f'){
			result += (10 + s[i] - 'a');
		} else {
			return 0;
		}
	}
	return result;
}

int main(){
	string test = "0xF2";
	printf("%d\n", htoi(test));
	return 0;
}