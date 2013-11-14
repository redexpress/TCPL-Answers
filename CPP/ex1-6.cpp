#include <iostream>

int main(){
	//press control-D in UNIX or control-Z in Windows you get 0
	std::cout << (std::getchar() != EOF) << std::endl;
	return 0;
}
