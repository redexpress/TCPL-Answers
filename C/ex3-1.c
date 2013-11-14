#include <stdio.h>

int binsearch(int x, int v[], int n){

	int mid;
	int low = 0;
	int high = n - 1;
	while (low < high) {
		mid = (low + high) / 2;
		if (x <= v[mid]){
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	return (x == v[low]) ? low : -1;
}

int main(){
	int data[] = {1, 1, 2, 3, 5, 8, 13, 21};
	printf("%d\n", binsearch(5, data, sizeof(data)/sizeof(int)));
	return 0;
}