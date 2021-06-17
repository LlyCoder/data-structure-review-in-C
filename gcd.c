//greatest common divisor(gcd) by Euclidean Algorithm

#include <stdio.h>

int main() {
	
	int output = gcd(12, 32);
	printf("%d\n", output);
	
	return 0;
}

int gcd(int a,int b) {
	if(b == 0) return a;
	return gcd(b, a % b); 
}