#include <stdio.h>

int main(){
	double lower = 0;
	double upper = 300;
	double step = 20;
	double celsius = lower;
	printf("celsius fahr\n");
	while (celsius <= upper){
		double fahr = celsius * 9.0 / 5.0 + 32.0;
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius += step;
	}
	return 0;
}
		
