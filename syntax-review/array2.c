# include <stdio.h>

int main() {
	int i,j;
	int n[10];
	for (i=0; i<10; i++) {
		n[i] = i + 100;
	}
	for (j=0; j<10; j++) {
		printf("第%d个数是%d\n",j+1, n[j]);
	}
	
	return 0;
}