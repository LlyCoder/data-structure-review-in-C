# include <stdio.h>
# include <string.h>


int main() {
	//C������û���ַ������ͣ�C��������'\0'Ϊ��ֹԪ�ص�һά�ַ���������ʾ�ַ���;
	//��������ı����� char str1[20] = {'a', 'b', 'c', '\0'}; 
	char str1[20] = "abc";  //���ü� '/0' �����������Զ�������ĩβ׷�� '\0' 
	//����һά�ַ����鶨���ַ��� 
	char str2[20] = {'l', 'y', '\0'};
	
	char str3[20];
	
	
	printf("%s\n", str1); // abc
	printf("%s\n", str2); // ly
	
	//һЩ�ַ�����������
	//strcpy(a, b); ��b�����ݸ��Ƹ�a 
	strcpy(str3, str1);
	//strcat(a, b);  ��b���������ӵ�a��
	strcat(str1, str2); 
	
 	printf("strcpy( str3, str1) :  %s\n", str3 ); //strcpy( str3, str1) :  abc
 	printf("strcat( str1, str2):   %s\n", str1 ); // strcat( str1, str2):   abcly
 	
 	//strlen(str) �����ַ������� ��Ԫ�ظ�����������'\0'�� 
	 
	return 0; 
}