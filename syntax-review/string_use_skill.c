# include <stdio.h>

int main() {
	
	//��C�����У������ַ��������������ַ���ĩβ׷�� '\0' Ϊ�ַ���������־ 
	char str[] = "Lly"; //����Ԫ��Ϊ  'L' 'l'  'y' '\0'
	int i = 0;
	while (str[i] != '\0') {
		printf("%c \n", str[i]);
		i++;
	}
	
	return 0;
}
/*

L
l
y

*/