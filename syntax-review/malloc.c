#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	//һ�������һֱ�ڴ��С��ֱ��������ȡ
	char name[100];
	strcpy(name, "lly");
	printf("name: %s\n", name);
	
	//δ֪��С��Ҫ��̬�ڴ����
	char *p;
	//char *��ʾ�����������Ŀռ���char�����ʹ洢����1���ֽڵ���һ���ַ��� 
	//malloc() ֻ����һ����������������� �ֽ� �ռ� 
	p = (char *)malloc(30 * sizeof(char));
	if(p == NULL) {
		printf("�����ڴ�ռ�ʧ�ܣ�\n");
	} else {
		strcpy(p, "����Ŀռ��Ƕ�̬��������");
		printf("%s\n", p);
	}
	//��̬����Ŀռ�Ҫ�ֶ��ͷŵ��������ڴ�й©
	free(p); 
	
	return 0; 
}