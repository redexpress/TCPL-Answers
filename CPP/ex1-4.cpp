#include <iostream>
#include <iomanip>
#include <string>

int main(){
	double lower = 0;
	double upper = 300;
	double step = 20;
	double celsius = lower;
	std::cout << "fahr\tcelsius" << std::endl;
	std::cout.precision(1);
	while (celsius <= upper){
		double fahr = celsius * 9.0 / 5.0 + 32.0;
		std::cout <<  std::setw(3) << std::fixed << fahr << "\t" << std::setw(6) << celsius << std::endl;
		celsius += step;
	}
	return 0;
}

		
