# include <stdio.h>
# include <float.h>

int main() {
	//ʹ��sizeof�鿴�������ͻ������ռ���ֽڴ�С
	printf("float��ռ��СΪ��%lu\n", sizeof(float)); 
	printf("float���ֵΪ��%e\n", FLT_MAX);
	printf("float��СֵΪ��%e\n", FLT_MIN);
	printf("float����ֵΪ�� %d\n", FLT_DIG);
	
	return 0;
}

/*

float��ռ��СΪ��4
float���ֵΪ��3.402823e+038
float��СֵΪ��1.175494e-038
float����ֵΪ�� 6

*/