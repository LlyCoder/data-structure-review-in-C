# include <stdio.h>

int main() {
	char strArr[] = "hello";
	int i =0;
	//注意：这里是单引号 
	while(strArr[i] != '\0') {
		printf("%c", strArr[i]);
		i++;
	}
	
	
	return 0;
}