# include <stdio.h>

void printN(int maxN);

int main() {
	int maxN;
	scanf("%d", &maxN);
	printN(maxN);
	
	return 0; 
}

void printN(int maxN) {
	int i;
	for (i=1; i<=maxN; i++) {
		printf("%d\n", i); 
	}
	
	return;
}