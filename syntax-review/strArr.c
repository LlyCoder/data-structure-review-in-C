# include <stdio.h>

int main() {
	char strArr[] = "hello";
	int i =0;
	//ע�⣺�����ǵ����� 
	while(strArr[i] != '\0') {
		printf("%c", strArr[i]);
		i++;
	}
	
	
	return 0;
}