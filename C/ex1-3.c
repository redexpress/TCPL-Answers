#include <stdio.h>

int main(){
	double lower = 0;
	double upper = 300;
	double step = 20;
	double fahr = lower;
	printf("fahr celsius\n\n");
	while (fahr <= upper){
		double celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr += step;
	}
	return 0;
}
		
