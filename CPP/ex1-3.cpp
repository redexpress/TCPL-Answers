#include <iostream>
#include <iomanip>
#include <string>

int main(){
	double lower = 0;
	double upper = 300;
	double step = 20;
	double fahr = lower;
	std::cout << "fahr\tcelsius" << std::endl;
	std::cout.precision(1);
	while (fahr <= upper){
		double celsius = (5.0/9.0) * (fahr-32.0);
		std::cout <<  std::setw(3) << std::fixed << fahr << "\t" << std::setw(6) << celsius << std::endl;
		fahr += step;
	}
	return 0;
}
		
