# include <stdio.h> 

const int MAX = 3;

int main () {
	int arr[3] = {1, 2, 3};
	int i, *pointer;
	pointer = arr;
	
	for (i=0; i< MAX; i++) {		
		printf("arr[%d]的地址为：%x\n", i, pointer);
		printf("arr[%d]的值为： %d\n", i, *pointer);
		pointer++;
	}
		
	return 0;
}

/*
arr[0]的地址为：60ff20
arr[0]的值为： 1
arr[1]的地址为：60ff24
arr[1]的值为： 2
arr[2]的地址为：60ff28
arr[2]的值为： 3

因为 int是四个字节 ， 每次指针自增就是向后挪 4 个字节。 

*/