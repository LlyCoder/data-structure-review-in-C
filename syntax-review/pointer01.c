# include <stdio.h> 

int main() {
	//ʹ�� & ȡ�ñ������ڵ��ڴ��ַ
	int var;
	int test_arr[12]; //δ��ʼ�����������ָ�����鳤��
	printf("var������ַ%p  test_arr���׵�ַ��%p\n", &var, test_arr);// ���������������׵�ַ�����Բ��ü�& 
	
	
	//��ʼ��ָ�벢����ָ����ָ�������ֵ 
	float pi = 3.14;
	float *pointer = &pi; //�൱�� float *pointer; pointer = $pi; 
	printf("�����ĵ�ַ�� %p  ָ���ֵ�� %p  ָ��ָ��ı���ֵΪ %f\n", &pi, pointer, *pointer); 
	
	
	// ��ָ�룺 ��ָ��û��ȷ�е�ֵ���Ը��ڣ� Ӧ��Ϊָ�������ֵNULL��NULL ָ����һ�������ڱ�׼���е�ֵΪ��ĳ���
	int *demo = NULL;
	printf("����ֵNULL��ָ���ֵ�ǣ�%p\n", demo); //����ֵNULL��ָ���ֵ�ǣ�00000000
	
		
	return 0;
} 
/*
var������ַ0060FF2C  test_arr���׵�ַ��0060FEF0
�����ĵ�ַ�� 0060FEEC  ָ���ֵ�� 0060FEEC  ָ��ָ��ı���ֵΪ 3.140000
����ֵNULL��ָ���ֵ�ǣ�00000000
*/