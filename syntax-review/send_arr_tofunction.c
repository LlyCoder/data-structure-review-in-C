# include <stdio.h>

double get_avg(int arr[],  int size);

int main () {
	double avg;
	
	int arr[5] = {1, 2, 3, 5, 6};
	avg = get_avg(arr, 5);
	printf("平均值为： %f\n", avg);
	
	return 0;
}

double get_avg(int arr[], int size) {
	int i;
	double sum = 0;
	double avg;
	for (i=0; i<size; i++) {
		sum += arr[i];
	}
	avg = sum/size;
	
	return avg;
}