#include <stdio.h>

int ftoc(int fahr){
	return (5.0/9.0) * (fahr-32.0);
}

int main(){
	double lower = 0;
	double upper = 300;
	double step = 20;
	double fahr = lower;
	printf("fahr celsius\n");
	while (fahr <= upper){
		double celsius = ftoc(fahr);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr += step;
	}
	return 0;
}
		
