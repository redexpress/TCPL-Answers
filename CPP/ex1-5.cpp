#include <iostream>
#include <iomanip>
#include <string>

int main(){
	std::cout << "fahr\tcelsius" << std::endl;
	std::cout.precision(1);
	for (int fahr = 300; fahr >=0; fahr -= 20){
		std::cout <<  std::setw(3) << std::fixed << fahr << "\t" << std::setw(6) << (5.0/9.0) * (fahr-32) << std::endl;
	}
	return 0;
}
