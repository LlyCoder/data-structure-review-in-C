# include <stdio.h>

//�������ṹ������ 
struct person {
	//����������Ժ���� ; �ֺ� 
	int id;
	char name[20];
	char sex;	
}; //����һ��Ҫ�ӷֺţ����� 

int main() {
	//�ڴ����ṹ����������ö��󷽷���ֵ  
	struct person student1 = {101, "������", 'M'};
	//������������һ��ֵ 
	struct person student2;
	student2.id = 102;
	student2.name[20] = "��Ӣ��";
	student2.sex = 'W';
	printf("%d %s %c\n",student1.id, student1.name, student1.sex); 
 	printf("%d %s %c\n",student2.id, student2.name, student2.sex);
 	
	return 0;
}
