# include <stdio.h> 

const int MAX = 3;

int main () {
	int arr[3] = {1, 2, 3};
	int i, *pointer;
	pointer = arr;
	
	for (i=0; i< MAX; i++) {		
		printf("arr[%d]�ĵ�ַΪ��%x\n", i, pointer);
		printf("arr[%d]��ֵΪ�� %d\n", i, *pointer);
		pointer++;
	}
		
	return 0;
}

/*
arr[0]�ĵ�ַΪ��60ff20
arr[0]��ֵΪ�� 1
arr[1]�ĵ�ַΪ��60ff24
arr[1]��ֵΪ�� 2
arr[2]�ĵ�ַΪ��60ff28
arr[2]��ֵΪ�� 3

��Ϊ int���ĸ��ֽ� �� ÿ��ָ�������������Ų 4 ���ֽڡ� 

*/