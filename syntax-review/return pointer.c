# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int * get_random() {
	//C���Բ�֧�ַ��ؾֲ������ĵ�ַ�����Ǳ���������Ϊstatic��̬����
	int static r[10];
	int i;
	 for (i=0; i<10; i++) {
 		r[i] = rand();
 		printf("r[%d] = %d\n", i, r[i]);
 	}
 	//���ص���ʵ�������׵�ַ��ָ�룩 
 	return r;
} 

int main() {
	int *p = &get_random();
	int i;
	for ()
	
	return 0;
}