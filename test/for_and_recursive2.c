# include <stdio.h>

void printN(int maxN);

int main() {
	int maxN;
	scanf("%d", &maxN);
	printN(maxN);
	
	return 0; 
}

void printN(int maxN) {
	if (maxN) {
		printN(maxN - 1);
		printf("%d\n", maxN);	
	}
	
	return;
}

/*
when the input number is too large the program  will cause interruption. because recursive function need much
memory to save last state 
*/